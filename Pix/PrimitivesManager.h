#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();

	bool BeginDraw(Topology topology);

	void AddVertex(const Vertex& vertex);

	bool EndDraw();

private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	bool mDrawBegin = false;
};


