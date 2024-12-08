#pragma once

class Node
{
public:
	Node* next = nullptr;
	Node* previous = nullptr;

	void Remove();
	void InsertBefore(Node* target);
};