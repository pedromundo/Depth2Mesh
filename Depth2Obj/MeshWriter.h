#pragma once
class MeshWriter
{
public:
	MeshWriter();
	virtual ~MeshWriter();
	virtual int writeDepthToMeshfile(const char* fileName, const unsigned char* imageData, const unsigned char* colorData = 0, bool cullBlack = false, int width = 640, int height = 480) = 0;
	float interpolate(float a, float b, float coefficient);	
};