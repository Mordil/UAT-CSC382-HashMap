#pragma once

#define TABLE_SIZE 10

#include <functional>

#include "MyHashNode.h"

template <typename K>
struct KeyHash {
	unsigned long operator ()(const K& key) const
	{
		std::hash<K> hasher;
		return hasher(key) % TABLE_SIZE;
	}
};

template<typename K, typename V, typename F = KeyHash<K>>
class MyHashMap
{
	typedef MyHashNode<K, V> Node;

public:
	/* Initializes a HashMap with the initial size provided. */
	MyHashMap(const int initialSize = TABLE_SIZE) { _table = new Node* [initialSize](); }

	~MyHashMap() { }

	void Insert(const K& key, const V& value)
	{
		unsigned long hashValue = _hashFunction(key);
		Node* previous = NULL;
		Node* entry = _table[hashValue];

		// loop through so that "entry" points to the last linked list item with this hash
		// and previous links to any previous linked list item with the same hash
		while (entry != NULL && entry->GetKey() != key)
		{
			previous = entry;
			entry = entry->GetNextNode();
		}

		// if there is no entry with that hash && key
		if (entry == NULL)
		{
			// create the entry
			entry = new Node(key, value);

			// if this is the only entry with that hash
			if (previous == NULL)
			{
				// insert as the first item with this hash
				_table[hashValue] = entry;
			}
			else
			{
				// attach this node as a linked item to the previous
				previous->SetNext(entry);
			}
		}
		else
		{
			// just update the value
			entry->SetValue(value);
		}
	}

	const V* const GetValueForKey(const K& key)
	{
		// pointer to return
		const V* valuePtr = NULL;

		// hash the key
		unsigned long hashValue = _hashFunction(key);
		// create a pointer to the possible object in the table with the hashvalue
		Node* entry = _table[hashValue];

		// while we have a node
		while (entry != NULL)
		{
			// check if the node's key matches the one passed
			if (entry->GetKey() == key)
			{
				// if it does, assign the address to its value to the value pointer
				// that will be returned to the caller
				valuePtr = &entry->GetValue();
				// break out of the loop
				break;
			}
			// assign entry to the next node before starting the loop cycle again
			entry = entry->GetNextNode();
		}

		return valuePtr;
	}

private:
	F _hashFunction;
	Node** _table;
};
