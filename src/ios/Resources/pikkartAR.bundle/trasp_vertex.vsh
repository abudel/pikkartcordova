attribute vec4 vertexPosition;
attribute vec4 vertexNormal;

varying vec4 normal;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix; 
uniform vec3 cameraPos;

void main()
{
	gl_Position = modelViewProjectionMatrix * vertexPosition;
    normal = modelMatrix * vertexNormal;
}
