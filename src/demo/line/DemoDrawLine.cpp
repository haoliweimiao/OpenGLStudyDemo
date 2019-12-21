/**
 * @Author: haoliwei
 * @Date: 2019-12-01 09:41:14
 * @Content: This is a demo of drawing a line
 * @Last Modified by: haoliwei
 * @Last Modified time: 2019-12-01 09:45:24
 */
#include "DemoDrawLine.hpp"

//用于绘制窗口需要的图形
void RenderScene() {
  //清除颜色缓冲区，即窗口的背景色
  glClear(GL_COLOR_BUFFER_BIT);

  //设置当前绘图使用的颜色
  glColor3f(0.0f, 0.0f, 0.0f);

  //使用当前的颜色来绘制一个矩形
  //    glRectf(100.0f, 150.0f, 150.0f, 100.0f);

  //   1.画点
  GLfloat sizesPoint[2]; //保存线宽的尺寸范围
  GLfloat stepPoint;     //保存线宽度尺寸的最小间隔
  GLfloat curSizePoint;

  glGetFloatv(GL_POINT_SIZE_RANGE, sizesPoint);
  glGetFloatv(GL_POINT_SIZE_GRANULARITY, &stepPoint);
  curSizePoint = sizesPoint[0];
  for (int i = 0; i < 25; i++) {
    glPointSize(curSizePoint);
    glBegin(GL_POINTS);
    glVertex3f(25.0 + i * 8, 200.0f, 0.0f);
    glEnd();
    curSizePoint += stepPoint * 2;
  }

  //  2. 画直线

  //    GLfloat sizesLine[2];//保存线宽的尺寸范围
  //    GLfloat stepLine;//保存线宽度尺寸的最小间隔
  GLfloat curSizeLine = 5;
  //    glGetFloatv(GL_LINE_WIDTH_RANGE,sizesLine);
  //    glGetFloatv(GL_LINE_WIDTH_GRANULARITY,&stepLine);
  glLineWidth(curSizeLine);
  glBegin(GL_LINES);
  glVertex3f(25.0f, 160.0f, 0.0f);
  glVertex3f(225.0f, 160.0f, 0.0f);

  glEnd();

  //   3.画连续的直线
  glBegin(GL_LINE_STRIP);
  glVertex3f(25.0f, 150.0f, 0.0f);
  glVertex3f(100.0f, 150.0f, 0.0f);
  glVertex3f(100.0f, 130.0f, 0.0f);
  glEnd();

  glBegin(GL_LINE_STRIP);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(10.0f, 10.0f, 0.0f);
  glVertex3f(20.0f, 5.0f, 0.0f);
  glEnd();

  //   4.画封闭式直线
  glBegin(GL_LINE_LOOP);
  glVertex3f(125.0f, 150.0f, 0.0f);
  glVertex3f(200.0f, 150.0f, 0.0f);
  glVertex3f(200.0f, 130.0f, 0.0f);
  glEnd();

  //   画虚线
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(
      1,
      0x00FF); //第一个参数是倍数，第二个参数是一个十六进制数，用来表示如何显示的
  glBegin(GL_LINES);
  glVertex3f(25.0f, 120.0f, 0.0f);
  glVertex3f(225.0f, 120.0f, 0.0f);
  glEnd();

  glLineWidth(3);
  glLineStipple(1, 0xFF0C);
  glBegin(GL_LINES);
  glVertex3f(25.0f, 80.0f, 0.0f);
  glVertex3f(225.0f, 80.0f, 0.0f);
  glEnd();

  glLineStipple(4, 0xFF0C);
  glBegin(GL_LINES);
  glVertex3f(25.0f, 40.0f, 0.0f);
  glVertex3f(225.0f, 40.0f, 0.0f);
  glEnd();
  glDisable(GL_LINE_STIPPLE);
  //刷新opengl命令队列
  glFlush();
}

//改变大小时调用的函数
void ChangeSize(GLsizei w, GLsizei h) {
  if (h == 0) {
    h = 1;
  }
  //设置视区尺寸
  glViewport(0, 0, w, h);
  //重置坐标系统，使用投影变换复位
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h) {
    glOrtho(0.0f, 250.0f, 0.0f, 250.0f * h / w, 1.0f, -1.0f);
  } else {
    glOrtho(0.0f, 250.0f * w / h, 0.0f, 250.0f, 1.0f, -1.0f);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

//用于初始化，常用来设置场景的渲染状态
void SetupRC(void) { glClearColor(1.0f, 1.0f, 1.0f, 1.0f); }

int demoDrawLine() {
  initOpenGL();

  // glfw window creation
  // --------------------
  GLFWwindow *window =
      glfwCreateWindow(WINDOW_WIEGHT, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
  //设置鼠标监听
  //   glfwSetCursorPosCallback(window, mouse_callback);
  //设置滚动监听
  //   glfwSetScrollCallback(window, scroll_callback);

  // tell GLFW to capture our mouse
  // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // configure global opengl state
  // -----------------------------
  glEnable(GL_DEPTH_TEST);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // per-frame time logic
    // --------------------
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glVertex2f(-0.5f, -0.5f); //直线起始坐标
    glVertex2f(0.5f, 0.5f);   //直线结束坐标
    glEnd();
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}
