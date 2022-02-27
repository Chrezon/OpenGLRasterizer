#ifndef OPENGLPLAYGROUND_GLSHADER_H
#define OPENGLPLAYGROUND_GLSHADER_H

#include <glad/glad.h>
#include <string>

// Function courtesy of: https://badvertex.com/2012/11/20/how-to-load-a-glsl-shader-in-opengl-using-c.html
char* readFile(const char *filePath);

class Shader {
public:
    GLuint ID;

    // Constructor
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    // Auto delete program
    ~Shader();
};


#endif //OPENGLPLAYGROUND_GLSHADER_H
