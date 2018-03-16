#include "../GameProject/Source/Fieldsource.h"

CFieldManager::CFieldManager() :CObjectBase(0, eU_System, eD_Null)
{
	new CFieldSky();
	new CFieldCloud(0);
	new CFieldBamboo(0);
	new CFieldGround(0);
	new CFieldGround(1);
}

CFieldManager::~CFieldManager()
{
}

void CFieldManager::Update()
{
}
