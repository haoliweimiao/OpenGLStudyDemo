/*
 * @Description: 从本地文件读取glsl数据装载示例
 * @Author: haoliwei
 * @Date: 2019-06-24 21:18:49
 * @LastEditTime: 2019-07-02 07:06:16
 * @LastEditors: Please set LastEditors
 */

#include "DemoDrawReadLocalGLSLTriangle.hpp"

int demoFunDrawReadLocalGLSLTriangle()
{

  initOpenGL();

  // glfw window creation
  // --------------------
  GLFWwindow *window =
      glfwCreateWindow(WINDOW_WIEGHT, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  //   Shader ourShader(
  //       "/Users/hlw/workspace/c++/VSCodeOpenGL/src/glsl/VertexBase.glsl",
  //       "/Users/hlw/workspace/c++/VSCodeOpenGL/src/glsl/FragmentBase.glsl");

  //   Shader ourShader(
  //       "/Users/hlw/workspace/c++/VSCodeOpenGL/src/glsl/VertexReverse.glsl",
  //       "/Users/hlw/workspace/c++/VSCodeOpenGL/src/glsl/FragmentBase.glsl");

  Shader ourShader(
      "/Users/hlw/workspace/c++/VSCodeOpenGL/src/glsl/VertexOffset.glsl",
      "/Users/hlw/workspace/c++/VSCodeOpenGL/src/glsl/FragmentBase.glsl");

  ourShader.use();

  // In your CPP file:
  // ======================
  float offset = 0.2f;
  ourShader.setFloat("xOffset", offset);

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] = {
      // positions         // colors
      0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
      0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
  };

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // You can unbind the VAO afterwards so other VAO calls won't accidentally
  // modify this VAO, but this rarely happens. Modifying other VAOs requires a
  // call to glBindVertexArray anyways so we generally don't unbind VAOs (nor
  // VBOs) when it's not directly necessary. glBindVertexArray(0);

  // as we only have a single shader, we could also just activate our shader
  // once beforehand if we want to
  glUseProgram(ourShader.ID);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window))
  {
    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // render the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}