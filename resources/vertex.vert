#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;

out vec3 vertexColor;

uniform mat4 u_Projection;
uniform mat4 u_View;

void main() {
    gl_Position = u_Projection * u_View * vec4(aPosition, 1.0);
    vertexColor = aColor;
}
