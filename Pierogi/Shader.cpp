#include "pch.h"
#include "Shader.h"

#include "GLFWCode/OpenGLShader.h"

namespace pr {
	Shader::Shader(const std::string& vertexSFile, const std::string& fragmentSFile)
	{
		//mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#ifdef PIEROGI_MSCPP
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile)};
#elif PIEROGI_APPLE
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#elif PIEROGI_LINUX
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#endif
	}
	void Shader::Bind()
	{
		mImplementation->Bind();
	}
	void Shader::setUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->setUniform2Ints(uniformName, val1, val2);
	}
	void Shader::setUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		mImplementation->setUniform2Ints(move(uniformName), val1, val2);
	}
}