/*
 * @Description: demo_draw_two_triangle
 * @Author: haoliwei
 * @Date: 2019-06-24 22:53:26
 * @LastEditTime: 2019-06-29 23:37:47
 * @LastEditors: Please set LastEditors
 */
#include "DemoDrawTwoDifferentColorTriangle.hpp"

int demoFunDrawTwoDifferentColorTriangle() {

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

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // build and compile our shader program
  // ------------------------------------
  // we skipped compile log checks this time for readability (if you do
  // encounter issues, add the compile-checks! see previous code samples)
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  unsigned int fragmentShaderOrange =
      glCreateShader(GL_FRAGMENT_SHADER); // the first fragment shader that
                                          // outputs the color orange
  unsigned int fragmentShaderYellow =
      glCreateShader(GL_FRAGMENT_SHADER); // the second fragment shader that
                                          // outputs the color yellow
  unsigned int shaderProgramOrange = glCreateProgram();
  unsigned int shaderProgramYellow =
      glCreateProgram(); // the second shader program
  glShaderSource(vertexShader, 1, &VERTEX_SHADER_SOURCE, NULL);
  glCompileShader(vertexShader);
  glShaderSource(fragmentShaderOrange, 1, &FRAGMENT_SHADER_SOURCE, NULL);
  glCompileShader(fragmentShaderOrange);
  glShaderSource(fragmentShaderYellow, 1, &FRAGMENT_SHADER_SOURCE_YELLOW, NULL);
  glCompileShader(fragmentShaderYellow);
  

  // link the first program object
  glAttachShader(shaderProgramOrange, vertexShader);
  glAttachShader(shaderProgramOrange, fragmentShaderOrange);
  glLinkProgram(shaderProgramOrange);
  // then link the second program object using a different fragment shader (but
  // same vertex shader) this is perfectly allowed since the inputs and outputs
  // of both the vertex and fragment shaders are equally matched.
  glAttachShader(shaderProgramYellow, vertexShader);
  glAttachShader(shaderProgramYellow, fragmentShaderYellow);
  glLinkProgram(shaderProgramYellow);


  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float firstTriangle[] = {
      -0.9f,  -0.5f, 0.0f, // left
      -0.0f,  -0.5f, 0.0f, // right
      -0.45f, 0.5f,  0.0f, // top
  };
  float secondTriangle[] = {
      0.0f,  -0.5f, 0.0f, // left
      0.9f,  -0.5f, 0.0f, // right
      0.45f, 0.5f,  0.0f  // top
  };
  unsigned int VBOs[2], VAOs[2];
  glGenVertexArrays(
      2,
      VAOs); // we can also generate multiple VAOs or buffers at the same time
  glGenBuffers(2, VBOs);
  // first triangle setup
  // --------------------
  glBindVertexArray(VAOs[0]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle,
               GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                        (void *)0); // Vertex attributes stay the same
  glEnableVertexAttribArray(0);
  // glBindVertexArray(0); // no need to unbind at all as we directly bind a
  // different VAO the next few lines second triangle setup
  // ---------------------
  glBindVertexArray(VAOs[1]); // note that we bind to a different VAO now
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]); // and a different VBO
  glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle,
               GL_STATIC_DRAW);
  glVertexAttribPointer(
      0, 3, GL_FLOAT, GL_FALSE, 0,
      (void *)0); // because the vertex data is tightly packed we can also
                  // specify 0 as the vertex attribute's stride to let OpenGL
                  // figure it out
  glEnableVertexAttribArray(0);
  // glBindVertexArray(0); // not really necessary as well, but beware of calls
  // that could affect VAOs while this one is bound (like binding element buffer
  // objects, or enabling/disabling vertex attributes)

  // uncomment this call to draw in wireframe polygons.
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // now when we draw the triangle we first use the vertex and orange fragment
    // shader from the first program
    glUseProgram(shaderProgramOrange);
    // draw the first triangle using the data from our first VAO
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0,
                 3); // this call should output an orange triangle
    // then we draw the second triangle using the data from the second VAO
    // when we draw the second triangle we want to use a different shader
    // program so we switch to the shader program with our yellow fragment
    // shader.
    glUseProgram(shaderProgramYellow);
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0,
                 3); // this call should output a yellow triangle

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(2, VAOs);
  glDeleteBuffers(2, VBOs);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}