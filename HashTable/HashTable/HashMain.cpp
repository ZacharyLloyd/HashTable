#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 11
class Record {
public:
	string name;
	string number;
	Record(string initName, string initNumber) {
		name = initName;
		number = initNumber;
	}
};
class HashTable {
public:
	//dynamically create an array
	Record * hashArray[TABLE_SIZE] = { nullptr };
	void insertKey(string inName, string inNumber);
	//void deleteKey(string key);
	int hashFunction(string x);
	void displayHash();
};

int HashTable::hashFunction(string key) {
	int strSum = 0;
	for (unsigned int i = 0; i < key.size(); i++)
		strSum += key[i];
	int index = strSum % TABLE_SIZE;
	if (hashArray[index] != nullptr) 
	{
		//index = index %
	}
	return (strSum % TABLE_SIZE);
}

void HashTable::insertKey(string inName, string inNumber)
{
	int index = hashFunction(inName);
	Record * myRecord = new Record (inName, inNumber);
	if (hashArray[index] != nullptr) 
	{
		hashArray[index] = myRecord;
	}
}
/*
void HashTable::deleteKey(string key)
{
	int index = hashFunction(key);
	hashArray[index] = "";
}
*/
void HashTable::displayHash() {
	for (int i = 0; i < TABLE_SIZE; i++)
		if (hashArray[i] != nullptr)
		{
			cout << i << ": " << hashArray[i]->name << " " << hashArray[i]->number << endl;
		}
		else
			cout << i << ": " << endl;
	cout << endl;
}

int main() {
	HashTable myHash;
	string a[] = { "AB", "CD", "EF", "GH" };

	int phoneNum = 4125967133;

	for (string x : a)
		myHash.insertKey(x, to_string(phoneNum++));
	myHash.displayHash();

	//myHash.deleteKey("EF");
	//myHash.displayHash();

	return 0;
}