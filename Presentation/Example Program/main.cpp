/*
Big Data Analytics, Probabilistic Prediction Project
Algorithm Example Program to be run on a dataset
	Currently set up to run on a CSV file of 3 years worth of Google's closing stock prices
		"Google 3 Year no dates.csv"

Written by:
-------
Samuel Pittman
Michael Capriles

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "../../probabilisticPrediction/Probabilistic Prediction Tree/ProbabilisticPredictor.h"
using namespace std;

double percentError(double, double);

size_t GenerateSymbol(int Input)
{
	if(Input <= -21) { return (0); }
	else if(Input <= -16) { return (1); }
	else if(Input <= -11) { return (2); }
	else if(Input <= -6) { return (3); }
	else if(Input <= -1) { return (4); }
	else if(Input <= 4) { return (5); }
	else if(Input <= 9) { return (6); }
	else if(Input <= 14) { return (7); }
	else if(Input <= 19) { return (8); }
	else if(Input <= 24) { return (9); }
	else if(Input >= 25) { return (10); }
	return 0;
}


int main()
{
	size_t TreeWidth = 11;
	size_t TreeHeight = 7;

	//double TotalDeltaPercentError = 0;
	double TotalControlError = 0; //This just guesses the last value
	double TotalErrorRating = 0;
	//double TotalPercentError = 0;
	double TotalConfidence = 0;
	size_t ItemsErrorChecked = 0;

	double inputNum = 0;
	vector<int> inputNums;

	//Predictions and Actual Value variables:
	//Prediction values initialized to 1
	//double predict100 = 1, predict200 = 1, predict300 = 1, predict400 = 1, predict500 = 1, predict600 = 1, predict700 = 1;
	//double actual100, actual200, actual300, actual400, actual500, actual600, actual700;

	string fileName = "";
	{
		cout << "Open 'WeatherDataCleaned'? (y/n)" << endl;
		string Resp = "";
		cin >> Resp;
		if(Resp[0]=='y'||Resp[0]=='Y')
		{
		fileName = "WeatherDataCleaned";
		}
		else
		{
			//get the name of the file to open
			cout << "Enter the name of the file that you would like to open: " << endl;
			cin >> fileName;
		}

	}

	//open the file, should be a .txt file
	std::ifstream inFile(fileName);
	if(!inFile)
	{
		cout << "ERROR: File did not open!" << endl;
		return 1;
	}

	//lol, making it more entertaining
	cout << "File Opened!" << endl;
	//cout << endl << "Got it! Here's your results!: " << endl << "----------------" << endl;

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
	inFile.close();

	cout << "Data Read!" << endl << endl;

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

	cout << "Starting Predictor Creation!" << endl;
	ProbabilisticPredictor SirPredictALot(TreeHeight, TreeWidth);

	cout << "Predictor Creation Finished!" << endl << endl;


	//symbol translations
	//    X   <= -21 :   0
	//  -20   to -16 :   1
	//  -15   to -11 :   2
	//  -10   to  -6 :   3
	//   -5   to  -1 :   4
	//    0   to   4 :   5
	//    5   to   9 :   6
	//   10   to  14 :   7
	//   15   to  19 :   8
	//   20   to  24 :   9
	//   25   <=   X :  10


	size_t YearsToInput = 10;
	for(size_t Year = 0; Year < YearsToInput; ++Year)
	{

		cout << "Started Inputting Pass: " << Year + 1 << endl;
		for(size_t i = 0; i < inputNums.size(); ++i)
		{
			//int CurrentValue = inputNums[i];//this will help speed sligtly;
			//if(CurrentValue <= -21) { SirPredictALot.InputNextSymbol(0); }
			//else if(CurrentValue <= -16) { SirPredictALot.InputNextSymbol(1); }
			//else if(CurrentValue <= -11) { SirPredictALot.InputNextSymbol(2); }
			//else if(CurrentValue <= -6) { SirPredictALot.InputNextSymbol(3); }
			//else if(CurrentValue <= -1) { SirPredictALot.InputNextSymbol(4); }
			//else if(CurrentValue <= 4) { SirPredictALot.InputNextSymbol(5); }
			//else if(CurrentValue <= 9) { SirPredictALot.InputNextSymbol(6); }
			//else if(CurrentValue <= 14) { SirPredictALot.InputNextSymbol(7); }
			//else if(CurrentValue <= 19) { SirPredictALot.InputNextSymbol(8); }
			//else if(CurrentValue <= 24) { SirPredictALot.InputNextSymbol(9); }
			//else if(CurrentValue >= 25) { SirPredictALot.InputNextSymbol(10); }

			SirPredictALot.InputNextSymbol(GenerateSymbol(inputNums[i]));
			size_t NextSquenceNumber = i + 1 + (Year * inputNums.size());
			size_t PredictedSymbol = SirPredictALot.ReadSymbol(NextSquenceNumber);
			double Confidence = SirPredictALot.GetSymbolProbability(NextSquenceNumber);

			if(i + 1 < inputNums.size() && Year == YearsToInput - 1)
			{


				//int PredictedValue;
				////reverse symbolization
				//switch(PredictedSymbol)
				//{
				//case 0:
				//	PredictedValue = -25;
				//	break;
				//case 1:
				//	PredictedValue = -20;
				//	break;
				//case 2:
				//	PredictedValue = -15;
				//	break;
				//case 3:
				//	PredictedValue = -10;
				//	break;
				//case 4:
				//	PredictedValue = -5;
				//	break;
				//case 5:
				//	PredictedValue = 0;
				//	break;
				//case 6:
				//	PredictedValue = 5;
				//	break;
				//case 7:
				//	PredictedValue = 10;
				//	break;
				//case 8:
				//	PredictedValue = 15;
				//	break;
				//case 9:
				//	PredictedValue = 20;
				//	break;
				//case 10:
				//	PredictedValue = 25;
				//	break;
				//default:
				//	break;
				//}





				//double DeltaPercentError = abs(100 * (((double)Deltas[i + 1]) - ((double)PredictedValue)) / 20);

				//double ErrorRating =  abs(100 * (((double)inputNums[i + 1]) - ((double)PredictedValue)) /55);
				size_t ActualNextSymbol = GenerateSymbol(inputNums[i + 1]);
				double ErrorRating = abs(100 * (((double)ActualNextSymbol) - ((double)PredictedSymbol)) / 11);
				double ControlError = abs(100 * (((double)ActualNextSymbol) - ((double)GenerateSymbol(inputNums[i]))) / 11);



				//cout << "Actual Value: " << inputNums[i + 1] << "\t\t" << "Predicted Value: " << PredictedValue << "\t\t" << endl; //<< "Percent Error: " << percentError(inputNums[i + 1], PredictedValue) << "%" << endl;
				cout << "Actual Symbol: " << ActualNextSymbol << "\t\t" << "Predicted Symbol: " << PredictedSymbol << "\t\t" << endl; //<< "Percent Error: " << percentError(inputNums[i + 1], PredictedValue) << "%" << endl;
				cout << "Error Rating: " << ErrorRating << "%" << "\t\t" << "Control Error: " << ControlError << "%" << endl;
				cout << "Confidence: " << Confidence << endl << endl;
				//TotalDeltaPercentError += DeltaPercentError;
				//TotalPercentError += percentError(GenerateSymbol(inputNums[i + 1]), GenerateSymbol(PredictedValue));

				//TotalControlError += percentError(GenerateSymbol(inputNums[i + 1]), GenerateSymbol(inputNums[i]));
				TotalControlError += ControlError;
				TotalErrorRating += ErrorRating;
				TotalConfidence += Confidence;


				++ItemsErrorChecked;
			}

		}

		cout << "Finished Inputting Pass: " << Year + 1 << endl << endl;
	}

	//vector<int> Deltas;
	//for(size_t i = 1; i < inputNums.size(); ++i)
	//{
	//	Deltas.push_back(inputNums[i] - inputNums[i - 1]);
	//}

	////symbol translations
	////   <=  -9  :  0
	//// -8 to -7  :  1
	//// -6 to -5  :  2
	//// -4 to -3  :  3
	//// -2 to -1  :  4
	////    0      :  5
	////  1 to  2  :  6
	////  3 to  4  :  7
	////  5 to  6  :  8
	////  7 to  8  :  9
	////  >= 9     : 10


	//vector<size_t> Symbols;
	//for(size_t i = 0; i < Deltas.size(); ++i)
	//{
	//	int CurrentDelta = Deltas[i];//this will help speed sligtly;
	//	if(CurrentDelta <= -9) { SirPredictALot.InputNextSymbol(0); }
	//	else if(CurrentDelta == -8 || CurrentDelta == -7) { SirPredictALot.InputNextSymbol(1); }
	//	else if(CurrentDelta == -6 || CurrentDelta == -5) { SirPredictALot.InputNextSymbol(2); }
	//	else if(CurrentDelta == -4 || CurrentDelta == -3) { SirPredictALot.InputNextSymbol(3); }
	//	else if(CurrentDelta == -2 || CurrentDelta == -1) { SirPredictALot.InputNextSymbol(4); }
	//	else if(CurrentDelta == 0) { SirPredictALot.InputNextSymbol(5); }
	//	else if(CurrentDelta == 1 || CurrentDelta == 2) { SirPredictALot.InputNextSymbol(6); }
	//	else if(CurrentDelta == 3 || CurrentDelta == 4) { SirPredictALot.InputNextSymbol(7); }
	//	else if(CurrentDelta == 5 || CurrentDelta == 6) { SirPredictALot.InputNextSymbol(8); }
	//	else if(CurrentDelta == 7 || CurrentDelta == 8) { SirPredictALot.InputNextSymbol(9); }
	//	else if(CurrentDelta >= 9) { SirPredictALot.InputNextSymbol(10); }

	//	if(i >= 100 && i + 2 < inputNums.size())
	//	{
	//		size_t PredictedSymbol = SirPredictALot.ReadSymbol(i + 1);

	//		int PredictedDelta;
	//		//reverse symbolization and apply delta
	//		switch(PredictedSymbol)
	//		{
	//		case 0:
	//			PredictedDelta = -10;
	//			break;
	//		case 1:
	//			PredictedDelta = -8;
	//			break;
	//		case 2:
	//			PredictedDelta = -6;
	//			break;
	//		case 3:
	//			PredictedDelta = -4;
	//			break;
	//		case 4:
	//			PredictedDelta = -2;
	//			break;
	//		case 5:
	//			PredictedDelta = 0;
	//			break;
	//		case 6:
	//			PredictedDelta = 2;
	//			break;
	//		case 7:
	//			PredictedDelta = 4;
	//			break;
	//		case 8:
	//			PredictedDelta = 6;
	//			break;
	//		case 9:
	//			PredictedDelta = 8;
	//			break;
	//		case 10:
	//			PredictedDelta = 10;
	//			break;
	//		default:
	//			break;
	//		}
	//		int PredictedValue = inputNums[i + 1] + PredictedDelta;


	//		//test against zero prediction
	//		//PredictedDelta = 0;

	//		double DeltaPercentError = abs(100 * (((double)Deltas[i + 1]) - ((double)PredictedDelta)) / 20);




	//		cout << "Actual Delta: " << Deltas[i + 1] << "\t\t" << "Predicted Delta: " << PredictedDelta << "\t\t" << "Percent Error: " << DeltaPercentError << "%" << endl;

	//		cout << "Actual Value: " << inputNums[i + 2] << "\t\t" << "Predicted Value: " << PredictedValue << "\t\t" << "Percent Error: " << percentError(inputNums[i + 2], PredictedValue) << "%" << endl << endl;

	//		TotalDeltaPercentError += DeltaPercentError;
	//		TotalPercentError += percentError(inputNums[i + 2], PredictedValue);
	//		++ItemsErrorChecked;
	//	}

	//}


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
	//cout << "Average Error in Delta: " << TotalDeltaPercentError / ((double)ItemsErrorChecked) << "%" << endl << endl;

	cout << "////Results://///////////////////////////////////////////////////////////////" << endl;
	cout << "//                        File: \t" << fileName << endl;
	cout << "//                 Tree Height: \t" << TreeHeight << endl;
	cout << "//                  Tree Width: \t" << TreeWidth << endl;
	cout << "//        Estimated Node Count: \t" << pow(TreeWidth, TreeHeight) << endl;
	cout << "//        Average Error Rating: \t" << TotalErrorRating / ((double)ItemsErrorChecked) << "%" << endl;
	//cout << "//Average Error: " << TotalPercentError / ((double)ItemsErrorChecked) << "%" << endl << endl;
	cout << "//Average Control Error Rating: \t" << TotalControlError / ((double)ItemsErrorChecked) << "%" << endl;
	cout << "//          Average Confidence: \t" << TotalConfidence / ((double)ItemsErrorChecked) << endl;
	cout << "//          Improvement Factor: \t" << TotalControlError / TotalErrorRating << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////" << endl << endl;

	//cout << "The average error in delta is the important statistic, it being less than 50% show a significant improvement over pure chance!" << endl << endl;

	/*{
		//open the file, should be a .txt file
		std::ofstream OutFile("PredictionOutput.txt");
		if(!OutFile)
		{
			cout << "ERROR: File did not open!" << endl;
			return 1;
		}


		//Input entries from file into vector, inputNums<int>
		//i is the iterator to output the entries, if wanted
		//int i = 0;
		//while(inFile)
		//{
		//	inFile >> inputNum;
		//	inputNums.push_back(inputNum);
		//	//optional vector contents output for troubleshooting
		//	//cout << inputNums[i] << endl;
		//	//++i;
		//}

		for(size_t i = 0; i < inputNums.size(); ++i)
		{
			OutFile << SirPredictALot.ReadSymbol(SirPredictALot.LatestKnownSequenceNumber() + i + 1) << endl;
		}
		OutFile.close();


	}*/

	return 0;
}

double percentError(double actual, double predicted)
{
	if(predicted == actual) { return 0; }
	double result = 0.0;
	result = abs(100 * (predicted - actual) / max(abs(predicted), abs(actual)));

	return result;
}