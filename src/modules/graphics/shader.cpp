#include "shader.hpp"

mocha::graphics::Shader::Shader(const char *vertex_path, const char *fragment_path)
{
    // 1. retrieve source code from filePath
    std::string vertex_code;
    std::string fragment_code;
    std::ifstream v_shader_file;
    std::ifstream f_shader_file;

    try
    {
        v_shader_file.open(vertex_path);
        f_shader_file.open(fragment_path);
        std::stringstream v_shader_stream, f_shader_stream;

        v_shader_stream << v_shader_file.rdbuf();
        f_shader_stream << f_shader_file.rdbuf();

        v_shader_file.close();
        f_shader_file.close();

        vertex_code = v_shader_stream.str();
        fragment_code = f_shader_stream.str();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    const char* v_shader_code = vertex_code.c_str();
    const char* f_shader_code = fragment_code.c_str();

    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &v_shader_code, NULL);
    glCompileShader(vertex);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &f_shader_code, NULL);
    glCompileShader(fragment);

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void mocha::graphics::Shader::use()
{
    glUseProgram(id);
}

void mocha::graphics::Shader::setBool(const char *name, bool value)
{
    glUniform1i(glGetUniformLocation(id, name), (int)value);
}

void mocha::graphics::Shader::setInt(const char *name, int value)
{
    glUniform1i(glGetUniformLocation(id, name), value);
}

void mocha::graphics::Shader::setFload(const char *name, float value)
{
    glUniform1f(glGetUniformLocation(id, name), value);
}
