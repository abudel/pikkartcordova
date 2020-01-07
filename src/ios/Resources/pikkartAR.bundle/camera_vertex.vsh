attribute vec4 vertexPosition;
attribute vec2 vertexTexCoord;

varying vec2 v_UV;

uniform mat4 modelViewProjectionMatrix;

void main()
{
	v_UV = vertexTexCoord;
	gl_Position = modelViewProjectionMatrix * vertexPosition;
}