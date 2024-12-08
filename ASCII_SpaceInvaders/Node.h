#pragma once

class Node
{
public:
	Node* next = nullptr;
	Node* previous = nullptr;

	void Remove();
	void InsertBefore(Node* target);
	void InsertAfter(Node* target);
	void Append(Node* target);
	void Push(Node* target);
};