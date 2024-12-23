#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <glad/glad.h>
#include "Shader.h"

/*
 * Structure defining a vertex, with an x, y, 
 * and z value for a single coordinate.
 */
struct Vertex 
{
	float x;
	float y;
	float z;
};

class Model 
{
public:
	/*
	 * Default constructor for Model.
	 */
	Model();
	
	/*
	 * Initializes and loads vertex data 
	 * into a model object.
	 * 
	 * **Note** Still need to add texture/color loading.
	 *
	 */
	Model(std::vector<Vertex> vertices);

	/*
	 * Draws the current model with a specified 
	 * shader.
	 */
	void draw(const Shader &shader);

private:
	std::vector<Vertex> m_vertices;
	unsigned int m_vbo;
	unsigned int m_vao;
	
};

#endif
