#include "ProbabilisticPredictor.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

deque<size_t> ProbabilisticPredictor::GetPredictionSequence(size_t SquenceNumber)
{
	deque<size_t> ReturnValue;
	for(size_t i = (SquenceNumber >= (Height - 1) && SquenceNumber - (Height - 1) >= StartOffset ? SquenceNumber - (Height - 1) : StartOffset); i <= SquenceNumber; ++i)
	{
		ReturnValue.push_back(ReadSymbol(i));
	}
	return ReturnValue;




}

void ProbabilisticPredictor::Predict(size_t SequenceNumber)
{
	if(KnownSymbols.size() == 0)
	{
		throw string("Cannot predict on empty predicter!");
	}

	if(SequenceNumber <= StartOffset || SequenceNumber - StartOffset < KnownSymbols.size() || (SequenceNumber - StartOffset) - KnownSymbols.size() < Predictions.size())
	{
		return; // this prediction either exists or is invalid
	}

	//if(((SequenceNumber - 1) - StartOffset) - KnownSymbols.size() > Predictions.size())
	{
		Predict(SequenceNumber - 1);// this should stop when it hits a predicted or known symbol
	}
	deque<size_t> PredictionSequence = GetPredictionSequence(SequenceNumber - 1);

	if(PredictionSequence.size() >= Height)
	{
		PredictionSequence.pop_front();
	}//it needs to be, at most, height - 1 to leave room for the new item in trie

	Node * CurrentNode = RootNode;
	for(size_t i = 0; i < PredictionSequence.size(); ++i)
	{
		CurrentNode = CurrentNode->Children[PredictionSequence[i]];
	}

	double TotalWeight = 0;
	for(size_t i = 0; i < Width; ++i)
	{
		TotalWeight += CurrentNode->Children[i]->GetProbabilityWeight();
	}

	size_t PredictedValue = PredictionSequence.back();
	double BestWeight = CurrentNode->Children[PredictedValue]->GetProbabilityWeight();

	for(size_t i = 0; i < Width; ++i)
	{
		if(CurrentNode->Children[i]->GetProbabilityWeight() > BestWeight)
		{
			PredictedValue = i;
			BestWeight = CurrentNode->Children[PredictedValue]->GetProbabilityWeight();
		}
	}

	double NewProbability = (TotalWeight
		? (BestWeight / TotalWeight)
		: 1 / ((double)Width));

	NewProbability = (Predictions.size()
		? Predictions.back().second * NewProbability
		: NewProbability);


	Predictions.push_back(pair<size_t, double>(PredictedValue, NewProbability));
}

ProbabilisticPredictor::ProbabilisticPredictor(size_t Height_, size_t Width_, size_t HistorySize_, size_t StartOffset_)
	: Height(Height_)
	, Width(Width_)
	, HistorySize(HistorySize_)
	, StartOffset(StartOffset_)
	, RootNode(new Node(Height_, Width_))
{
	if(HistorySize && HistorySize < Height - 1)
	{
		HistorySize = Height - 1;
	}
}

void ProbabilisticPredictor::InputNextSymbol(size_t NextSymbol)
{
	deque<size_t> SymbolSequence;
	SymbolSequence.push_back(NextSymbol);
	InputSequence(SymbolSequence);
	/*
	if(NextSymbol > Width - 1)
	{
		throw string("Symbol \"") + to_string(NextSymbol) + string("\" out of width range ") + to_string(Width);
	}

	if(Predictions.size())
	{
		bool Hit = false;
		bool Miss = false;
		Miss = !(Hit = (Predictions.front().first == NextSymbol));
		double Probability = Predictions.front().second;

		deque<size_t> PredictionSequence = GetPredictionSequence(KnownSymbols.size() + StartOffset);

		Node * CurrentNode = RootNode;
		for(size_t i = 0; i < PredictionSequence.size(); ++i)
		{
			CurrentNode = CurrentNode->Children[PredictionSequence[i]];
			if(Miss)
			{
				CurrentNode->Miss += Probability;
			}
			else if(Hit)
			{
				CurrentNode->Hit += Probability;
			}
		}
		Predictions.clear();
	}



	KnownSymbols.push_back(NextSymbol);

	{
		deque<size_t> PredictionSequence = GetPredictionSequence((KnownSymbols.size() - 1) + StartOffset);
		Node * CurrentNode = RootNode;
		for(size_t i = 0; i < PredictionSequence.size(); ++i)
		{
			CurrentNode = CurrentNode->Children[PredictionSequence[i]];
			CurrentNode->Frequency += 1;
		}
	}


	if(HistorySize && KnownSymbols.size() > HistorySize)
	{
		KnownSymbols.pop_front();
		++StartOffset;

	}
	*/

}

