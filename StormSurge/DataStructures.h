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
	struct Storm {
		string name;
		int level;
		int casualties;
		string location;
		double safety;
	};

	Storm* minHeapName[25000];
	int minHeapNameIndex;
	unordered_map<string, vector<Storm*>> mapByStorm;
	map<double, vector<string>> mapBySafetyIndex;
	map<int, vector<string>> mapByCasualties;

	void insertminHeapName(Storm* x) {
		minHeapName[minHeapNameIndex] = x;
		int child = minHeapNameIndex++;
		int parent = (child - 1) / 2;
		while (parent >= 0 && minHeapName[parent]->name > minHeapName[child]->name) {
			Storm* y = minHeapName[parent];
			minHeapName[parent] = minHeapName[child];
			minHeapName[child] = y;
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void sortMinHeapName() {
		for (int i = 0; i < 25000; i++) {
			cout << "Storm: " << minHeapName[i]->name << " | Level: " << minHeapName[i]->level << " | Casualties: " << minHeapName[i]->casualties << " | Location: "
				<< minHeapName[i]->location << " | Safety Index: " << fixed << setprecision(2) << minHeapName[i]->safety << endl;
		}
	}

	void tempPrintAll(unordered_map<string, vector<Storm*>> m1) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it.first << " | Level: " << it2->level << " | Casualties: " << it2->casualties << " | Location: " << it2->location << " | Safety Index: " << setprecision(2) << fixed << it2->safety << endl;
			}
		}
	}


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
		for (auto it : m2) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it2 << " | Safety Index: " << setprecision(2) << fixed << it.first << endl;
			}
		}
	}

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

	void printSafety3(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2) {
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
		for (auto it : m2) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it2 << " | Safety Index: " << setprecision(2) << fixed << it.first << endl;
			}
			break;
		}
	}

	void printCasualties(unordered_map<string, vector<Storm*>> m1, map<int, vector<string>> m2) {
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
				cout << "Storm: " << it2->second[i] << " | Casualties: " << setprecision(2) << fixed << it2->first << endl;
			}
		}

	}

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
		minHeapNameIndex = 0;
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
			insertminHeapName(curr);
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

	void printAll() {
		tempPrintAll(mapByStorm);
	}

	void printSafetyLow() {
		printSafety(mapByStorm, mapBySafetyIndex);
	}

	void printSafetyHigh() {
		printSafety2(mapByStorm, mapBySafetyIndex);
	}

	void printSafestCities() {
		printSafety3(mapByStorm, mapBySafetyIndex);
	}

	void printCasualtiesHigh() {
		printCasualties(mapByStorm, mapByCasualties);
	}

	void search(string name) {
		searchByName(mapByStorm, name);
	}
};

