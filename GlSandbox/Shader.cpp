#include "Shader.h"


Shader::Shader(const std::string& fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".glvs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".glfs"), GL_FRAGMENT_SHADER);

	for (GLuint i = 0; i < 2; i++)
		glAttachShader(m_program, m_shaders[i]);

	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error linking program");

	/*glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Invalid program");*/
}

Shader::~Shader()
{
	for (GLuint i = 0; i < 2; ++i)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}

void Shader::Bind()
{
	glUseProgram(m_program);
}

std::string Shader::LoadShader(const std::string& fileName)
{
	std::ifstream file_stream;
	file_stream.open(fileName);

	std::string line, out;

	if (file_stream.is_open())
		while (std::getline(file_stream, line)) out += line + "\n";
	else
		std::cerr << "Failed to load file.\n";

	return out;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& error_msg)
{
	GLint success;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(m_program, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << error_msg << ": '" << error << "'" << std::endl;
	}
}

GLuint Shader::CreateShader(const std::string& txt, GLuint type)
{
	GLuint shader = glCreateShader(type);
	
	if (shader == 0) std::cerr << "Failed to create shader!\n";
	
	const GLchar* p[1] = { txt.c_str() };
	GLint l[1] = { txt.length() };
	
	glShaderSource(shader, (GLsizei)1, (GLchar**)p, 0);
	glCompileShader(shader);

	return shader;
}