/*
 * @Description: draw ten 3d rotating box
 * @Author: haoliwei
 * @Date: 2019-07-20 13:03:49
 * @LastEditTime: 2019-07-27 21:05:20
 * @LastEditors: Please set LastEditors
 */

#ifndef DemoDrawTenBase3DBoxhpp
#define DemoDrawTenBase3DBoxhpp

#include "../../config/ConstantConfig.hpp"
#include "../../glsl/Shader.hpp"
#include "../../implement/FramebufferSizeCallbackImpl.hpp"
#include "../../utils/DrawBaseUtils.hpp"
#include "../../utils/KeyboardUtils.hpp"
#include "../../utils/OpenGLInitUtils.hpp"
#include "../../utils/ThreadSleepUtils.hpp"
#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <filesystem>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

int demoFunDrawTenBase3DBox();

#endif /* DemoDrawTenBase3DBoxhpp */
