/*
 * @Description: Keyboard Utils
 * @Author: haoliwei
 * @Date: 2019-06-22 17:53:27
 * @LastEditTime: 2019-07-07 00:01:43
 * @LastEditors: Please set LastEditors
 */

#include "KeyboardUtils.hpp"

/**
 *  对用户输入的键位进行监听
 */
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        std::cout << "user press up" << std::endl;
    }
}
