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
	void searchKey(string inName);
	int hashFunction(string x);
	void displayHash();
};

int HashTable::hashFunction(string key) {
	int strSum = 0;
	//increment variable based on data in key
	for (unsigned int i = 0; i < key.size(); i++)
		strSum += key[i];
	//First hash
	int index = strSum % TABLE_SIZE;
	//Double hash if collison is detected
	if (hashArray[index] != nullptr) 
	{
		//Hash again
		strSum = 7 % index;
	}
	//return position
	return (strSum % TABLE_SIZE);
}

void HashTable::insertKey(string inName, string inNumber)
{
	//hash the name
	int index = hashFunction(inName);
	//create new record to store data
	Record * myRecord = new Record (inName, inNumber);
	//Put data in array
	if (hashArray[index] == nullptr) 
	{
		hashArray[index] = myRecord;
	}
}
// function to search key in hash table 
void HashTable::searchKey(string inName)
{
	int location = hashFunction(inName);
	bool foundKey{};
	string name;

	Record* ptr = hashArray[location];
	while (ptr != NULL)
	{
		foundKey = true;
		if (ptr->name == inName)
		{
			foundKey = true;
			name = ptr->name;
		}
	}

	if (foundKey == true)
	{
		std::cout << " Name belonging to the number is: " << name << std::endl;
	}
	else
	{
		foundKey = false;
		std::cout << " No number exist with that ID" << std::endl;
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
	//Cycle through the array to display the name and the number that are linked together
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
	string a[] = { "Zack", "Tyler", "Erick", "Ryan", "Mike" };

	int phoneNum = 5967133;

	for (string x : a)
		myHash.insertKey(x, to_string(phoneNum++));
	myHash.displayHash();
	myHash.searchKey("Zack");
	myHash.searchKey("Brad");

	return 0;
}