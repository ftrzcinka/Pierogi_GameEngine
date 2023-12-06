#pragma once

#include "Utilities.h"
#include "pch.h"
#include "ShaderImplementation.h"

namespace pr {
	class PIEROGI_API Shader {
	public:
		Shader(const std::string& vertexSFile, const std::string& fragmentSFile);
		void Bind();
		void setUniform2Ints(const std::string& uniformName, int val1, int val2);
		void setUniform2Ints(std::string&& uniformName, int val1, int val2);
	private:
		std::unique_ptr<ShaderImplementation> mImplementation;
	};
}
