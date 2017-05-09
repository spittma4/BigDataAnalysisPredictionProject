//#pragma once


#include <deque>
#include <utility>

#include <string>
using std::string;
using std::to_string;
using std::pair;
using std::deque;
#include "Node.h"

class ProbabilisticPredictor
{
	deque<size_t> KnownSymbols;
	deque<pair<size_t, double>> Predictions;

	size_t Height;
	size_t Width;


	size_t StartOffset;

	size_t HistorySize;

	Node * RootNode;




	ProbabilisticPredictor() = delete;

	//todo: Undelete and Add copy contructors and operator=; move to public when done
	ProbabilisticPredictor(const ProbabilisticPredictor&) = delete;
	ProbabilisticPredictor& operator=(const ProbabilisticPredictor&) = delete;

	/// dont read too far into future, that is bad
	deque<size_t> GetPredictionSequence(size_t SquenceNumber);

	/// dont read too far into future, that is bad
	void Predict(size_t SequenceNumber);



public:



	ProbabilisticPredictor(size_t Height, size_t Width, size_t HistorySize = 0, size_t StartOffset = 0);

	///You can't give it symbols out of order
	void InputNextSymbol(size_t NextSymbol);
	void InputSequence(deque<size_t> Symbols);

	/// dont read too far into future, that is bad
	size_t ReadSymbol(size_t SequenceNumber);

	/// dont read too far into future, that is bad
	double GetSymbolProbability(size_t SequenceNumber);

	size_t LatestKnownSequenceNumber() { return KnownSymbols.size() ? StartOffset + KnownSymbols.size() - 1 : StartOffset; }
	//size_t FarthestPredictedSequenceNumber() { return StartOffset + KnownSymbols.size() + Predictions.size() >= 2 ? StartOffset + KnownSymbols.size() + Predictions.size() - 2 : 0; }
	size_t FarthestPredictedSequenceNumber() { return Predictions.size() ? LatestKnownSequenceNumber() + Predictions.size() - 1 : LatestKnownSequenceNumber(); }

	~ProbabilisticPredictor();
};

//prob = freq * hit / (hit + miss)


