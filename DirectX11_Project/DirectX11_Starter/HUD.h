#pragma once
#include "SimpleShader.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
using namespace DirectX; 

class HUD
{
public:
	HUD();
	HUD(ID3D11DeviceContext* deviceContext);
	~HUD();

private: 
	SpriteBatch* spriteBatch; 
};

