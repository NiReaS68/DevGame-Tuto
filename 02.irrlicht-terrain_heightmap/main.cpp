#include <irrlicht.h>

using namespace irr;

int main(void)
{
	/* INIT */
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL);
	video::IVideoDriver *driver = device->getVideoDriver();
	scene::ISceneManager *sceneManager = device->getSceneManager();
	device->getCursorControl()->setVisible(false);

	/* CAMERA */
	SKeyMap keyMap[5];
	keyMap[0].Action = EKA_MOVE_FORWARD;
	keyMap[0].KeyCode = KEY_KEY_Z;
	keyMap[1].Action = EKA_MOVE_BACKWARD;
	keyMap[1].KeyCode = KEY_KEY_S;
	keyMap[2].Action = EKA_STRAFE_LEFT;
	keyMap[2].KeyCode = KEY_KEY_Q;
	keyMap[3].Action = EKA_STRAFE_RIGHT;
	keyMap[3].KeyCode = KEY_KEY_D;
	keyMap[4].Action = EKA_JUMP_UP;
	keyMap[4].KeyCode = KEY_SPACE;

	sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);

	/* TERRAIN */
	scene::ITerrainSceneNode *terrain = sceneManager->addTerrainSceneNode("../img/heightmap0.png", 0, -1, core::vector3df(-100,-20,20), core::vector3df(0,0,0), core::vector3df(1,0.25,1));
	terrain->setMaterialTexture(0, driver->getTexture("../img/texture0.png"));

	/* LIGHT */
	sceneManager->setAmbientLight(video::SColorf(0.9, 0.9, 0.9, 0.0));

	/* RENDER */
	while(device->run())
	{
		driver->beginScene(true, true, video::SColor(0,255,255,255));
		sceneManager->drawAll();
		driver->endScene();
	}

	device->drop();
	return 0;
}
