#pragma once

#include <glm/glm.hpp>

class Vertex
{
private:
	glm::vec3 m_pos;
public:
	Vertex(const glm::vec3& pos);
	~Vertex();
};

