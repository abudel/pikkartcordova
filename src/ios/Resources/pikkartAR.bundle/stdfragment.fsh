precision mediump float;

varying vec2 texCoord;
varying vec4 normal;
varying vec4 Vertex_T;
varying vec4 Vertex_BT;

uniform sampler2D texSampler2D;

void main()
{
   gl_FragColor = texture2D(texSampler2D, texCoord);
}
