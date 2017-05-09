
#include "Node.h"





Node::Node()
	:Height(0)
	, Width(0)
	, Children(nullptr)
	, Frequency(0)
	, Hit(0)
	, Miss(0)
{
}

void Node::Initialize(size_t NewHeight, size_t NewWidth)
{
	Height = NewHeight;
	Width = NewWidth;
	if(Height != 0)
	{
		Children = new Node[Width]();

		for(size_t i = 0; i < Width; ++i)
		{
			Children[i].Initialize(Height - 1, Width);
		}
	}
	else
	{
		Children = nullptr;
	}
}

Node::Node(size_t Height_, size_t Width_)
	: Height(Height_)
	, Width(Width_)
	, Frequency(0)
	, Hit(0)
	, Miss(0)
{
	Initialize(Height, Width);
}

double Node::GetProbabilityWeight()
{
	if(Hit + Miss == 0) { return Frequency; } //prevent divide by zero error
	return Frequency * Hit / (Hit + Miss);
}


Node::~Node()
{
	if(Children != nullptr)
	{
		/*for(size_t i = 0; i < Width; ++i)
		{
			delete[] (Children[i]);
			Children[i] = nullptr;
		}*/
		delete[] Children;
	}
}


