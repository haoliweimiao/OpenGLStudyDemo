#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

// need set it value in c code
uniform float xOffset = 0.0f;
uniform mat4 transform;

void main() {
  gl_Position = transform * vec4(aPos, 1.0f);
//   gl_Position = transform * vec4(aPos.x + xOffset, aPos.y + xOffset,
//                                  aPos.z + xOffset, 1.0f);
  TexCoord = vec2(aTexCoord.x, 1.0 - aTexCoord.y);
}