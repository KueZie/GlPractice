#pragma once

#include <GL/glew.h>
#include "Vertex.h"
#include <iostream>

class Mesh
{
private:
	Vertex* m_verticies;
	unsigned int m_num_verticies;
	unsigned int m_draw_count;

	enum
	{
		POSITION_VB,
		NUM_BUFFERS
	};

	GLuint m_vertex_array_object;
	GLuint m_vertex_array_buffers[NUM_BUFFERS];
public:
	Mesh(Vertex* verticies, unsigned int num_verticies);
	void Draw();
	~Mesh();
};

