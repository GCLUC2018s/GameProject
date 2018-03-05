#version 120

uniform mat4 WorldMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 ShadowTextureMatrix;
attribute vec3	Vertex;
attribute vec3	Normal;
attribute vec2	TexCoord;
//フラグメントシェーダーに渡す変数
varying vec3 V;//座標
varying vec3 N;//法線ベクトル
varying vec2 texCoord;
varying vec4 vShadowCoord;    //!< シャドウデプスマップの参照用座標
void main(void)
{
	V=vec3(WorldMatrix * vec4(Vertex,1));
    gl_Position = ProjectionMatrix * ModelViewMatrix * vec4(Vertex,1);
    N = normalize(mat3(WorldMatrix)* Normal);
	vShadowCoord = ShadowTextureMatrix*ModelViewMatrix*vec4(Vertex,1);    // 影用座標値(光源中心座標)
        
	texCoord = TexCoord;
}
