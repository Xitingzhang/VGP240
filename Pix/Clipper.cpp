#include "Clipper.h"
#include "Viewport.h"

const short BIT_INSIDE = 0; //0000
const short BIT_LEFT = 1 << 1; //0001
const short BIT_RIGHT = 1 << 2; //0010
const short BIT_BOTTOM = 1 << 3; //0100
const short BIT_TOP = 1 << 4; //1000

enum class ClipEdge : short
{
	Left,
	Top,
	Right,
	Bottom,
	Count
};

bool IsInFront(ClipEdge edge, const Vector3& pos)
{
	switch (edge)
	{
	case ClipEdge:: Left: return pos.x > Viewport::Get()->GetMinX();
	case ClipEdge:: Top: return pos.y > Viewport::Get()->GetMinY();
	case ClipEdge:: Right: return pos.x < Viewport::Get()->GetMaxX();
	case ClipEdge:: Bottom: return pos.y < Viewport::Get()->GetMaxY();

		default:
			break;

	}
}

Vertex ComputeIntersection(ClipEdge edge, const Vertex& nVertex, const Vertex& np1Vertex)
{
	float t = 0.0f;
	switch (edge)
	{
	case ClipEdge::Left: 
	{
		t = (Viewport::Get()->GetMinX() - nVertex.pos.x) / (np1Vertex.pos.x - nVertex.pos.x);
	}
	break;
	case ClipEdge::Top: 
	{
		t = (Viewport::Get()->GetMinY() - nVertex.pos.y) / (np1Vertex.pos.y - nVertex.pos.y);
	}
	break;
	case ClipEdge::Right:
	{
		t = (Viewport::Get()->GetMaxX() - nVertex.pos.x) / (np1Vertex.pos.x - nVertex.pos.x);
	}
	break;
	case ClipEdge::Bottom:
	{
		t = (Viewport::Get()->GetMaxY() - nVertex.pos.y) / (np1Vertex.pos.y - nVertex.pos.y);
	}
	break;
	default:
		break;

	}
	return LerpVertex(nVertex, np1Vertex, t);
}

short GetOutputCode(float x, float y)
{
	short code = BIT_INSIDE;
	if (x < Viewport::Get()->GetMinX())
	{
		code |= BIT_LEFT;
	}
	else if (x > Viewport::Get()->GetMaxX())
	{
		code |= BIT_RIGHT;
	}

	if (y < Viewport::Get()->GetMinY())
	{
		code |= BIT_TOP;
	}

	else if (y > Viewport::Get()->GetMaxY())
	{
		code |= BIT_BOTTOM;
	}

	return code;

}

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

void Clipper::OnNewFrame()
{
	mClipping = false;
	
}



bool Clipper::ClipPoint(const Vertex& v)
{
	if(!mClipping)
	{
		return false;
	}

	float maxX = Viewport::Get()->GetMaxX();
	float maxY = Viewport::Get()->GetMaxY();
	float minX = Viewport::Get()->GetMinY();
	float minY = Viewport::Get()->GetMinY();

	return v.pos.x < minX || v.pos.x > maxX
		|| v.pos.y < minY || v.pos.y > maxY;

}
bool Clipper::ClipLine(Vertex& v0, Vertex& v1)
{
	if (!mClipping)
	{
		return false;
	}

	float maxX = Viewport::Get()->GetMaxX();
	float maxY = Viewport::Get()->GetMaxY();
	float minX = Viewport::Get()->GetMinY();
	float minY = Viewport::Get()->GetMinY();

	short codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
	short codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);

	bool cullLine = true;

	while (true)// 0100 0010 = 0110
	{
		if (!(codeV0 | codeV1))
		{
			cullLine = false;
			break;

		}
		else if (codeV0 & codeV1)
		{
			break;
			//not in the view space, cut it
		}
		else
		{
			float t = 0.0f;
			short outcodeOut = codeV1 > codeV0 ? codeV1 : codeV0;

			if (outcodeOut & BIT_TOP)
			{
				t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y);
			}
			else if (outcodeOut & BIT_BOTTOM)
			{
				t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y);
			}
			else if (outcodeOut & BIT_LEFT)
			{
				t = (minX - v0.pos.x) / (v1.pos.x - v0.pos.x);
			}
			else if (outcodeOut & BIT_RIGHT)
			{
				t = (maxX - v0.pos.x) / (v1.pos.x - v0.pos.x);
			}

			if (outcodeOut == codeV0)
			{
				v0 = LerpVertex(v0, v1, t);
				codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
			}
			else 
			{
				v1 = LerpVertex(v0, v1, t);
				codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);
			}

		}
	}
	return cullLine;


	

}

bool Clipper::ClipTriangle(std::vector<Vertex>& vertices)
{
	if (!mClipping)
	{
		return false;
	}
	std::vector<Vertex> newVertices;
	for (int i = 0; i < (int)ClipEdge::Count; ++i)
	{
		newVertices.clear();
		ClipEdge edge = (ClipEdge)i;
		for (size_t n = 0; n < vertices.size(); ++n)
		{
			size_t np1 = (n + 1) % vertices.size();
			const Vertex& nVertex = vertices[n];
			const Vertex& np1Vertex = vertices[np1];

			bool nIsInFront = IsInFront(edge, nVertex.pos);
			bool np1IsInFront = IsInFront(edge, np1Vertex.pos);

			if (nIsInFront && np1IsInFront)
			{
				//case1
				newVertices.push_back(np1Vertex);
			}
			else if (nIsInFront && !np1IsInFront)
			{
				//case2
				newVertices.push_back(ComputeIntersection(edge, nVertex, np1Vertex));
			}
			else if (!nIsInFront && !np1IsInFront)
			{
				//case3
			}
			else if (!nIsInFront && np1IsInFront)
			{
				//case4
				
				newVertices.push_back(ComputeIntersection(edge, nVertex, np1Vertex));
				newVertices.push_back(np1Vertex);
			}

		}
		vertices = newVertices;
	}
	return newVertices.empty();
}