/*!
	@brief	�摜�`��N���X hpp
	@author	s.namizashi
**/

#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

class clImage
{
	private:
		VECTOR2F	m_Pos;			//!< �`��ʒu
		UVI			m_UV;			//!< UV�l
		VECTOR2F	m_Center;		//!< ���S�_�ʒu
		VECTOR2F	m_Scale;		//!< �X�P�[���l
		COLOR4I		m_Color;		//!< �J���[
		int			m_iHundle;		//!< �n���h��
		float		m_Angle;		//!< ��]�l
		bool		m_IsTurn;		//!< ���E���]���邩�ǂ���

		/*!
			@brief	�`���񏉊���
		**/
		void InitDrawInfo();
	public:
		/// �R���X�g���N�^
		clImage();
		/// �f�X�g���N�^
		~clImage();

		/*!
			@brief	����������
		**/
		void Init();

		/*!
			@brief	�摜�ǂݍ���
			@param[in]	name	�ǂݍ��މ摜��
		**/
		void Load( const char* name );

		/*!
			@brief	�`��ʒu�ݒ�
			@param[in]	x	X���W�l
			@param[in]	y	Y���W�l
		**/
		void SetPos( float x, float y );

		/*!
			@brief	UV�ݒ�
					�s�N�Z���Ŏw�肷��p(0�`�摜�T�C�Y)
			@param[in]	sx	�J�nX���W
			@param[in]	sy	�J�nY���W
			@param[in]	ex	�I��X���W
			@param[in]	ey	�I��Y���W
		**/
		void SetUV( int sx, int sy, int ex, int ey );

		/*!
			@brief	UV�ݒ�
					�����Ŏw�肷��p(0.0f�`1.0f)
			@param[in]	sx	�J�nX���W����
			@param[in]	sy	�J�nY���W����
			@param[in]	ex	�I��X���W����
			@param[in]	ey	�I��Y���W����
		**/
		void SetUV( float sx, float sy, float ex, float ey );

		UVI GetUV() const;

		/*!
			@brief	���S�_�ݒ�(�^�C�v�w��p)
			@param[in]	type	�ݒ肷�钆�S�_�^�C�v
		**/
		void SetCenter( enDirection type );

		/*!
			@brief	���S�_�ݒ�(�ʒu�w��p)
			@param[in]	x	X���W�ʒu
			@param[in]	y	Y���W�ʒu
		**/
		void SetCenter( int x, int y );

		/*!
			@brief	�X�P�[���l�ݒ�(�ʎw��p)
			@param[in]	x	X���X�P�[���l
			@param[in]	y	Y���X�P�[���l
		**/
		void SetScale( float x, float y );

		/*!
			@brief	�X�P�[���l�ݒ�(���ʎw��p)
			@param[in]	scl	�X�P�[���l
		**/
		void SetScale( float scl );

		/*!
			@brief	�X�P�[���l�擾
			@return	�X�P�[���l
		**/
		VECTOR2F GetScale() const;

		/*!
			@brief	�J���[�ݒ�(COLOR4I�^�p)
			@param[in]	color	�ݒ肷��J���[
		**/
		void SetColor( COLOR4I color );

		/*!
			@brief	��]�l�ݒ�(���W�A���w��p)
			@param[in]	rot	��]��
		**/
		void SetRotate( float rot );

		/*!
			@brief	��]�l�ݒ�(�f�B�O���[�w��p)
			@param[in]	rot	��]�l
		**/
		void SetRotate( int rot );

		/*!
			@brief	���E���]���邩�ǂ�����ݒ�
			@param[in]	is_turn	true�Ȃ�΍��E���]
		**/
		void SetTurn( bool is_turn );

		/*!
			@brief	�ǂݍ���ł���摜���
		**/
		void Release();

		/*!
			@brief	�X�V����
		**/
		void Update();

		/*!
			@brief	�`�揈��
		**/
		void Draw();
};

#endif	// #ifndef __IMAGE_HPP__