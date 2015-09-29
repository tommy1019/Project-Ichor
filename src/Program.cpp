#include "Program.h"

Program::Program(Shader vs, Shader fs)
{
    programPtr = glCreateProgram();

    glAttachShader(programPtr, vs.shaderPtr);
    glAttachShader(programPtr, fs.shaderPtr);

    glLinkProgram(programPtr);

    GLint programSuccess = GL_FALSE;
    glGetProgramiv(programPtr, GL_LINK_STATUS, &programSuccess);
    if (programSuccess != GL_TRUE)
    {
        printf("Error linking program:\n");
        printProgramLog();
        throw 1;
    }
}

void Program::printProgramLog()
{
    int infoLogLength = 0;
    int maxLength = 0;

    glGetProgramiv(programPtr, GL_INFO_LOG_LENGTH, &maxLength);

    char* infoLog = new char[maxLength];
    glGetProgramInfoLog(programPtr, maxLength, &infoLogLength, infoLog);

    if (infoLogLength > 0)
    {
        printf("%s\n", infoLog);
    }

    delete infoLog;
}
