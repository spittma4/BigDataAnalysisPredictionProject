/*
Big Data Analytics, Probabilistic Prediction Project
Algorithm Example Program to be run on a dataset
	Currently set up to run on a CSV file of 3 years worth of Google's closing stock prices
		"Google 3 Year no dates.csv"

Written by:
-------
Samuel Pittman
Michael Caprile

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../../probabilisticPrediction/Probabilistic Prediction Tree/ProbabilisticPredictor.h"
using namespace std;

double percentError(double, double);

int main()
{

	int inputNum = 0;
	vector<int> inputNums;

	//Predictions and Actual Value variables:
	//Prediction values initialized to 1
	//double predict100 = 1, predict200 = 1, predict300 = 1, predict400 = 1, predict500 = 1, predict600 = 1, predict700 = 1;
	//double actual100, actual200, actual300, actual400, actual500, actual600, actual700;

	//get the name of the file to open
	cout << "Enter the name of the file that you would like to open: " << endl;
	string fileName;
	cin >> fileName;



	//open the file, should be a .txt file
	std::ifstream inFile(fileName);
	if(!inFile)
	{
		cout << "ERROR: File did not open!" << endl;
		return 1;
	}

	//lol, making it more entertaining
	cout << endl << "Got it! Here's your results!: " << endl << "----------------" << endl;

	//Input entries from file into vector, inputNums<int> 
	//i is the iterator to output the entries, if wanted
	//int i = 0;
	while(inFile)
	{
		inFile >> inputNum;
		inputNums.push_back(inputNum);
		//optional vector contents output for troubleshooting
		//cout << inputNums[i] << endl;
		//++i;
	}

	//Set actual values of the data:
	/*actual100 = inputNums[100];
	actual200 = inputNums[200];
	actual300 = inputNums[300];
	actual400 = inputNums[400];
	actual500 = inputNums[500];
	actual600 = inputNums[600];
	actual700 = inputNums[700];*/

	//set the values of predicted values 
	//DO MAGIC HERE MICHAEL
	/*
	predict100 =
	predict200 =
	predict300 =
	predict400 =
	predict500 =
	predict600 =
	predict700 =
	*/

	ProbabilisticPredictor SirPredictALot(5, 11);
	vector<int> Deltas;

	for(size_t i = 1; i < inputNums.size(); ++i)
	{
		Deltas.push_back(inputNums[i] - inputNums[i - 1]);
	}

	//symbol translations
	//   <=  -9  :  0
	// -8 to -7  :  1
	// -6 to -5  :  2
	// -4 to -3  :  3
	// -2 to -1  :  4
	//    0      :  5
	//  1 to  2  :  6
	//  3 to  4  :  7
	//  5 to  6  :  8
	//  7 to  8  :  9
	//  >= 9     : 10


	vector<size_t> Symbols;
	for(size_t i = 0; i < Deltas.size(); ++i)
	{
		int CurrentDelta = Deltas[i];//this will help speed sligtly;
		if(CurrentDelta <= -9) { SirPredictALot.InputNextSymbol(0); }
		else if(CurrentDelta == -8 || CurrentDelta == -7) { SirPredictALot.InputNextSymbol(1); }
		else if(CurrentDelta == -6 || CurrentDelta == -5) { SirPredictALot.InputNextSymbol(2); }
		else if(CurrentDelta == -4 || CurrentDelta == -3) { SirPredictALot.InputNextSymbol(3); }
		else if(CurrentDelta == -2 || CurrentDelta == -1) { SirPredictALot.InputNextSymbol(4); }
		else if(CurrentDelta == 0) { SirPredictALot.InputNextSymbol(5); }
		else if(CurrentDelta == 1 || CurrentDelta == 2) { SirPredictALot.InputNextSymbol(6); }
		else if(CurrentDelta == 3 || CurrentDelta == 4) { SirPredictALot.InputNextSymbol(7); }
		else if(CurrentDelta == 5 || CurrentDelta == 6) { SirPredictALot.InputNextSymbol(8); }
		else if(CurrentDelta == 7 || CurrentDelta == 8) { SirPredictALot.InputNextSymbol(9); }
		else if(CurrentDelta >= 9) { SirPredictALot.InputNextSymbol(10); }

		if(i >= 100 && i + 2 < inputNums.size())
		{
			size_t PredictedSymbol = SirPredictALot.ReadSymbol(i + 1);

			int PredictedDelta;
			//reverse symbolization and apply delta
			switch(PredictedSymbol)
			{
			case 0:
				PredictedDelta = -10;
				break;
			case 1:
				PredictedDelta = -8;
				break;
			case 2:
				PredictedDelta = -6;
				break;
			case 3:
				PredictedDelta = -4;
				break;
			case 4:
				PredictedDelta = -2;
				break;
			case 5:
				PredictedDelta = 0;
				break;
			case 6:
				PredictedDelta = 2;
				break;
			case 7:
				PredictedDelta = 4;
				break;
			case 8:
				PredictedDelta = 6;
				break;
			case 9:
				PredictedDelta = 8;
				break;
			case 10:
				PredictedDelta = 10;
				break;
			default:
				break;
			}
			int PredictedValue = inputNums[i + 1] + PredictedDelta;

			cout << "Actual Delta: " << Deltas[i + 1] << "\t\t" << "Predicted Delta: " << PredictedDelta << "\t\t" /*<< "Percent Error: " << percentError(Deltas[i + 1], PredictedDelta)<< "%"*/ << endl;

			cout << "Actual Value: " << inputNums[i + 2] << "\t\t" << "Predicted Value: " << PredictedValue << "\t\t" << "Percent Error: " << percentError(inputNums[i + 2], PredictedValue) << "%" << endl << endl;

		}

	}


	//cout the values to see the comparison with percent of error
	/*cout << "Actual Value: " << actual100 << "     " << "Predicted Value: " << predict100 << "     " << "Percent Error: " << percentError(actual100, predict100) << "%" << endl;
	cout << "Actual Value: " << actual200 << "     " << "Predicted Value: " << predict200 << "     " << "Percent Error: " << percentError(actual200, predict200) << "%" << endl;
	cout << "Actual Value: " << actual300 << "     " << "Predicted Value: " << predict300 << "     " << "Percent Error: " << percentError(actual300, predict300) << "%" << endl;
	cout << "Actual Value: " << actual400 << "     " << "Predicted Value: " << predict400 << "     " << "Percent Error: " << percentError(actual400, predict400) << "%" << endl;
	cout << "Actual Value: " << actual500 << "     " << "Predicted Value: " << predict500 << "     " << "Percent Error: " << percentError(actual500, predict500) << "%" << endl;
	cout << "Actual Value: " << actual600 << "     " << "Predicted Value: " << predict600 << "     " << "Percent Error: " << percentError(actual600, predict600) << "%" << endl;
	cout << "Actual Value: " << actual700 << "     " << "Predicted Value: " << predict700 << "     " << "Percent Error: " << percentError(actual700, predict700) << "%" << endl;
	cout << endl;
	*/


	inFile.close();
	return 0;
}

double percentError(double actual, double predicted)
{
	if(predicted == actual) { return 0; }
	double result = 0.0;
	result = (predicted - actual) / predicted;

	return result;
}