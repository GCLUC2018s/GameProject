#ifndef DEBUG_SCENE_GUARD
#define DEBUG_SCENE_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

/*

êßçÏé“Å@ã{˙±

*/
class CDebugScene : public CObjectBase
{
public:
	//DebugópScene
	CDebugScene();
	~CDebugScene();
	void Update();
	void Draw();
private:
	int m_scene_num;
	CFont	m_font;
};
#endif // !DEBUG_SCENE_GUARD
