/*
 * @Author: haoliwei
 * @Date: 2019-06-23 20:38:52
 * @Last Modified by: haoliwei
 * @Last Modified time: 2019-06-23 20:58:22
 */

#include "DrawRectangle.hpp"
#include "DrawBaseUtils.hpp"

// float vertices[] = {
//     // 第一个三角形
//     0.5f, 0.5f, 0.0f,   // 右上角
//     0.5f, -0.5f, 0.0f,  // 右下角
//     -0.5f, 0.5f, 0.0f,  // 左上角
//     // 第二个三角形
//     0.5f, -0.5f, 0.0f,  // 右下角
//     -0.5f, -0.5f, 0.0f, // 左下角
//     -0.5f, 0.5f, 0.0f   // 左上角
// };

const float vertices[] = {
    0.5f,  0.5f,  0.0f, // 右上角
    0.5f,  -0.5f, 0.0f, // 右下角
    -0.5f, -0.5f, 0.0f, // 左下角
    -0.5f, 0.5f,  0.0f  // 左上角
};

const unsigned int indices[] = {
    // 注意索引从0开始!
    0, 1, 3, // 第一个三角形
    1, 2, 3  // 第二个三角形
};

const char *striangle_vertex_shader =
    "#version 330 core"
    " layout(location = 0) in vec3 aPos;"
    " void main() { "
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); "
    "}";

const char *fragment_shader = "#version 330 core "
                        " out vec4 FragColor; "
                        " void main() { "
                        " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
                        " }";

