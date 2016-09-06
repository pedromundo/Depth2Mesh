#include "MeshWriter.h"


MeshWriter::MeshWriter()
{
}


MeshWriter::~MeshWriter()
{
}

float MeshWriter::interpolate(float a, float b, float coefficient)
{
	return a + coefficient * (b - a);
}
