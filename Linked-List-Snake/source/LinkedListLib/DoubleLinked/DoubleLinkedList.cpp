#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "LinkedListLib/DoubleLinked/DoubleNode.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		Node* DoubleLinkedList::createNode()
		{
			return new DoubleNode();
		}
		DoubleLinkedList::DoubleLinkedList() = default;
		DoubleLinkedList::~DoubleLinkedList() = default;
	}
}