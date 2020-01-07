attribute vec4 vertexPosition;
attribute vec4 vertexNormal;
attribute vec2 vertexTexCoord;

varying vec2 v_UV;
varying vec3 v_Normal;
varying vec3 v_CameraVector;
varying vec3 v_LightVector;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix; 
uniform vec3 cameraPos;

void main()
{
	v_Normal = normalize((modelMatrix * vertexNormal).xyz);
	vec3 vertexPosition_CV  = (modelViewMatrix * vertexPosition).xyz;
	vec3 light_pos = vec3(0.0,0.0,0.0);
	vec3 camera_pos = vec3(0.0,0.0,0.0);
	v_LightVector = normalize(light_pos - vertexPosition_CV);
	v_CameraVector = normalize(camera_pos - vertexPosition_CV); 
	v_UV = vertexTexCoord;
	gl_Position = modelViewProjectionMatrix * vertexPosition;
}