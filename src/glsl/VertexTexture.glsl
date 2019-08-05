#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

// need set it value in c code
uniform float xDirection = 1.f;
uniform float yDirection = 1.f;

void main() {
  gl_Position = vec4(aPos, 1.0);
  // aPos.x 取反，图像y轴方向镜像效果
  // aPos.y 取反，图像x轴方向镜像效果
  gl_Position = vec4(aPos.x * xDirection, aPos.y * yDirection, aPos.z, 1.0);
  // ourColor = aColor;
  TexCoord = aTexCoord;
}