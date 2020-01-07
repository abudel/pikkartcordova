precision mediump float;
uniform sampler2D texSampler2D; // color map
uniform vec3 diffuseColor;
uniform vec3 specularColor;
uniform vec3 emissiveColor;
uniform vec3 ambientColor;
uniform float shininess;

varying vec2 v_UV;
varying vec3 v_Normal;
varying vec3 v_CameraVector;
varying vec3 v_LightVector;

void main()
{
	//constant
	vec3 globalAmbient = vec3(0.2,0.2,0.2);
	vec3 lightColor = vec3(1.0,1.0,1.0);
	
	//textures data
	vec3 tex_color = texture2D(texSampler2D, v_UV).rgb;
	
	//normal from normal map
	vec3 N = normalize(v_Normal);
	
	//compute emissive term
	vec3 emissive = emissiveColor;
	
	//compute ambient term
	vec3 ambient = ambientColor * globalAmbient;
	
	//compute diffuse term
	float dotNL = dot(N,v_LightVector);
	float diffuseLight = max(dotNL,0.0);
	vec3 diffuse = diffuseColor * tex_color * lightColor * diffuseLight;
  
	//compute specular term
	float F = 0.0;
	if(dotNL>0.0) F=1.0;
	vec3 H = normalize(v_LightVector + v_CameraVector);
	float specularLight = pow(max(dot(N,H),0.0),shininess);
	vec3 specular = specularColor * lightColor * F * specularLight;
	
	vec3 lighting = clamp(emissive + ambient + diffuse + specular,0.0,1.0);
 
	gl_FragColor.rgb = lighting;
	gl_FragColor.a = 1.0;
}