void ProbabilisticPredictor::InputSequence(deque<size_t> Symbols)
{
	if(Symbols.size() == 0) { return; }
	for(size_t i = 0; i < Symbols.size(); ++i)
	{
		if(Symbols[i] >= Width)
		{
			throw string("Symbol \"") + to_string(Symbols[i]) + string("\" out of width range ") + to_string(Width);
		}
	}
	if(KnownSymbols.size())
	{
		Predict(KnownSymbols.size() + StartOffset + Symbols.size() - 1);

		if(Predictions.size())
		{
			for(size_t i = 0; i < Symbols.size(); ++i)
			{

				bool Hit = false;
				bool Miss = false;
				Miss = !(Hit = (Predictions[i].first == Symbols[i]));
				double Probability = Predictions[i].second;

				deque<size_t> PredictionSequence = GetPredictionSequence(i + KnownSymbols.size() + StartOffset);

				Node * CurrentNode = RootNode;
				for(size_t j = 0; j < PredictionSequence.size(); ++j)
				{
					CurrentNode = CurrentNode->Children[PredictionSequence[j]];
					if(Miss)
					{
						CurrentNode->Miss += Probability;
					}
					else if(Hit)
					{
						CurrentNode->Hit += Probability;
					}
				}
			}
		}
	}
	Predictions.clear();
	for(size_t i = 0; i < Symbols.size(); ++i)
	{


		KnownSymbols.push_back(Symbols[i]);


		deque<size_t> PredictionSequence = GetPredictionSequence((KnownSymbols.size() - 1));
		Node * CurrentNode = RootNode;
		for(size_t j = 0; j < PredictionSequence.size(); ++j)
		{
			CurrentNode = CurrentNode->Children[PredictionSequence[j]];
			CurrentNode->Frequency += 1;
		}


		if(HistorySize && KnownSymbols.size() > HistorySize)
		{
			KnownSymbols.pop_front();
			++StartOffset;

		}
	}

}

size_t ProbabilisticPredictor::ReadSymbol(size_t SequenceNumber)
{
	if(KnownSymbols.size() == 0)
	{
		throw string("Cannot Read from empty predicter!");
	}
	if(SequenceNumber < StartOffset)
	{
		throw string("Invalid Sequence Number ") + to_string(SequenceNumber);
	}
	else if(SequenceNumber - StartOffset < KnownSymbols.size())
	{
		return KnownSymbols[SequenceNumber - StartOffset];
	}
	else if((SequenceNumber - StartOffset) - KnownSymbols.size() < Predictions.size())
	{
		return Predictions[(SequenceNumber - StartOffset) - KnownSymbols.size()].first;
	}
	else
	{
		Predict(SequenceNumber);
		return Predictions[(SequenceNumber - StartOffset) - KnownSymbols.size()].first;
	}
}

double ProbabilisticPredictor::GetSymbolProbability(size_t SequenceNumber)
{

	if(SequenceNumber < StartOffset || SequenceNumber - StartOffset < KnownSymbols.size())
	{
		throw string("Can't predict past values");
	}
	if((SequenceNumber - StartOffset) - KnownSymbols.size() < Predictions.size())
	{
		return Predictions[(SequenceNumber - StartOffset) - KnownSymbols.size()].second;
	}
	else
	{
		Predict(SequenceNumber);
		return Predictions[(SequenceNumber - StartOffset) - KnownSymbols.size()].second;
	}
}

ProbabilisticPredictor::~ProbabilisticPredictor()
{
	delete RootNode;
}


