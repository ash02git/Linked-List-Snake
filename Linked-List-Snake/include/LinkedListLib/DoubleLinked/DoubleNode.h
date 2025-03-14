#pragma once
#include "LinkedListLib/Node.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		struct DoubelNode :public Node
		{
			Node* prev = nullptr;
		};
	}
}