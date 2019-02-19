#include "Mesh.h"

Mesh::Mesh(Vertex* verticies, unsigned int num_verticies)
{
	m_draw_count = num_verticies;
	m_verticies = verticies;

	glGenVertexArrays(1, &m_vertex_array_object);
	glBindVertexArray(m_vertex_array_object);

	glGenBuffers(1, m_vertex_array_buffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_array_buffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies[0]) * m_num_verticies, verticies, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindVertexArray(0);

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertex_array_object);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertex_array_object);
	std::cout << POSITION_VB << " " << NUM_BUFFERS << std::endl;
	glDrawArrays(1, 0, m_draw_count);

	glBindVertexArray(0);
}