int main()
{
	cout << endl << endl;
	cout << "Creating a ProbabilisticPredictor with height 5 and width 6" << endl;
	ProbabilisticPredictor Predicter1(5, 6);

	try
	{
		cout << "Attempting to read latest known Sequence number from empty Predictor: ";
		cout << Predicter1.LatestKnownSequenceNumber() << endl;

	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	try
	{

		cout << "Attempting to read farthest predicted Sequence number from empty Predictor: ";
		cout << Predicter1.FarthestPredictedSequenceNumber() << endl;


	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	try
	{

		cout << "Attempting prediction on empty predictor: ";
		cout << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber());
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << endl;

	cout << "Inputing: 0" << endl;
	Predicter1.InputNextSymbol(0);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	Predicter1.InputNextSymbol(3);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
//	cout << "Inputing: 4" << endl;
//	Predicter1.InputNextSymbol(4);
//	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	try
	{
		cout << "Inputing: 6" << endl;
		Predicter1.InputNextSymbol(6);
		cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
		cout << "Probability: ";
		try
		{
			cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
		}
		catch(string ex)
		{
			cout << ex << endl;
		}
	}
	catch(string ex)
	{
		cout << ex << endl;
	}


	cout << endl;

	cout << "Inputing: 0" << endl;
	Predicter1.InputNextSymbol(0);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	Predicter1.InputNextSymbol(3);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
//	cout << "Inputing: 4" << endl;
//	Predicter1.InputNextSymbol(4);
//	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	try
	{
		cout << "Inputing: 6" << endl;
		Predicter1.InputNextSymbol(6);
		cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
		cout << "Probability: ";
		try
		{
			cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
		}
		catch(string ex)
		{
			cout << ex << endl;
		}
	}
	catch(string ex)
	{
		cout << ex << endl;
	}

	cout << endl << endl << "Reading symbols both stored and predicted: " << endl;
	for(size_t i = 0; i < 50; ++i)
	{
		cout << endl;
		cout << "Outputing Symbol Number: " << i << endl;
		cout << "Symbol: " << Predicter1.ReadSymbol(i) << endl;
		cout << "Probability: ";
		try

		{
			cout << Predicter1.GetSymbolProbability(i) << endl;
		}
		catch(string ex)
		{
			cout << ex << endl;
		}

	}

	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	Predicter1.InputNextSymbol(3);
	//	cout << "Inputing: 4" << endl;
	//	Predicter1.InputNextSymbol(4);
	//cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.FarthestPredictedSequenceNumber() + 1)<<endl << endl;
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}


	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	Predicter1.InputNextSymbol(3);
	//	cout << "Inputing: 4" << endl;
	//	Predicter1.InputNextSymbol(4);
	//cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.FarthestPredictedSequenceNumber() + 1)<<endl << endl;
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}

	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	Predicter1.InputNextSymbol(3);
	//	cout << "Inputing: 4" << endl;
	//	Predicter1.InputNextSymbol(4);
	//cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.FarthestPredictedSequenceNumber() + 1)<<endl << endl;
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}

	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	Predicter1.InputNextSymbol(3);
	//	cout << "Inputing: 4" << endl;
	//	Predicter1.InputNextSymbol(4);
	//cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.FarthestPredictedSequenceNumber() + 1)<<endl << endl;
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}

	cout << "Inputing: 1" << endl;
	Predicter1.InputNextSymbol(1);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 2" << endl;
	Predicter1.InputNextSymbol(2);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	cout << "Inputing: 3" << endl;
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}
	Predicter1.InputNextSymbol(3);
	//	cout << "Inputing: 4" << endl;
	//	Predicter1.InputNextSymbol(4);
	//cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.FarthestPredictedSequenceNumber() + 1)<<endl << endl;
	cout << "Inputing: 5" << endl;
	Predicter1.InputNextSymbol(5);
	cout << "Next Predicted Symbol: " << Predicter1.ReadSymbol(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	cout << "Probability: ";
	try
	{
		cout << Predicter1.GetSymbolProbability(Predicter1.LatestKnownSequenceNumber() + 1) << endl;
	}
	catch(string ex)
	{
		cout << ex << endl;
	}


	cout << endl << endl << "Reading symbols both stored and predicted: " << endl;
	for(size_t i = 0; i < 50; ++i)
	{
		cout << endl;
		cout << "Outputing Symbol Number: " << i << endl;
		cout << "Symbol: " << Predicter1.ReadSymbol(i) << endl;
		cout << "Probability: ";
		try

		{
			cout << Predicter1.GetSymbolProbability(i) << endl;
		}
		catch(string ex)
		{
			cout << ex << endl;
		}

	}

	cout << endl << endl << "Inserting 4, 3, 2: " << endl;
	deque<size_t> seq;
	seq.push_back(4);
	seq.push_back(3);
	seq.push_back(2);
	Predicter1.InputSequence(seq);

	cout << endl << endl << "Reading symbols both stored and predicted: " << endl;
	for(size_t i = 0; i < 50; ++i)
	{
		cout << endl;
		cout << "Outputing Symbol Number: " << i << endl;
		cout << "Symbol: " << Predicter1.ReadSymbol(i) << endl;
		cout << "Probability: ";
		try

		{
			cout << Predicter1.GetSymbolProbability(i) << endl;
		}
		catch(string ex)
		{
			cout << ex << endl;
		}

	}


	return 0;
}

