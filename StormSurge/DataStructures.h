//https://cplusplus.com/reference/map/map/
//https://cplusplus.com/reference/unordered_map/unordered_map/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

class DataStructures {
	//creates struct storm with its data
	struct Storm {
		string name;
		int level;
		int casualties;
		string location;
		double safety;
	};

	//creates necessary maps to store the storm's data
	unordered_map<string, vector<Storm*>> mapByStorm;
	map<string, double> mapBySafestCities;
	map<double, string> mapBySafestCities2;
	map<double, vector<string>> mapBySafetyIndex;
	map<int, vector<string>> mapByCasualties;

	
	//goes through the unordered map of the storms and prints all their data
	void tempPrintAll(unordered_map<string, vector<Storm*>> m1) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it.first << " | Level: " << it2->level << " | Casualties: " << it2->casualties << " | Location: " << it2->location << " | Safety Index: " << setprecision(2) << fixed << it2->safety << endl;
			}
		}
	}

	//goes through all of the storms and inserts them into the m2 which holds the safety index as its key and the vector of storm names as the key
	void printSafety(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<double, vector<string>>::iterator it3;
				it3 = m2.find(it2->safety);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->safety, v));
					m2[it2->safety].push_back(it.first);
				}
				else {
					m2[it2->safety].push_back(it.first);
				}
				
			}
		}
		//it goes through m2 and prints all the data from lowest to highest
		for (auto it : m2) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it2 << " | Safety Index: " << setprecision(2) << fixed << it.first << endl;
			}
		}
	}

	//does the same as above but prints all the data from highest to lowest
	void printSafety2(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<double, vector<string>>::iterator it3;
				it3 = m2.find(it2->safety);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->safety, v));
					m2[it2->safety].push_back(it.first);
				}
				else {
					m2[it2->safety].push_back(it.first);
				}

			}
		}
		
		map<double, vector<string>>::reverse_iterator it2;
		for (it2 = m2.rbegin(); it2 != m2.rend(); it2++) {
			for (int i = it2->second.size() - 1; i >= 0; i--) {
				cout << "Storm: " << it2->second[i] << " | Safety Index: " << setprecision(2) << fixed << it2->first << endl;
			}
		}

	}

	//goes through the unordered map with storms and stores the safety index of each storm that happened at a specific location
	void printSafety3(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2, map<string, double> m3, map<double, string> m4) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<double, vector<string>>::iterator it3;
				it3 = m2.find(it2->safety);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->safety, v));
					m2[it2->safety].push_back(it2->location);
				}
				else {
					m2[it2->safety].push_back(it2->location);
				}

			}
		}
		//it then calculates the total safety index of every location where a storm occured and stores it in m3
		for (auto it : m2) {
			for (auto it2 : it.second) {
				map<string, double>::iterator it3;
				it3 = m3.find(it2);
				if (it3 == m3.end()) {
					m3.insert(pair<string, double>(it2, it.first));
				}
				else {
					m3[it2] += it.first;
				}
			}
		}
		//it then stores this into m4 as we are looking to sort this from lowest to highest
		for (auto it : m3) {
			m4.insert(pair<double, string>(it.second, it.first));
		}
		
		//it then prints out the city with the lowest safety index and then the city with the highest
		map<double, string>::iterator it2;
		it2 = m4.begin();
		cout << "The safest city is " << it2->second << " with a cumulative safety index of " << it2->first << endl;
		map<double, string>::reverse_iterator it3;
		it3 = m4.rbegin();
		cout << "The most dangerous city is " << it3->second << " with a cumulative safety index of " << it3->first << endl;
	}

	//prints the storms with the highest casualties
	void printCasualties(unordered_map<string, vector<Storm*>> m1, map<int, vector<string>> m2) {
		//does the same as the print safety functions except with casualties
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<int, vector<string>>::iterator it3;
				it3 = m2.find(it2->casualties);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->casualties, v));
					m2[it2->casualties].push_back(it.first);
				}
				else {
					m2[it2->casualties].push_back(it.first);
				}

			}
		}

		map<int, vector<string>>::reverse_iterator it2;
		for (it2 = m2.rbegin(); it2 != m2.rend(); it2++) {
			for (int i = it2->second.size() - 1; i >= 0; i--) {
				if (it2->first == 300) {
					cout << "Storm: " << it2->second[i] << " | Casualties: " << setprecision(2) << fixed << it2->first << endl;
				}
			}
		}

	}

	//is a search function and searches the name of the storm and prints all the storms with said name and their data
	void searchByName(unordered_map<string, vector<Storm*>> m1, string name) {
		unordered_map<string, vector<Storm*>>::iterator it;
		it = m1.find(name);
		if (it != m1.end()) {
			cout << "The storms with name " << name << " are:" << endl;
			for (int i = 0; i < m1[name].size(); i++) {
				cout << "Storm: " << name << " | Level: " << m1[name][i]->level << " | Casualties: " << m1[name][i]->casualties << " | Location: " << m1[name][i]->location << " | Safety Index: " << setprecision(2) << fixed << m1[name][i]->safety << endl;
			}
		}
		else {
			cout << "Sorry, no storm exists with the name " << name << "." << endl;
		}
	}
	


public:
	void loadData() {
		vector<Storm*> v;
		ifstream i;
		i.open("StormData.csv");
		string temp;
		getline(i, temp, ',');
		getline(i, temp, ',');
		getline(i, temp, ',');
		getline(i, temp, '\n');
		int count = 1;
		while (getline(i, temp, ',')) {
			Storm* curr = new Storm();
			curr->name = temp;
			getline(i, temp, ',');
			curr->level = stoi(temp);
			getline(i, temp, ',');
			curr->casualties = stoi(temp);
			getline(i, temp, '\n');
			curr->location = temp;
			curr->safety = (curr->level * curr->casualties) / 30.0;
			//insert into Heaps and Graph here
			
			unordered_map<string, vector<Storm*>>::iterator it;
			it = mapByStorm.find(curr->name);
			if (it == mapByStorm.end()) {
				mapByStorm.insert(pair<string, vector<Storm*>>(curr->name, v));
				mapByStorm[curr->name].push_back(curr);
			}
			else {
				mapByStorm[curr->name].push_back(curr);
			}
			
		}
		
	}

	//prints all storms
	void printAll() {
		tempPrintAll(mapByStorm);
	}

	//prints all storms sorted by lowest to highest safety index
	void printSafetyLow() {
		printSafety(mapByStorm, mapBySafetyIndex);
	}

	//prints all storms sorted by highest to lowest safety index
	void printSafetyHigh() {
		printSafety2(mapByStorm, mapBySafetyIndex);
	}

	//prints the safest cities (the cities with the lowest safety index)
	void printSafestCities() {
		printSafety3(mapByStorm, mapBySafetyIndex, mapBySafestCities, mapBySafestCities2);
	}

	//prints the casualties of each storm from highest to low
	void printCasualtiesHigh() {
		printCasualties(mapByStorm, mapByCasualties);
	}

	//search function that searches and prints storms with a certain name
	void search(string name) {
		searchByName(mapByStorm, name);
	}
};

