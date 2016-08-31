#pragma once
#include "MeshWriter.h"
class XyzMeshWriter :
	public MeshWriter
{
public:
	XyzMeshWriter();
	~XyzMeshWriter();
	int writeDepthToMeshfile(const char* fileName, const unsigned char* depthData, const unsigned char* colorData = 0, bool cullBlack = false, int width = 640, int height = 480);
};

