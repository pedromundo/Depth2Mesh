#include "MeshWriter.h"


MeshWriter::MeshWriter()
{
}


MeshWriter::~MeshWriter()
{
}

double MeshWriter::interpolate(double a, double b, double coefficient)
{
	return a + coefficient * (b - a);
}
