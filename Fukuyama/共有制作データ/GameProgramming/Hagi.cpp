#include"Hagi.h"

void Hagi::Update(){
}

void Hagi::Draw(){
	Icon.DrawImage(-585, -495, -435, -345, 0, 90, 90, 0);
	i_iconShadow.Render(0.0f, 0.0f, 0.0f, 0.5f);
}