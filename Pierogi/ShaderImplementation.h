#pragma once
#include "pch.h"

namespace pr {
	class ShaderImplementation {
	public:
		virtual void Bind() = 0;

		virtual void setUniform2Ints(const std::string& uniformName, int val1, int val2) = 0;
		virtual void setUniform2Ints(std::string&& uniformName, int val1, int val2) = 0;

		~ShaderImplementation() {};
	};
}
