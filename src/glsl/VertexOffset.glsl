#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

//need set it value in c code
uniform float xOffset;

out vec3 ourColor;
void main() {
  gl_Position = vec4(aPos.x + xOffset, aPos.y + xOffset, aPos.z + xOffset, 1.0);
  ourColor = aColor;
}