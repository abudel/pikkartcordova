precision mediump float;
uniform sampler2D texSampler2D; // color map
uniform sampler2D texSampler2D_alpha;
varying vec2 v_UV;

void main()
{
	//constant
	vec3 globalAmbient = vec3(1.0,1.0,1.0);
	vec3 lightColor = vec3(1.0,1.0,1.0);
	
	//textures data
	float y = texture2D(texSampler2D, v_UV).r;
	float v = texture2D(texSampler2D_alpha, v_UV).a - 0.5;
	float u = texture2D(texSampler2D_alpha, v_UV).r - 0.5;
	float r = y + 1.13983*v;
    float g = y - 0.39465*u - 0.58060*v;
    float b = y + 2.03211*u;
	//float r = y;
    //float g = y;
    //float b = y;
	
	gl_FragColor = vec4(r, g, b, 1.0);
}