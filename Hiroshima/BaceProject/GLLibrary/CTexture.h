#pragma once

#include "GL.h"
#include "CResource.h"

class CTexture : public CResource{
public:
	unsigned char *m_data;
	int	m_width;
	int m_height;
	int m_internalFormat;
	int m_format;
	unsigned int m_imgSize;
	int m_type;

	unsigned int m_bufID;
	bool loadBmp(char *path);
	bool loadPng(char *path);
public:
	CTexture();
	~CTexture();
	static CTexture* LoadTexture(char *path);
	bool Load(char *path);
	void MapTexture();
	void UnmapTexture();
	void Release();

	void SetWrapST(int wrapst);
	void SetFilter(int filter);

	
	void Draw();
};