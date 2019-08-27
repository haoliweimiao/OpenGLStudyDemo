/*
 * @Description: 光照贴图demo
 * @Author: haoliwei
 * @Date: 2019-08-24 08:04:18
 * @LastEditTime: 2019-08-24 08:05:55
 * @LastEditors: Please set LastEditors
 */

#ifndef DemoLightMaphpp
#define DemoLightMaphpp

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

int demoFunDrawLightMap();

#endif /* DemoLightMaphpp */
