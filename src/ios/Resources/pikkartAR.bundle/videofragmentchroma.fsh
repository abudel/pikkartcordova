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

float th = 8.0;
float a2 = 1.2;
float spill = 1.0;

float getAlpha(vec4 c){
    // First Vlahos assumption: Gf <= a2Bf
    return 1.0 - th*(c.g-a2*(max(c.r,c.b)));
}

vec4 despill(vec4 c){
    // Second Vlahos assumption: max (Gf - Bf,0) <= max(Bf - Rf, 0)
    float sub = max(c.g - mix(c.b, c.r, 0.45), 0.0);
    c.g -= sub;
    c.a -= smoothstep(0.25, 0.5, sub*c.a);
    //restore luminance (kind of, I slightly reduced the green weight)
    float luma = dot(c.rgb, vec3(0.350, 0.587,0.164));
    c.r += sub*c.r*2.0*.350/luma;
    c.g += sub*c.g*2.0*.587/luma;
    c.b += sub*c.b*2.0*.164/luma;
    return c;
}

void main() {
   vec4 video_color = texture2D(texSampler2D, texCoord);
   video_color.a = clamp(getAlpha(video_color), 0.0, 1.0);
   video_color = despill(video_color);
   gl_FragColor = video_color;
}