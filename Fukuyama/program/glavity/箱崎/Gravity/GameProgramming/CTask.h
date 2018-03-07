#include"math.h"
#include"stdio.h"
class Task{
public:
	bool    m_kill;       
	virtual void    Update()    
	{ printf("a"); }
};
class Player :public Task{
     void Update(){
		printf("player");
	}
};
class Enemy :public Task{
	void Update(){
		printf("Enemy");
	}
};