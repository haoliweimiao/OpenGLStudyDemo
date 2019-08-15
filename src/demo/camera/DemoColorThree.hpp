/*
 * @Description: 绘制两个立方体，一个光源，一个为物体。在观察空间（而不是世界空间）中计算冯氏光照：参考解答。
 * @Author: haoliwei
 * @Date: 2019年08月15日20:58:24
 * @LastEditTime: 2019-08-15 20:58:31
 * @LastEditors: Please set LastEditors
 */

#ifndef DemoColorThreehpp
#define DemoColorThreehpp

#include "../../config/ConstantConfig.hpp"
#include "../../glsl/Shader.hpp"
#include "../../implement/FramebufferSizeCallbackImpl.hpp"
#include "../../utils/KeyboardUtils.hpp"
#include "../../utils/OpenGLInitUtils.hpp"
#include "../../utils/ThreadSleepUtils.hpp"
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <filesystem>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

int demoFunDrawColorThree();

#endif /* DemoColorThreehpp */
