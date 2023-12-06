#include "pch.h"
#include "Utilities.h"
#include "OpenGLShader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace pr {
	OpenGLShader::OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF)
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			PR_ERROR("Failed to Initialize GLAD");
			return;
		}
		
		std::string vertexString = ReadWholeFile(vertexSF);
		const char* vertexShaderSource = vertexString.c_str();

		std::string fragString = ReadWholeFile(fragmentSF);
		const char* fragmentShaderSource = fragString.c_str();

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int sucess;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &sucess);

		if (!sucess) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			PR_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &sucess);
		if (!sucess) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			PR_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glGetShaderiv(mShaderProgram, GL_COMPILE_STATUS, &sucess);
		if (!sucess) {
			glGetShaderInfoLog(mShaderProgram, 512, NULL, infoLog);
			PR_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	OpenGLShader::OpenGLShader(std::string&& vertexSF, std::string&& fragmentSF)
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			PR_ERROR("Failed to Initialize GLAD");
			return;
		}
		
		std::string vertexString = ReadWholeFile(move(vertexSF));
		const char* vertexShaderSource = vertexString.c_str();

		std::string fragString = ReadWholeFile(move(fragmentSF));
		const char* fragmentShaderSource = fragString.c_str();

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int sucess;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &sucess);

		if (!sucess) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			PR_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &sucess);
		if (!sucess) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			PR_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glGetShaderiv(mShaderProgram, GL_COMPILE_STATUS, &sucess);
		if (!sucess) {
			glGetShaderInfoLog(mShaderProgram, 512, NULL, infoLog);
			PR_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	void OpenGLShader::setUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProgram);
		GLint location{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(location, val1, val2);
	}
	void OpenGLShader::setUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProgram);
		GLint location{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(location, val1, val2);
	}
	void OpenGLShader::Bind()
	{
		glUseProgram(mShaderProgram);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(mShaderProgram);
	}
	std::string OpenGLShader::ReadWholeFile(const std::string& filename)
	{
		std::ifstream inputFile{ filename };

		std::string result;
		std::string nextLine;

		while (inputFile) {
			std::getline(inputFile, nextLine);
			if (!inputFile)
				break;
			result += nextLine + "\n";
		}

		return result;
	}
	std::string OpenGLShader::ReadWholeFile(std::string&& filename)
	{
		std::ifstream inputFile{ move(filename) };

		std::string result;
		std::string nextLine;

		while (inputFile) {
			std::getline(inputFile, nextLine);
			if (!inputFile)
				break;
			result += nextLine + "\n";
		}

		return result;
	}
}