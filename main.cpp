/*
 * @Description: main cpp
 * @Author: haoliwei
 * @Date: 2019-06-23 20:16:34
 * @LastEditTime: 2019-08-25 16:28:00
 * @LastEditors: Please set LastEditors
 */

// glad 头文件必须在包含 glfw 头文件之前，否则回报错：OpenGL header already
// included, remove this include, glad already provides
#include "src/config/ConstantConfig.hpp"
#include "src/implement/FramebufferSizeCallbackImpl.hpp"
#include "src/utils/KeyboardUtils.hpp"
#include "src/utils/OpenGLInitUtils.hpp"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <stdio.h>

#include "src/demo/Demo.hpp"
#include "src/demo/camera/DemoCameraOne.hpp"
#include "src/demo/camera/DemoColorOne.hpp"
#include "src/demo/camera/DemoColorThree.hpp"
#include "src/demo/camera/DemoColorTwo.hpp"
#include "src/demo/camera/DemoLightMap.hpp"
#include "src/demo/camera/DemoMaterialOne.hpp"
#include "src/demo/firstchapter/DemoDrawChangeColorTriangle.hpp"
#include "src/demo/firstchapter/DemoDrawColorfulTriangle.hpp"
#include "src/demo/firstchapter/DemoDrawReadLocalGLSLTriangle.hpp"
#include "src/demo/firstchapter/DemoDrawRectangle.hpp"
#include "src/demo/firstchapter/DemoDrawTexture.hpp"
#include "src/demo/firstchapter/DemoDrawTexture2.hpp"
#include "src/demo/firstchapter/DemoDrawTranslate.hpp"
#include "src/demo/firstchapter/DemoDrawTriangle.hpp"
#include "src/demo/firstchapter/DemoDrawTwoDifferentColorTriangle.hpp"
#include "src/demo/firstchapter/DemoDrawTwoDifferentTriangle.hpp"
#include "src/demo/firstchapter/DemoDrawTwoTranslate.hpp"
#include "src/demo/firstchapter/DemoDrawTwoTriangle.hpp"
#include "src/demo/line/DemoDrawLine.hpp"
#include "src/demo/start3d/DemoDrawFirst3D.hpp"
#include "src/demo/start3d/DemoDrawTenBase3DBox.hpp"

int main(int argc, char **argv) {
  // return demo();
  // return demoFunDrawTriangle();
  // return demoFunDrawRectangle();
  // return demoFunDrawTwoTriangle();
  // return demoFunDrawTwoDifferentTriangle();
  // return demoFunDrawTwoDifferentColorTriangle();
  // return demoFunDrawChangeColorTriangle();
  // return demoFunDrawColorfulTriangle();
  // return demoFunDrawReadLocalGLSLTriangle();
  return demoFunDrawTexture();
  // return demoFunDrawTexture2();
  // return demoFunDrawTranslate();
  // return demoFunDrawTwoTranslate();
  // return demoFunDrawFirst3D();
  // return demoFunDrawTenBase3DBox();
  // return demoFunDrawCameraOne();
  // return demoFunDrawColorOne();
  // return demoFunDrawColorTwo();
  // return demoFunDrawColorThree();
  // return demoFunDrawMaterialsOne();
  // return demoFunDrawLightMap();
  // return demoDrawLine();
}