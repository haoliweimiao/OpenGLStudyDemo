/*
 * @Description: FramebufferSizeCallbackImpl
 * @Author: haoliwei
 * @Date: 2019-06-24 22:53:26
 * @LastEditTime: 2019-08-04 22:38:05
 * @LastEditors: Please set LastEditors
 */
#include "FramebufferSizeCallbackImpl.hpp"

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
  std::cout << "width: " << width << "height: " << height << std::endl;
  glViewport(0, 0, width, height);
}