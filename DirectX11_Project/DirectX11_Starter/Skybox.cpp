#include "Skybox.h"



Skybox::Skybox()
{
}

Skybox::Skybox(Mesh * inputMesh, Material* inputMaterial, Camera* cam)
{ 
	mesh = inputMesh;
	skyTexture = inputMaterial;

	camera = cam;

	identity = new XMFLOAT4X4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	scale = 1.0f;

	scaleMatrix = new XMFLOAT4X4(
		scale, 0.0f, 0.0f, 0.0f,
		0.0f, scale, 0.0f, 0.0f,
		0.0f, 0.0f, scale, 0.0f,
		0.0f, 0.0f, 0.0f, scale);

	worldMatrix = scaleMatrix;

	//XMStoreFloat4x4(scaleMatrix, XMMatrixScaling(scale,scale,scale));
}

Skybox::~Skybox()
{
}


void Skybox::prepareMaterial(XMFLOAT4X4 view, XMFLOAT4X4 proj)
{
	//Prepares material object for reuse

	//don't adjust world matrix of sky?
	//skyTexture->vertexShader->SetMatrix4x4("world", &identity*&scaleMatrix);
	//XMMATRIX i = XMLoadFloat4x4(identity);
	//XMMATRIX s = XMLoadFloat4x4(scaleMatrix);
	//XMFLOAT4X4 t;
	//XMStoreFloat4x4(&t, XMMatrixTranspose(i*s));
	//skyTexture->vertexShader->SetMatrix4x4("world", t);

//	skyTexture->getFileName();

	updateScene();
	//camera->getPosition();

	skyTexture->vertexShader->SetMatrix4x4("world", *worldMatrix);
	skyTexture->vertexShader->SetMatrix4x4("view", view);
	skyTexture->vertexShader->SetMatrix4x4("projection", proj);
	skyTexture->vertexShader->SetShader(true);
	skyTexture->pixelShader->SetShader(true);
	skyTexture->pixelShader->SetShaderResourceView("diffuseTexture", skyTexture->SRV);
	skyTexture->pixelShader->SetSamplerState("trillinear", skyTexture->samplerState);
}

void Skybox::drawScene(ID3D11DeviceContext * deviceContext)
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	ID3D11Buffer* tempBuffer = this->mesh->GetVertexBuffer();

	deviceContext->IASetVertexBuffers(0, 1, &tempBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(this->mesh->GetIndexBuffer(), DXGI_FORMAT_R32_UINT, 0);

	// Finally do the actual drawing
	//  - Do this ONCE PER OBJECT you intend to draw
	//  - This will use all of the currently set DirectX "stuff" (shaders, buffers, etc)
	//  - DrawIndexed() uses the currently set INDEX BUFFER to look up corresponding
	//     vertices in the currently set VERTEX BUFFER
	deviceContext->DrawIndexed(
		this->mesh->GetIndexCount(),     // The number of indices to use (we could draw a subset if we wanted)
		0,     // Offset to the first index we want to use
		0);    // Offset to add to each index when looking up vertices

}

void Skybox::updateScene() {
	//XMMATRIX worldMat = XMLoadFloat4x4(&worldMatrix);
	XMFLOAT3 pos = camera->getPosition();
	XMMATRIX translation = XMLoadFloat4x4(&XMFLOAT4X4{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			pos.x, pos.y, pos.z, 1.0f
	});
	//XMMATRIX rot = XMLoadFloat4x4(&rotation);
	XMMATRIX scaling = XMLoadFloat4x4(scaleMatrix);


	XMMATRIX worldMat = translation * scaling;
	//XMStoreFloat4x4(&worldMat, XMTranspose worldMatrix);
	//XMStoreFloat4x4(worldMatrix, XMMatrixTranspose(worldMat));
}