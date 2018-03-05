 uniform sampler2D tDiffuse;
void main() {
	vec4 textureColor = texture2D(tDiffuse, vec2( gl_TexCoord[0].x,gl_TexCoord[0].y) );
    gl_FragColor = textureColor;
}
