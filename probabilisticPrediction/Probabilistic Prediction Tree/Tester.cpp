#include "ProbabilisticPredictor.h"

#include <iostream>
using std::cout;
using std::endl;


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
	cout << endl;
	cout << endl;
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
	cout << endl;
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
	cout << endl;
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
	cout << endl;
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

	cout << endl;
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

