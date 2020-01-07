attribute vec4 vertexPosition;
attribute vec4 vertexNormal;
attribute vec2 vertexTexCoord;
attribute vec4 vertexTangent;
attribute vec4 vertexBitangent;

varying vec2 texCoord;
varying vec4 normal;
varying vec4 Vertex_T;
varying vec4 Vertex_BT;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix; 
uniform vec3 cameraPos;

void main()
{
	Vertex_T=vertexTangent;
	Vertex_BT=vertexBitangent;
   gl_Position = modelViewProjectionMatrix * vertexPosition;
   normal = vertexNormal;
   texCoord = vertexTexCoord;
}
