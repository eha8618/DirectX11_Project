#pragma once
#include "Entity.h"
class Vehicle :
	public Entity
{
public:
	Vehicle();
	Vehicle(Mesh* inputMesh, Material* inputMaterial);
	~Vehicle();
};

