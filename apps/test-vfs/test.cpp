#include "gsvfs/gsfilesystem.h"

int main (int argc, char *argv[])
{
	gsvfs::gsfilesystem fs ("test.vfs");

	fs.addDir ("/", "Images");
	fs.addDir ("/Images", "CubeMap");
	fs.addFile ("/Images/CubeMap", "negx.bmp");
	fs.addFile ("/Images/CubeMap", "negy.bmp");
	fs.addFile ("/Images/CubeMap", "negz.bmp");
	fs.addFile ("/Images/CubeMap", "posx.bmp");
	fs.addFile ("/Images/CubeMap", "posy.bmp");
	fs.addFile ("/Images/CubeMap", "posz.bmp");

	fs.addDir ("/Images", "Heightmaps");
	fs.addFile ("/Images/Heightmaps", "continent.bmp");
	fs.addFile ("/Images/Heightmaps", "heightmap.bmp");
	fs.addFile ("/Images/Heightmaps", "landmass.bmp");

	fs.addFile ("/Images", "alphamap.tga");
	fs.addFile ("/Images", "plasma.bmp");
	fs.addFile ("/Images", "ring.tga");
	fs.addFile ("/Images", "rocky.bmp");
	fs.addFile ("/Images", "rocky-normalmap.bmp");
	fs.addFile ("/Images", "test.bmp");
	fs.addFile ("/Images", "water.bmp");

	fs.addDir ("/", "Scenes");
	fs.addFile ("/Scenes", "box.scene");
	fs.addFile ("/Scenes", "ground.scene");
	fs.addFile ("/Scenes", "quad.scene");
	fs.addFile ("/Scenes", "sphere.scene");
	fs.addFile ("/Scenes", "triangle.scene");
	fs.addFile ("/Scenes", "texture-test.scene");

	fs.addDir ("/", "Shaders");
	fs.addFile ("/Shaders", "vert.txt");
	fs.addFile ("/Shaders", "frag.txt");

	fs.addDir ("/", "Xml");
	fs.addFile ("/Xml", "test.xml");

	gsvfs::gsfile *file = fs.getFile ("/Xml/test.xml");

	FILE *f = fopen ("test-test.xml", "w+b");
	fwrite (file->getData (), file->getSize (), 1, f);
	fclose (f);

	fs.print ();

	return 0;
}
