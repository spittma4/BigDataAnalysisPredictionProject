
#include "Node.h"





Node::Node(size_t Height_, size_t Width_)
	: Height(Height_)
	, Width(Width_)
{
	if(Height != 0)
	{
		Children = new Node *[Width]();

		for(size_t i = 0; i < Width; ++i)
		{
			Children[i] = new Node(Height - 1, Width);
		}
	}
	else
	{
		Children = nullptr;
	}
	Frequency = 0;
	Hit = 0;
	Miss = 0;
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
		for(size_t i = 0; i < Width; ++i)
		{
			delete (Children[i]);
			Children[i] = nullptr;
		}
		delete[] Children;
	}
}


