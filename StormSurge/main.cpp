#include <iostream>
#include <string>
#include "DataStructures.h"
using namespace std;

int main() {

	DataStructures b;
	b.loadData();
	//b.printAll();
	//cout << endl;
	//b.printSafetyLow();
	//cout << endl;
	//b.printSafetyHigh();
	//cout << endl;
	b.printCasualtiesHigh();
	//b.printSafestCities();
	//b.search("Julia");
	return 0;
}