#include "Vehicle.h"



//Vehicle::Vehicle()
//{
//}
//
//Vehicle::Vehicle(Mesh* inputMesh, Material* inputMaterial):
//	Entity(inputMesh, inputMaterial)
//{
//
//
//	// make chassis with a collision shape and a rigid body, also added to dynamic world
//	//btScalar chassisMass(1.0f);
//	//btVector3 chassisInertia(0.0f, 0.0f, 0.0f);
//	//btCollisionShape* chassisShape = new btBoxShape(btVector3(2.0f, 1.0f, 4.0f));
//
//	//btDefaultMotionState* chassisMotionState = new btDefaultMotionState(btTransform(btQuaternion(0.0f, 0.0f, 0.0f, 1.0f), btVector3(0.0f, 4.0f, 0.0f)));
//	//chassisShape->calculateLocalInertia(chassisMass, chassisInertia);
//
//	//btRigidBody::btRigidBodyConstructionInfo chassisRBCI(chassisMass, chassisMotionState, chassisShape, chassisInertia);
//	//btRigidBody* chassisRB = new btRigidBody(chassisRBCI);
//	//chassisRB->setActivationState(DISABLE_DEACTIVATION);
//	////dynamicsWorld->addRigidBody(chassisRB);
//
//	//// setting raycasting for wheels and making vehicle
//	//btRaycastVehicle::btVehicleTuning tune;
//	//btVehicleRaycaster* caster = new btDefaultVehicleRaycaster(dynamicsWorld);
//	//btRaycastVehicle* vehicle = new btRaycastVehicle(tune, chassisRB, caster);
//	//vehicle->setCoordinateSystem(0, 1, 2);
//
//	//// make wheels, also keep them under the half-length of chassis
//	//btVector3 wheelDir(0.0f, -1.0f, 0.0f);
//	//btVector3 wheelAxis(-1.0f, 0.0f, 0.0f);
//	//btScalar suspensionRestLength(0.5f);
//	//btScalar wheelRad(0.5f);
//
//	//vehicle->addWheel(btVector3(-1.0f, 0.0f, 2.0f), wheelDir, wheelAxis, suspensionRestLength, wheelRad, tune, true);
//	//vehicle->addWheel(btVector3(1.0f, 0.0f, 2.0f), wheelDir, wheelAxis, suspensionRestLength, wheelRad, tune, true);
//	//vehicle->addWheel(btVector3(-1.0f, 0.0f, -2.0f), wheelDir, wheelAxis, suspensionRestLength, wheelRad, tune, false);
//	//vehicle->addWheel(btVector3(1.0f, 0.0f, -2.0f), wheelDir, wheelAxis, suspensionRestLength, wheelRad, tune, false);
//
//
//
//	// Graphics 
//	position = XMFLOAT4X4(
//		1.0f, 0.0f, 0.0f, 0.0f,
//		0.0f, 1.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, 0.0f, 1.0f);
//	rotation = XMFLOAT4X4(
//		1.0f, 0.0f, 0.0f, 0.0f,
//		0.0f, 1.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, 0.0f, 1.0f);
//	scalar = XMFLOAT4X4(
//		1.0f, 0.0f, 0.0f, 0.0f,
//		0.0f, 1.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, 0.0f, 1.0f);
//
//	worldMatrix = XMFLOAT4X4(
//		1.0f, 0.0f, 0.0f, 0.0f,
//		0.0f, 1.0f, 0.0f, 0.0f,
//		0.0f, 0.0f, 1.0f, 0.0f,
//		0.0f, 0.0f, 0.0f, 1.0f);
//		
//}
//
//
//Vehicle::~Vehicle()
//{
//}


