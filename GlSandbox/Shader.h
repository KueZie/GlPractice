#pragma once

#include <GL/glew.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader
{
private:
	GLuint m_program;
	GLuint m_shaders[2];
public:
	Shader(const std::string& fileName);
	~Shader();
	void Bind();
	std::string LoadShader(const std::string& fileName);
	GLuint CreateShader(const std::string& txt, GLuint type);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& error_msg);
};

