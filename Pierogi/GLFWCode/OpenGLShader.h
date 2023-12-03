#pragma once

#include "pch.h"

#include "ShaderImplementation.h"

namespace pr {
	class OpenGLShader : public ShaderImplementation {
	public:
		OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF);
		OpenGLShader(std::string&& vertexSF, std::string&& fragmentSF);


		virtual void setUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void setUniform2Ints(std::string&& uniformName, int val1, int val2) override;


		void Bind() override;

		~OpenGLShader();

	private:
		std::string ReadWholeFile(const std::string& filename);
		std::string ReadWholeFile(std::string&& filename);
		
		unsigned int mShaderProgram;
	};
}
