#pragma once
#pragma once
/**
* @file		AsSet.h
* @brief	���\�[�X�Ǘ��N���X
*
* @author	shinya nagakawa
*/


#include <map>
#include <vector>

class CResource {
	std::string m_name;
public:
	CResource():m_name(""){}
	/**
	* @fn
	* �R���X�g���N
	* @brief �R���X�g���N�^
	* @param name [in]�@���O
	*/
	CResource(std::string name) :m_name(name){}
	/**
	* @fn
	* �f�X�g���N�^
	* @brief �f�X�g���N�^
	*/
	virtual ~CResource() {};
	/**
	* @fn
	* ���O�̎擾
	* @brief ���O�̎擾
	* @return ���O
	*/
	std::string GetName() const {
		return m_name;
	}
	/**
	* @fn
	* ���\�[�X�J������
	* @brief ���\�[�X�J������
	*/
	virtual void Release() {};
	friend class CResourceManager;

};
class CResourceManager {
private:
	std::map<int,std::map<std::string, CResource*>> m_list;
	static CResourceManager*	m_instance;
public:
	static CResourceManager* GetInstance() {
		if (!m_instance) m_instance = new CResourceManager;
		return m_instance;
	}
	/**
	* @fn�@���\�[�X��S�Ĕj������
	* @brief ���\�[�X��S�Ĕj������
	*/
	static void ClearInstance() {
		if (!m_instance) return;
		delete m_instance;
		m_instance = nullptr;
	}
	CResourceManager();
	~CResourceManager();
	/**
	* @fn
	* ���\�[�X�̒ǉ�
	* @brief ���\�[�X�̒ǉ�
	*/
	void Add(CResource* res,int group=0);
	void Add(std::string name, CResource* res,int group=0);
	/**
	* @fn
	* ���\�[�X�̎擾
	* @brief ���\�[�X�̂̎擾
	* @param name [in]�@���\�[�X�̖��O
	* @return ���\�[�X
	*/
	CResource* Get(std::string name, int group = 0);
	/**
	* @fn
	* ���\�[�X�̍폜
	* @brief ���\�[�X�̂̍폜
	* @param name [in]�@���\�[�X�̖��O
	*/
	void Delete(std::string name, int group = 0);
	/**
	* @fn
	* ���\�[�X�̍폜
	* @brief ���\�[�X�̂̍폜
	* @param name [in]�@���\�[�X�O���[�v
	*/
	void Delete(int group = 0);

};