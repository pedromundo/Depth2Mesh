// Depth2Obj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MeshWriter.h"
#include "XyzMeshWriter.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char* fileName;
	unsigned char* depthImageData;
	unsigned char* colorImageData;
	int width, height, channels, width2, height2, channels2;
	/*cout << "Enter filename: ";
	cin >> fileName;
	cin.ignore();*/

	depthImageData = SOIL_load_image("bag_depth.bmp", &width, &height, &channels, SOIL_LOAD_L);
	printf(SOIL_last_result());
	printf("%dx%dx%d Depth Image. Size in ubytes: %ld\n", width, height, channels, width*height*channels*sizeof(unsigned char));

	colorImageData = SOIL_load_image("bag_rgb_lores.jpg", &width2, &height2, &channels2, SOIL_LOAD_L);
	printf(SOIL_last_result());
	printf("\n%dx%dx%d Color Image. Size in ubytes: %ld\n", width2, height2, channels2, width2*height2*channels2*sizeof(unsigned char));

	if (width*height != width2*height2){
		cout << "Size mismatch between the depth and the RGB image, automatic rescaling isn't supported yet!";
	}

	MeshWriter* writer = new XyzMeshWriter();
	writer->writeDepthToMeshfile("mesh.xyz", depthImageData, colorImageData, true);
	return 0;
}

