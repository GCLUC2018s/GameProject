float rand(vec2 co) {
    float t = fract(co.x * 43758.5453);
    return t;
}
 
uniform sampler2D tDiffuse;
uniform vec2 vScreenSize;
void main() {
 

    float radius = 5.0;
 
    float x = (gl_TexCoord[0].x * vScreenSize.x) + rand(vec2(gl_TexCoord[0].x,gl_TexCoord[0].y)) * radius * 2.0 - radius;
    float y = (gl_TexCoord[0].y * vScreenSize.y) + rand(vec2(gl_TexCoord[0].y,gl_TexCoord[0].x)) * radius * 2.0 - radius;
 
    vec4 textureColor = texture2D(tDiffuse, vec2( gl_TexCoord[0].x+ rand(vec2(gl_TexCoord[0].x,gl_TexCoord[0].y))*0.01f,gl_TexCoord[0].y + rand(vec2(gl_TexCoord[0].y,gl_TexCoord[0].x))*0.01f ) );
    gl_FragColor = textureColor;
}
