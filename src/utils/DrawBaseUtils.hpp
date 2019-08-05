#ifndef DrawBaseUtilshpp
#define DrawBaseUtilshpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

unsigned int initVAO();
void initVBO(unsigned int &address);
void initEBO(unsigned int &address);

#endif /* DrawBaseUtilshpp */
