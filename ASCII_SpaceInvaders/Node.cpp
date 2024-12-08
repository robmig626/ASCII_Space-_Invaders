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