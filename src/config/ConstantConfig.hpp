/*
 * @Author: haoliwei
 * @Date: 2019-06-23 20:42:35
 * @Last Modified by: haoliwei
 * @Last Modified time: 2019-06-23 20:57:18
 */
#ifndef ConstantConfighpp
#define ConstantConfighpp

#include <glm/glm.hpp>
#include "Camera.hpp"

// extern int WINDOW_HEIGHT;
// extern int WINDOW_WIEGHT;
// extern char *WINDOW_NAME;

static const int WINDOW_HEIGHT = 600;
static const int WINDOW_WIEGHT = 800;
static const int SCR_HEIGHT = 600;
static const int SCR_WIDTH = 800;
static const char *WINDOW_NAME = "LearnOpenGL";


// camera
static Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
static float lastX = SCR_WIDTH / 2.0f;
static float lastY = SCR_HEIGHT / 2.0f;
static bool firstMouse = true;

// timing
static float deltaTime = 0.0f;	// time between current frame and last frame
static float lastFrame = 0.0f;

static const char *VERTEX_SHADER_SOURCE =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

static const char *FRAGMENT_SHADER_SOURCE =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

static const char *FRAGMENT_SHADER_SOURCE_YELLOW =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\n\0";

static const char *VERTEX_SHADER_SOURCE_CHANGE =
    "#version 330 core\n"
    // 位置变量的属性位置值为0
    "layout (location = 0) in vec3 aPos;\n"
    // 为片段着色器指定一个颜色输出
    "out vec4 vertexColor;\n"
    "void main()\n"
    "{\n"
    // 注意我们如何把一个vec3作为vec4的构造器的参数(gl_Position =
    // vec4(aPos, 1.0);)
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    // 把输出变量设置为暗红色
    "   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
    "}\n\0";

static const char *FRAGMENT_SHADER_SOURCE_CHANGE =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    // 从顶点着色器传来的输入变量（名称相同、类型相同）
    "in vec4 vertexColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vertexColor;\n"
    "}\n\0";
#endif /* ConstantConfighpp */
