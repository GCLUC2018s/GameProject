#include "ImageResource.h"

CImage g_image[eImageMax];


static TexAnim playerIdle[] = {
	{ 0,32 },
	{ 1,16 },
	{ 2,16 },
	{ 1,16 },
};

TexAnimData playerAnimData[] = {
	ANIMDATA(playerIdle),
};
