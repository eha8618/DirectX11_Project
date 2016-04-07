#pragma once

#include <DirectXMath.h>
#include "DirectXGameCore.h"
#include "SimpleShader.h"
#include "Mesh.h"
#include "Entity.h"
#include "Camera.h"
#include "Lights.h"
#include "GamePadXbox.h"
#include "HUD.h"
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision\Gimpact\btGImpactCollisionAlgorithm.h"



// Include run-time memory checking in debug builds, so 
// we can be notified of memory leaks
#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

// --------------------------------------------------------
// Game class which extends the base DirectXGameCore class
// --------------------------------------------------------

//Game State Machine
static enum class GAME_STATES { MAIN_MENU, PLAYING, OPTIONS, EXIT};
//Game State
static GAME_STATES gameState;

class MyDemoGame : public DirectXGameCore
{
public:
	MyDemoGame(HINSTANCE hInstance);
	~MyDemoGame();

	// Overrides for base level methods
	bool Init();
	void OnResize();
	void UpdateScene(float deltaTime, float totalTime);
	void DrawScene(float deltaTime, float totalTime);

	// For handing mouse input
	void OnMouseDown(WPARAM btnState, int x, int y);
	void OnMouseUp(WPARAM btnState, int x, int y);
	void OnMouseMove(WPARAM btnState, int x, int y);



	//Physics 
	static  btBroadphaseInterface* broadphase;

	static btDefaultCollisionConfiguration* collisionConfiguration;
	static btCollisionDispatcher* dispatcher;

	static btSequentialImpulseConstraintSolver* solver;

	static btDiscreteDynamicsWorld* dynamicsWorld;

	void UpdatePhysics(float deltaTime); 

	


private:
	// Initialization for our "game" demo - Feel free to
	// expand, alter, rename or remove these once you
	// start doing something more advanced!
	void LoadShaders();
	void CreateGeometry();
	void CreateMatrices();

	//Meshes
	Mesh* meshOne;
	Mesh* meshTwo;
	Mesh* meshThree;

	////Entities - represent game objects

	Entity* e1;
	Entity* e2;
	Entity* e3;
	vector<Entity*> entities;

	//Camera
	Camera* cam;

	//Xbox Controller Input 
	GamePadXbox* pad; 

	//HUD
	HUD* Selector;
	HUD* Text; 
	vector<HUD*> UI; 
	

	//Material 
	Material* material;

	//Lights
	DirectionalLight directionalLight;
	DirectionalLight directionalLight2;
	SpecularLight specularLight;
	PointLight pointLight;

	//Misc
	bool leftmouseHeld;
	bool middlemouseHeld;
	bool rightmouseHeld;

	// Buffers to hold actual geometry data
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;

	// Wrappers for DirectX shaders to provide simplified functionality
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;

	// The matrices to go from model space to screen space
	DirectX::XMFLOAT4X4 worldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix;

	// Keeps track of the old mouse position.  Useful for 
	// determining how far the mouse moved in a single frame.
	POINT prevMousePos;
};