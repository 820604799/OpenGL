#pragma once

#include "GL/glew.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x/* 把函数名当做字符串返回 */, __FILE__, __LINE__))

void GLClearError();


bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
	public:
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)const;
		void Clear() const;

		

};