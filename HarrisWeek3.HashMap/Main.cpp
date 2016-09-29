#include <iostream>
#include <string>

#include "MyHashMap.h"

using namespace std;

int main()
{
	MyHashMap<string, string> hashMap(15);
	hashMap.Insert("John Doe", "111-355-0000");
	hashMap.Insert("Jane Doe", "111-500-5544");
	hashMap.Insert("Bob Smith", "111-555-0000");

	cout << "John Doe's Phone Number:\t" << *hashMap.GetValueForKey("John Doe") << "\n";
	cout << "Jane Doe's Phone Number:\t" << *hashMap.GetValueForKey("Jane Doe") << "\n";
	cout << "Bob Smith's Phone Number:\t" << *hashMap.GetValueForKey("Bob Smith") << "\n";

	const string* value = hashMap.GetValueForKey("Invalid");

	if (!value)
	{
		cout << "No value found for the key provided.\n";
	}

	cout << "\n\n";
	system("pause");
	return 0;
}
