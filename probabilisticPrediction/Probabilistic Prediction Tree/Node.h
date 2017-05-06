//#pragma once

class Node
{
	Node();
	void Initialize(size_t Height, size_t Width);

public:
	Node *  Children;
	size_t Height;
	size_t Width;
	size_t Frequency;
	double Hit;
	double Miss;



	Node(size_t Height, size_t Width);

	double GetProbabilityWeight();



	~Node();



};



