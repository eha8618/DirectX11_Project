#pragma once
#include "SimpleShader.h"
#include "WICTextureLoader.h"

using namespace DirectX; 


class Material
{
public:
	Material();
	Material(SimpleVertexShader* vShader, SimplePixelShader* pShader); 
	Material(SimpleVertexShader* vShader, SimplePixelShader* pShader, ID3D11Device* device, ID3D11DeviceContext* deviceContext, const wchar_t* filePath);
	~Material();

	ID3D11ShaderResourceView* getTextureSRV(); 
	ID3D11SamplerState* getSamplerState(); 
	const wchar_t* getFileName(); 
	
	SimpleVertexShader* vertexShader; 
	SimplePixelShader* pixelShader; 
	ID3D11ShaderResourceView* SRV;
	ID3D11SamplerState* samplerState;
	const wchar_t* file; 
	
};

