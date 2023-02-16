#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};
enum class CullMode
{
	None,
	Front,
	Back
};
class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void SetCullMode(CullMode mode);

	bool BeginDraw(Topology topology, bool applyTransform = false);

	void AddVertex(const Vertex& vertex);

	bool EndDraw();

private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	CullMode mCullMode = CullMode::None;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
};


