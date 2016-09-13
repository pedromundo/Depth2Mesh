#pragma once
#include "MeshWriter.h"
class XyzMeshWriter :
	public MeshWriter
{
public:
	XyzMeshWriter();
	~XyzMeshWriter();
	int writeDepthToMeshfile(const char* fileName, const unsigned char* depthData, const unsigned char* colorData, bool cullBlack, int width=640, int height=480, unsigned int minMM=720, unsigned int maxMM=900);
};

