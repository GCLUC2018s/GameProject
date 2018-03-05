#pragma once


#include "GL.h"

class CShader {
private:
	GLuint vertexShader;
	GLuint flagShader;

	GLuint program;
	GLint compiled;
	GLint linked;
	
	bool readFile(GLuint program,GLuint shader, const char *file);
public:
	CShader();
	CShader(const char* vertexPath,const char*  flagPath);
	~CShader();
	bool load(const char* vertexPath,const char*  flagPath);
	bool load(const char* path,GLuint type);
	void enable();
	void disable();
	GLuint GetProgram() {
		return program;
	}


};