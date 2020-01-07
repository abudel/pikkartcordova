#ifndef IOS
#extension GL_OES_EGL_image_external : require
#endif
precision mediump float;
varying vec2 texCoord;
varying vec4 normal;
varying vec4 Vertex_T;
varying vec4 Vertex_BT;
#ifndef IOS
uniform samplerExternalOES texSampler2D;
#else
uniform sampler2D texSampler2D;
#endif
void main()
{
   gl_FragColor = texture2D(texSampler2D, texCoord);
}