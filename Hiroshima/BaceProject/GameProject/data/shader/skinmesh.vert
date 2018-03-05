#version 120

uniform mat4 Transforms[96];
uniform mat4 WorldMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 ShadowTextureMatrix;
uniform int useSkin=0;

attribute vec3	Vertex;
attribute vec3	Normal;
attribute vec2	TexCoord;
attribute vec4 indices;
attribute vec4 weights;

//フラグメントシェーダーに渡す変数
varying vec3 V;//座標
varying vec3 N;//法線ベクトル
varying vec2 texCoord;
varying vec4 vShadowCoord;    //!< シャドウデプスマップの参照用座標
void main(void)
{
		mat4 comb = mat4(0);
	if(useSkin==1) {

		comb += Transforms[int(indices.x)] * weights.x;
		comb += Transforms[int(indices.y)] * weights.y;
		comb += Transforms[int(indices.z)] * weights.z;
		comb += Transforms[int(indices.w)] * weights.w;

		vec4 skinPosition = ModelViewMatrix * comb * vec4(Vertex,1);
		V = vec3(WorldMatrix * comb * vec4(Vertex,1));
		gl_Position = ProjectionMatrix * skinPosition;
		N = normalize(mat3(WorldMatrix* comb) * Normal);
	} else {
		V=vec3(WorldMatrix * vec4(Vertex,1));
		gl_Position = ProjectionMatrix * ModelViewMatrix * vec4(Vertex,1);
		N = normalize(mat3(WorldMatrix)* Normal);
	}
	
	vShadowCoord = ShadowTextureMatrix*ModelViewMatrix*vec4(Vertex,1);    // 影用座標値(光源中心座標)
	texCoord = TexCoord;
}
