/*
 * @Description: OpenGL load class
 * @Author: your name
 * @Date: 2019-06-29 16:25:00
 * @LastEditTime: 2019-08-26 07:16:35
 * @LastEditors: Please set LastEditors
 */
#ifndef OpenGLInitUtilshpp
#define OpenGLInitUtilshpp

#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void initOpenGL();

// utility function for loading a 2D texture from file
// ---------------------------------------------------
unsigned int loadTexture(char const *path);

#endif /* OpenGLInitUtilshpp */
