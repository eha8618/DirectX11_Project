#pragma once
#include "Mesh.h"
#include "Material.h"
#include "Camera.h"
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision\Gimpact\btGImpactCollisionAlgorithm.h"


using namespace DirectX;

class Skybox
{
public:
	Skybox();
	Skybox(Mesh * inputMesh, Material* inputMaterial, Camera* cam);
	~Skybox();

	void prepareMaterial(XMFLOAT4X4 view, XMFLOAT4X4 proj);
	void drawScene(ID3D11DeviceContext * deviceContext);

	void updateScene();

private:

	Mesh* mesh;
	Material* skyTexture;

	float scale;

	XMFLOAT4X4* identity;
	XMFLOAT4X4* position;
	XMFLOAT4X4* scaleMatrix;

	XMFLOAT4X4* worldMatrix;

	Camera* camera;
};

