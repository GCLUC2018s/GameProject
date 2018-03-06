#include "CMatrix33.h"
void CMatrix33::firstcount(){
	for (int i = 0; i < 3; i++){
		m[i][i] = 1;
	}
}