#vertex
#version 330 core
layout (location = 0) in vec2 aPos; // the position variable has attribute position 0
layout (location = 1) in vec2 uv;
out vec4 vertexColor; // specify a color output to the fragment shader

void main()
{
    gl_Position = vec4(aPos, 1.0, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
}

#fragment
#version 330 core
out vec4 finalColor;
in vec4 vertexColor;

void main(){
    finalColor = vertexColor;
}