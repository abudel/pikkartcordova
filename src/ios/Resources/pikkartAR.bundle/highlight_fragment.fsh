precision mediump float;

varying vec3 v_Normal;
varying vec3 v_WorldView;

uniform vec4 unicolor;

void main()
{
	vec4 resultcolor;
	vec3 Nn = normalize(v_Normal);
    vec3 Vn = normalize(v_WorldView);
    float edge = 1.0 - dot(Nn,Vn);
    resultcolor.a = pow(edge,unicolor.a);
    resultcolor.rgb = edge * unicolor.rgb;
    gl_FragColor = resultcolor;
}
