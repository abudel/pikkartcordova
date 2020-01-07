attribute vec4 vertexPosition;
attribute vec4 vertexNormal;
attribute vec2 vertexTexCoord;
attribute vec4 vertexTangent;
attribute vec4 vertexBitangent;

varying vec2 v_UV;
varying vec3 v_CameraVector;
varying vec3 v_LightVector;


uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix; 
uniform mat4 modelMatrix; 
uniform vec3 cameraPos;

void m_transpose(mat3 i, out mat3 m)
{
	m[0][0]=i[0][0];
	m[1][0]=i[0][1];
	m[2][0]=i[0][2];
	m[0][1]=i[1][0];
	m[1][1]=i[1][1];
	m[2][1]=i[1][2];
	m[0][2]=i[2][0];
	m[1][2]=i[2][1];
	m[2][2]=i[2][2];
}

void main()
{
	float neutral_handedness = vertexTangent.w;
	vec3 neutral_tangent  = normalize((modelMatrix * vertexTangent).xyz);
	vec3 neutral_binormal = normalize((modelMatrix * vertexBitangent).xyz);
	vec3 neutral_normal = normalize((modelMatrix * vertexNormal).xyz);
	//calculate tangent space for world->tangent transform
	//mat3 TBN = mat3(neutral_tangent.x, neutral_binormal.x, neutral_normal.x, neutral_tangent.y, neutral_binormal.y, neutral_normal.y, neutral_tangent.z, neutral_binormal.z, neutral_normal.z);
	//mat3 TBN = mat3(normalize(neutral_tangent), normalize(neutral_binormal), normalize(neutral_normal));
	mat3 TBN = mat3(1.0);
	m_transpose(mat3(neutral_tangent,neutral_binormal,neutral_normal),TBN);
	//emit world_space vertex position
	vec3 vertexPosition_CV  = (modelViewMatrix * vertexPosition).xyz;
	//emit UVs
	v_UV = vertexTexCoord;
	//emit light vector
	vec3 light_pos = vec3(0.0,0.0,0.0);
	vec3 camera_pos = vec3(0.0,0.0,0.0);
	v_LightVector = normalize(TBN * (light_pos - vertexPosition_CV));
	v_CameraVector = normalize(TBN * (camera_pos - vertexPosition_CV)); 
	//v_CameraVector = v_LightVector;
	gl_Position = modelViewProjectionMatrix * vertexPosition;
}