void drawRectangle(GLFWwindow *window) {
  //顶点缓冲对象是我们在OpenGL教程中第一个出现的OpenGL对象。就像OpenGL中的其它对象一样，这个缓冲有一个独一无二的ID，
  //所以我们可以使用glGenBuffers函数和一个缓冲ID生成一个VBO对象：
  unsigned int VBO;
  // std::cout << "Address " << &VBO << std::endl;
  glGenBuffers(1, &VBO);

  // OpenGL有很多缓冲对象类型，顶点缓冲对象的缓冲类型是GL_ARRAY_BUFFER。
  // OpenGL允许我们同时绑定多个缓冲，只要它们是不同的缓冲类型。
  //我们可以使用glBindBuffer函数把新创建的缓冲绑定到GL_ARRAY_BUFFER目标上：
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  //从这一刻起，我们使用的任何（在GL_ARRAY_BUFFER目标上的）缓冲调用都会用来配置当前绑定的缓冲(VBO)。
  //然后我们可以调用glBufferData函数，它会把之前定义的顶点数据复制到缓冲的内存中：
  /**
   * GL_STATIC_DRAW ：数据不会或几乎不会改变。
   * GL_DYNAMIC_DRAW：数据会被改变很多。
   * GL_STREAM_DRAW ：数据每次绘制时都会改变。
   */
  //三角形的位置数据不会改变，每次渲染调用时都保持原样，所以它的使用类型最好是GL_STATIC_DRAW。如果，比如说一个缓冲中的数据将频繁被改变，
  //那么使用的类型就是GL_DYNAMIC_DRAW或GL_STREAM_DRAW，这样就能确保显卡把数据放在能够高速写入的内存部分。
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  //编译着色器
  //我们首先要做的是创建一个着色器对象，注意还是用ID来引用的。
  //所以我们储存这个顶点着色器为unsigned_int，然后用glCreateShader创建这个着色器：
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  //我们把需要创建的着色器类型以参数形式提供给glCreateShader。
  //由于我们正在创建一个顶点着色器，传递的参数是GL_VERTEX_SHADER。
  // glShaderSource函数把要编译的着色器对象作为第一个参数。第二参数指定了传递的源码字符串数量，这里只有一个。
  //第三个参数是顶点着色器真正的源码，第四个参数我们先设置为NULL。
  glShaderSource(vertexShader, 1, &striangle_vertex_shader, NULL);
  glCompileShader(vertexShader);

  //你可能会希望检测在调用glCompileShader后编译是否成功了，如果没成功的话，你还会希望知道错误是什么，
  //这样你才能修复它们。检测编译时错误可以通过以下代码来实现：
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  //首先我们定义一个整型变量来表示是否成功编译，还定义了一个储存错误消息（如果有的话）的容器。然后我们用glGetShaderiv检查是否编译成功。
  //如果编译失败，我们会用glGetShaderInfoLog获取错误消息，然后打印它。
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  //片段着色器只需要一个输出变量，这个变量是一个4分量向量，它表示的是最终的输出颜色，我们应该自己将其计算出来。
  //我们可以用out关键字声明输出变量，这里我们命名为FragColor。下面，
  //我们将一个alpha值为1.0(1.0代表完全不透明)的橘黄色的vec4赋值给颜色输出。

  //编译片段着色器的过程与顶点着色器类似，只不过我们使用GL_FRAGMENT_SHADER常量作为着色器类型：
  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
  glCompileShader(fragmentShader);

  //着色器程序
  //着色器程序对象(Shader Program
  // Object)是多个着色器合并之后并最终链接完成的版本。
  //如果要使用刚才编译的着色器我们必须把它们链接(Link)为一个着色器程序对象，然后在渲染对象的时候激活这个着色器程序。
  //已激活着色器程序的着色器将在我们发送渲染调用的时候被使用。

  //当链接着色器至一个程序的时候，它会把每个着色器的输出链接到下个着色器的输入。
  //当输出和输入不匹配的时候，你会得到一个连接错误。
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();

  // glCreateProgram函数创建一个程序，并返回新创建程序对象的ID引用。
  //现在我们需要把之前编译的着色器附加到程序对象上，然后用glLinkProgram链接它们：
  //代码应该很清楚，我们把着色器附加到了程序上，然后用glLinkProgram链接。
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  //就像着色器的编译一样，我们也可以检测链接着色器程序是否失败，并获取相应的日志。
  //与上面不同，我们不会调用glGetShaderiv和glGetShaderInfoLog，现在我们使用：

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR:glAttachShader FAILED!!!!" << std::endl;
  }

  //得到的结果就是一个程序对象，我们可以调用glUseProgram函数，
  //用刚创建的程序对象作为它的参数，以激活这个程序对象：
  glUseProgram(shaderProgram);
  //在glUseProgram函数调用之后，每个着色器调用和渲染调用都会使用这个程序对象（也就是之前写的着色器)了。
  //对了，在把着色器对象链接到程序对象以后，记得删除着色器对象，我们不再需要它们了：
  // glDeleteShader(vertexShader);
  // glDeleteShader(fragmentShader);

  //链接顶点属性
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // 0. 复制顶点数组到缓冲中供OpenGL使用
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // 1. 设置顶点属性指针
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // 2. 当我们渲染一个物体时要使用着色器程序
  glUseProgram(shaderProgram);
  // 3. 绘制物体
  someOpenGLFunctionThatDrawsOurTriangle();

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);

  // ..:: 初始化代码（只运行一次 (除非你的物体频繁改变)） :: ..
  // 1. 绑定VAO
  glBindVertexArray(VAO);
  // 2. 把顶点数组复制到缓冲中供OpenGL使用
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // 3. 设置顶点属性指针
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  unsigned int EBO;
  glGenBuffers(1, &EBO);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // ..:: 初始化代码 :: ..
  // 1. 绑定顶点数组对象
  glBindVertexArray(VAO);
  // 2. 把我们的顶点数组复制到一个顶点缓冲中，供OpenGL使用
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);
  // 4. 设定顶点属性指针
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  //[...]
  //线框模式(Wireframe Mode)
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  //默认模式。
  // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)
  // ..:: 绘制代码（渲染循环中） :: ..
  glUseProgram(shaderProgram);
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}

void someOpenGLFunctionThatDrawsOurTriangle() {
  // std::cout << "void someOpenGLFunctionThatDrawsOurTriangle();" << std::endl;
}