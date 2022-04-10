#include "Renderer.h"

#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << " )" << function << " " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	
	


	/*����vao�Ժ󣬿��Բ�������������Щ*/
	shader.Bind();
	/*GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	ֻ��Ҫ��vao��ibo
	GLCall(glBindVertexArray(vao));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));*/
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
