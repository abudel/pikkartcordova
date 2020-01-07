attribute vec4 vertexPosition;
attribute vec4 vertexNormal;

varying vec3 v_Normal;
varying vec3 v_WorldView;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix; 
uniform vec3 cameraPos;
uniform float inflate;

void main()
{
	gl_Position = modelViewProjectionMatrix * vertexPosition;
	v_Normal = normalize((modelMatrix * vertexNormal).xyz);
	vec4 newP;
	newP.xyz = vertexPosition.xyz + (inflate * v_Normal);
	newP.w = 1.0;
    vec4 Pw = modelViewMatrix * newP;
    v_WorldView = normalize(cameraPos - Pw.xyz);
}
