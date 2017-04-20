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

int main() {

	int inputNum = 0;
	vector<int> inputNums;

	//Predictions and Actual Value variables:
	//Prediction values initialized to 1
	double predict100 = 1, predict200 = 1, predict300 = 1, predict400 = 1, predict500 = 1, predict600 = 1, predict700 = 1;
	double actual100, actual200, actual300, actual400, actual500, actual600, actual700;

	//get the name of the file to open
	cout << "Enter the name of the file that you would like to open: " << endl;
	string fileName;
	cin >> fileName;



	//open the file, should be a .txt file
	std::ifstream inFile(fileName);
	if (!inFile) {
		cout << "ERROR: File did not open!" << endl;
		return 1;
	}

	//lol, making it more entertaining
	cout << endl << "Got it! Here's your results!: " << endl << "----------------" << endl;

	//Input entries from file into vector, inputNums<int> 
	//i is the iterator to output the entries, if wanted
	//int i = 0;
	while (inFile) {
		inFile >> inputNum;
		inputNums.push_back(inputNum);
		//optional vector contents output for troubleshooting
		//cout << inputNums[i] << endl;
		//++i;
	}

	//Set actual values of the data:
	actual100 = inputNums[100];
	actual200 = inputNums[200];
	actual300 = inputNums[300];
	actual400 = inputNums[400];
	actual500 = inputNums[500];
	actual600 = inputNums[600];
	actual700 = inputNums[700];

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

	ProbabilisticPredictor SirPredictALot(8, 10);
	vector<int> deltas;

	for(size_t i = 1; i < inputNums.size(); ++i)
	{
		deltas.push_back(inputNums[i] - inputNums[i - 1]);
	}
	vector<size_t> symbols;
	

	//cout the values to see the comparison with percent of error
	cout << "Actual Value: " << actual100 << "     " << "Predicted Value: " << predict100 << "     " << "Percent Error: " << percentError(actual100, predict100) << "%" << endl;
	cout << "Actual Value: " << actual200 << "     " << "Predicted Value: " << predict200 << "     " << "Percent Error: " << percentError(actual200, predict200) << "%" << endl;
	cout << "Actual Value: " << actual300 << "     " << "Predicted Value: " << predict300 << "     " << "Percent Error: " << percentError(actual300, predict300) << "%" << endl;
	cout << "Actual Value: " << actual400 << "     " << "Predicted Value: " << predict400 << "     " << "Percent Error: " << percentError(actual400, predict400) << "%" << endl;
	cout << "Actual Value: " << actual500 << "     " << "Predicted Value: " << predict500 << "     " << "Percent Error: " << percentError(actual500, predict500) << "%" << endl;
	cout << "Actual Value: " << actual600 << "     " << "Predicted Value: " << predict600 << "     " << "Percent Error: " << percentError(actual600, predict600) << "%" << endl;
	cout << "Actual Value: " << actual700 << "     " << "Predicted Value: " << predict700 << "     " << "Percent Error: " << percentError(actual700, predict700) << "%" << endl;
	cout << endl;
	inFile.close();
	return 0;
}

double percentError(double actual, double predicted) {
	double result = 0.0;
	result = (predicted - actual) / predicted;

	return result;
}