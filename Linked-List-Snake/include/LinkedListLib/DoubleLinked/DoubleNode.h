#pragma once
#include "LinkedListLib/Node.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		struct DoubleNode :public Node
		{
			Node* prev = nullptr;
		};
	}
}