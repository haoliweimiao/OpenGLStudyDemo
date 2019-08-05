/*
 * @Description: draw base utils
 * @Author: your name
 * @Date: 2019-06-24 23:41:01
 * @LastEditTime: 2019-06-29 20:59:27
 * @LastEditors: Please set LastEditors
 */

#include "OpenGLInitUtils.hpp"

void initOpenGL() {
  //初始化GLFW
  glfwInit();
  //指定版本3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// mac系统需要添加此项
#ifdef __APPLE__
  glfwWindowHint(
      GLFW_OPENGL_FORWARD_COMPAT,
      GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
}