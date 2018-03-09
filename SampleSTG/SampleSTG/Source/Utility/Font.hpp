/*!
	@brief	������`��N���X hpp
	@author	s.namizashi
**/

#ifndef __FONT_HPP__
#define __FONT_HPP__

class clFont
{
	private:
		enum
		{
			FONT_BUFFER_SIZE	= 512,	// ��x��Print�Őݒ�o���镶����
		};

		// �t�H���g�`����
		struct stDrawInfo
		{
			char		str[FONT_BUFFER_SIZE];
			VECTOR2I	pos;
			DWORD		color;
			stDrawInfo()
			{
				ZeroMemory(str,sizeof(str));
				pos = VECTOR2I(0,0);
				color = 0xffffffff;
			}
		};

		// �t�H���g�`���񃊃X�g�̃f�[�^�^
		typedef	std::vector<stDrawInfo> DRAWLIST;

		DRAWLIST	m_DrawList;		//!< �t�H���g�`���񃊃X�g
		std::string	m_fName;		//!< �t�H���g��
		int			m_fHundle;		//!< �t�H���g�n���h��
		int			m_fSize;		//!< �t�H���g�T�C�Y
		int			m_fThick;		//!< �t�H���g�̑���
		int			m_fType;		//!< �t�H���g�^�C�v
		DWORD		m_fColor;		//!< �t�H���g�J���[
		bool		m_IsShadow;		//!< �e�̗L��(true�Ȃ�΁A�e�L��)
		bool		m_IsChange;		//!< �t�H���g�ύX���邩�ǂ���
		bool		m_IsCenter;

		/*!
			@brief	�ǂݍ���ł���t�H���g���
		**/
		void Release();

		/*!
			@brief	�t�H���g�쐬
		**/
		void Create();
	public:
		// �t�H���g�^�C�v
		enum enFontType
		{
			FTYPE_NONE = -1,

			FTYPE_DEFAULT,					// �f�t�H���g�t�H���g
			FTYPE_NORMAL,					// �m�[�}���t�H���g
			FTYPE_EDGE,						// �G�b�W���t�H���g
			FTYPE_ANTIALIASING,				// �A���`�G�C���A�X�t�H���g( �W���@�\�A���`�G�C���A�X )
			FTYPE_ANTIALIASING_4X4,			// �A���`�G�C���A�X�t�H���g( 4x4�T���v�����O )
			FTYPE_ANTIALIASING_8X8,			// �A���`�G�C���A�X�t�H���g( 8x8�T���v�����O )
			FTYPE_ANTIALIASING_EDGE,		// �A���`�G�C���A�X���G�b�W�t���t�H���g( �W���@�\�A���`�G�C���A�X )
			FTYPE_ANTIALIASING_EDGE_4X4,	// �A���`�G�C���A�X���G�b�W�t���t�H���g( 4x4�T���v�����O )
			FTYPE_ANTIALIASING_EDGE_8X8,	// �A���`�G�C���A�X���G�b�W�t���t�H���g( 8x8�T���v�����O )

			FTYPE_COUNT
		};

		/// �R���X�g���N�^
		clFont();
		/// �f�X�g���N�^
		~clFont();

		/*!
			@brief	����������
		**/
		void Init();

		void SetCenter( bool flag ) { m_IsCenter = flag; }

		/*!
			@brief	�t�H���g���ݒ�
			@param[in]	name	�ݒ肷��t�H���g��
		**/
		void SetName( const char* fName );

		/*!
			@brief	�t�H���g�T�C�Y�ݒ�(-1:�f�t�H���g)
			@param[in]	size	�ݒ肷��t�H���g�T�C�Y
		**/
		void SetSize( int size );

		/*!
			@brief	�t�H���g�̑����ݒ�(0~9,-1:�f�t�H���g)
			@param[in]	thick	�ݒ肷��t�H���g�̑���
		**/
		void SetThick( int thick );

		/*!
			@brief	�t�H���g�^�C�v�ݒ�
			@param[in]	type	�ݒ肷��t�H���g�^�C�v
		**/
		void SetType( enFontType type );

		/*!
			@brief	�t�H���g�J���[�ݒ�
			@param[in]	color	�ݒ肷��t�H���g�J���[
		**/
		void SetColor( DWORD color );

		/*!
			@brief	�e�̗L���ݒ�
			@param[in]	flag	�e�̗L��(true�Ȃ�΁A�e�L��)
		**/
		void SetShadow( bool flag );

		/*!
			@brief	�`�敶����ݒ�(printf��)
			@param[in]	pos		�`��ʒu
			@param[in]	format	������̃t�H�[�}�b�g
			@param[in]	...		������
		**/
		void Print( VECTOR2I pos, const char* format, ... );

		/*!
			@brief	�f�o�b�O������`��p
			@param[in]	pos		�`��ʒu
			@param[in]	format	������̃t�H�[�}�b�g
			@param[in]	...		������
		**/
		static void DebugPrint( VECTOR2I pos, const char* fotmat, ... );

		/*!
			@brief	�X�V����
		**/
		void Update();

		/*!
			@brief	�`�揈��
		**/
		void Draw();
};

#endif	// #ifndef __FONT_HPP__