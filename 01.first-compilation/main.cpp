#include <irrlicht.h>

using namespace irr;

int main(void)
{
    IrrlichtDevice *device = createDevice(video::EDT_OPENGL);
    video::IVideoDriver *driver = device->getVideoDriver();

    while(device->run())
    {
	driver->beginScene(true, true, video::SColor(0,255,255,255));
	driver->endScene();
    }

    device->drop();
    return 0;
}
