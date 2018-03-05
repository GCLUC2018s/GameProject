#include "CInput.h"


char		CInput::m_key_code[PAD_MAX][CInput::eMax] = { 0 };
char		CInput::m_pad_code[PAD_MAX][16] = {
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
};
unsigned long CInput::m_key_old[PAD_MAX]={0};
unsigned long CInput::m_key_state[PAD_MAX][CInput::eStateMax]={0};
CVector2D CInput::m_mouse_old=CVector2D(0,0);
CVector2D CInput::m_mouse_vec;
int CInput::m_mouse_wheel= 0;
int CInput::m_mouse_wheelOld= 0;
bool CInput::m_mouse_inside = false;
bool CInput::m_mouse_inside_loop = false;
LPDIRECTINPUT8 CInput::m_pDinput=NULL;
CInput::SPadDevice CInput::m_device[PAD_MAX] = { { 0, }, };


//���p�\�ȃW���C�X�e�B�b�N��񋓂���R�[���o�b�N�֐�
bool CALLBACK CInput::_padCallback(const LPDIDEVICEINSTANCE lpddi, LPVOID pvRe)
{

	HDC glDc = wglGetCurrentDC();
	//�E�B���h�E�n���h���擾
	HWND hWnd = WindowFromDC(glDc);

//	HRESULT ret;
	static int d_num = 0;
	SPadDevice* pd = &((SPadDevice*)pvRe)[d_num];
	LPDIRECTINPUTDEVICE8* ppDevice = &pd->m_pPadDevice;
	//�W���C�X�e�B�b�N�p�Ƀf�o�C�X�I�u�W�F�N�g���쐬
	if (m_pDinput->CreateDevice(lpddi->guidInstance, ppDevice, NULL) != DI_OK) 
		return DIENUM_CONTINUE;

	(*ppDevice)->QueryInterface(IID_IDirectInputDevice2, (LPVOID *)&ppDevice);

	pd->no = d_num;
	if (!pd->m_pPadDevice) return DIENUM_CONTINUE;
	// �f�o�C�X���W���C�X�e�B�b�N�ɐݒ�
	if (FAILED(pd->m_pPadDevice->SetDataFormat(&c_dfDIJoystick2))) 	return DIENUM_CONTINUE;
	// �������x���̐ݒ�
	if (FAILED(pd->m_pPadDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))  return DIENUM_CONTINUE;
	// �f�o�C�X���u�擾�v����
	pd->m_pPadDevice->Acquire();
	

	d_num++;
	return (d_num >= PAD_MAX) ? DIENUM_STOP : DIENUM_CONTINUE;
}
bool CInput::Init(){

	// �uDirectInput�v�I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDinput, NULL)))
		return false;
	
	//���p�\�ȃQ�[���R���g���[���[�̗񋓊֐������s
	if (FAILED(m_pDinput->EnumDevices(DI8DEVCLASS_GAMECTRL, (LPDIENUMDEVICESCALLBACK)CInput::_padCallback,&m_device, DIEDFL_ATTACHEDONLY)))
		return false;

	return true;


}

void CInput::UpDate(){
	for(int i=0;i<PAD_MAX;i++) {
		unsigned long key = 0;
		unsigned long state = 0;
		for(int j=0;j<eMax;j++) {
			if(::GetKeyState(m_key_code[i][j]) & 0x80) {
				key |= 1<<j;
			}
		}

		if (m_device[i].m_pPadDevice) {
			DIJOYSTATE2 *js = &m_device[i].js;
			HRESULT hr = m_device[i].m_pPadDevice->Acquire();
			if ((hr == DI_OK) || (hr == S_FALSE))
			{
				m_device[i].m_pPadDevice->GetDeviceState(sizeof(DIJOYSTATE2), js);
				if (js->lY < 0x7E00) key |= 1 << eUp;
				if (js->lY > 0x8100)  key |= 1 << eDown;
				if (js->lX < 0x7E00) key |= 1 << eLeft;
				if (js->lX > 0x8100) key |= 1 << eRight;
				for (int j = 0; j < eUp; j++) {
					if (js->rgbButtons[m_pad_code[i][j]] & 0x80) key |= 1 << j;
				}
			}
		}
		m_key_state[i][ePush] = (~m_key_old[i]) & key;
		m_key_state[i][eHold] = m_key_old[i] & key;
		m_key_state[i][ePull] = m_key_old[i] & (~key);
		m_key_state[i][eFree] = (~m_key_old[i]) & (~key);
		m_key_old[i] = key;
	}
	CVector2D mouse_pos;
	mouse_pos = GetMousePoint();
	m_mouse_vec = mouse_pos -  m_mouse_old;
	if(m_mouse_inside) {
		HDC glDc = wglGetCurrentDC();
		HWND hWnd = WindowFromDC(glDc);
		if (m_mouse_inside_loop) {
			//�J�[�\������ʓ��ɖ߂�
			RECT rect;
			if (GetClientRect(hWnd, &rect)) {
				if (mouse_pos.x > rect.right-16) {
					mouse_pos.x = 16;
				}
				else if (mouse_pos.x < 16) {
					mouse_pos.x = (float)rect.right-16;
				}
				if (mouse_pos.y > rect.bottom-16) {
					mouse_pos.y = 16;
				}
				else if (mouse_pos.y < 16) {
					mouse_pos.y = (float)rect.bottom-16;
				}
				POINT pt = { (LONG)mouse_pos.x, (LONG)mouse_pos.y };
				ClientToScreen(hWnd, &pt);
				SetCursorPos(pt.x, pt.y);
			}
		} else {
			static bool trg = false;
			if (hWnd == GetForegroundWindow()) {
				if(!trg) {
					RECT rect;
					GetWindowRect(hWnd, &rect);
					rect.bottom -= 24; rect.top += 32; rect.left += 16; rect.right -= 24;
					ClipCursor(&rect);
					trg = true;
				}
			} else {
				if (trg) {
					ClipCursor(NULL);
					trg = false;
				}

			}

		}
	}
	m_mouse_old = mouse_pos;
	m_mouse_wheelOld = m_mouse_wheel;
	m_mouse_wheel = 0;
	
}
