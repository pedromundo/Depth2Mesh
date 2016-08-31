#pragma once
class DepthMap
{
public:
	DepthMap(unsigned long imageSize);
	~DepthMap();	
	const unsigned char * data() const;
	void data(unsigned char * imageBytes);
private:
	unsigned char* imageData;
	unsigned long imageSize;
};

