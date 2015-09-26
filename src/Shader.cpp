#include "Shader.h"

Shader::Shader(std::string fileName, GLuint shaderType)
{
    std::ifstream file;
    file.open(std::string("res/shaders/").append(fileName));

    if(!file)
    {
        printf("Unable to open shader file: %s\n", std::string("res/shaders/").append(fileName).c_str());
        throw 1;
    }

    std::string shaderContents;
    shaderContents.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    file.close();

    shaderPtr = glCreateShader(shaderType);
    
    const GLchar* shaderSource = shaderContents.c_str();
    glShaderSource(shaderPtr, 1, &shaderSource, NULL);

    glCompileShader(shaderPtr);

    GLint shaderCompiled = GL_FALSE;
    glGetShaderiv(shaderPtr, GL_COMPILE_STATUS, &shaderCompiled);
    if (shaderCompiled != GL_TRUE)
    {
        printf("Unable to compile shader: %s\n", fileName.c_str());
        printShaderLog(shaderPtr);
        glDeleteShader(shaderPtr);
        shaderPtr = 0;
        throw 1;
    }
}

void Shader::printShaderLog(GLuint shaderPtr)
{
    int infoLogLength = 0;
    int maxLength = 0;

    glGetShaderiv(shaderPtr, GL_INFO_LOG_LENGTH, &maxLength);

    char* infoLog = new char[maxLength];
    
    glGetShaderInfoLog(shaderPtr, maxLength, &infoLogLength, infoLog);
    if (infoLogLength > 0)
    {
        printf("%s", infoLog);
    }

    delete infoLog;
}
