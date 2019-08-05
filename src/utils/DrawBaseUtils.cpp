/*
 * @Description: draw base utils
 * @Author: your name
 * @Date: 2019-06-24 23:41:01
 * @LastEditTime: 2019-06-29 17:18:31
 * @LastEditors: Please set LastEditors
 */

#include "DrawBaseUtils.hpp"

unsigned int initVAO() {
    unsigned int VBO;
    //顶点缓冲对象是我们在OpenGL教程中第一个出现的OpenGL对象。就像OpenGL中的其它对象一样，这个缓冲有一个独一无二的ID，
    //所以我们可以使用glGenBuffers函数和一个缓冲ID生成一个VBO对象：
    glGenBuffers(1, &VBO);

    // OpenGL有很多缓冲对象类型，顶点缓冲对象的缓冲类型是GL_ARRAY_BUFFER。
    // OpenGL允许我们同时绑定多个缓冲，只要它们是不同的缓冲类型。
    //我们可以使用glBindBuffer函数把新创建的缓冲绑定到GL_ARRAY_BUFFER目标上：
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    return VBO;
}

void initVBO(unsigned int &address) {}

void initEBO(unsigned int &address) {}