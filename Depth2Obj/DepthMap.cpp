#include "stdafx.h"
#include "DepthMap.h"

DepthMap::DepthMap(unsigned long imageSize)
{
	this->imageSize = imageSize;	
}

DepthMap::~DepthMap()
{
}

const unsigned char * DepthMap::data( ) const{
	return this->imageData;
}

void DepthMap::data(unsigned char * imageBytes){
	if (sizeof(imageBytes) != this->imageSize){
		throw "Declared size and image size mismatch!";
		return;
	}
	this->imageData = imageBytes;
}