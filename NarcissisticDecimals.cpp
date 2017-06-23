/*
 * File: NarcissticDecimals.cpp
 * The code lists out Narcisstic decimals. A Narcissistic decimal number is a non-negative integer, n, 
 * that is equal to the sum of the m-th powers of each of the digits in the decimal representation of n,
 * where m is the number of digits in the decimal representation of n.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checkNarcissism(int wannabeNar);
void populateNarcissticList(int limit);

int main() {

	// int wannabeNar;
	// cout << "Please enter a number" << endl;
	// cin >> wannabeNar;

	// if (checkNarcissism(wannabeNar))
	// 	cout << "The number is narsisstic" << endl;
	// else 
	// 	cout << "The number isn't narsisstic" << endl;

	int limit;
	cout << "How many Narcisstic decimals do you want?" << endl;
	cin >> limit;
	cout << "Here are the first " << limit << " Narcisstic decimals: " << endl;
	populateNarcissticList(limit);

	return 0;
}

bool checkNarcissism(int wannabeNar) {
	int checker = wannabeNar;
	int sum = 0;

	vector<int> num;
	while (checker/10 != 0) {
		num.push_back(checker%10);
		checker /= 10;
	}
	num.push_back(checker%10);
	checker /= 10;

	int m = num.size();

	for(unsigned i = 0; i < m; ++i) {
		sum += pow(num[i], m);
	}

	if(sum == wannabeNar) {
		return true;
	}

	return false;
}

void populateNarcissticList(int limit) {
	int counter = 0;
	int num = 0;

	while(true) {
	    if(counter == limit) {
	    	cout << endl;
	    	break;
	    }
	    if (checkNarcissism(num)) {
	    	++counter;
	    	cout << num << "  ";
	    }
	    ++num;
	}

}
