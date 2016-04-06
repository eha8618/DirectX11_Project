#include "HUD.h"



HUD::HUD()
{
	spriteBatch = nullptr; 
}

HUD::HUD(ID3D11DeviceContext * deviceContext)
{
	spriteBatch = new SpriteBatch(deviceContext); 
}


HUD::~HUD()
{
	delete spriteBatch; 
}
