#include "Node.h"

void Node::Remove()
{
	if (next)
	{
		next->previous = previous;
	}

	if (previous)
	{
		previous->next = next;
	}
}

void Node::InsertBefore(Node* target)
{
	if (target)
	{
		previous = target->previous;
		target->previous = this;
		next = target;
		if (previous)
		{
			previous->next = this;
		}
	}
}

void Node::InsertAfter(Node* target)
{
	if (target)
	{
		next = target->next;
		target->next = this;
		previous = target;
		if (next)
		{
			next->previous = this;
		}
	}
}

void Node::Append(Node* target)
{
	Node* LastNode = target;
	while (LastNode->next) { LastNode = LastNode->next; }

	if (LastNode)
	{
		previous = LastNode;
		LastNode->next = this;
		next = nullptr;
	}
}

void Node::Push(Node* target)
{
	Node* FirstNode = target;
	while (FirstNode->previous) { FirstNode = FirstNode->previous; }

	if (FirstNode)
	{
		previous = nullptr;
		FirstNode->previous = this;
		next = FirstNode;
	}
}