#pragma once

template <typename K, typename V>
class MyHashNode
{
public:
	MyHashNode(const K& key, const V& value) : _key(key), _value(value), _nextNode(NULL) { }

	void SetValue(V newValue) { _value = newValue; }
	void SetNext(MyHashNode* newNextNode) { _nextNode = newNextNode; }

	const K& GetKey() const { return _key; }
	const V& GetValue() const { return _value; }

	MyHashNode* GetNextNode() const { return _nextNode; }

private:
	K _key;
	V _value;

	MyHashNode* _nextNode;
};
