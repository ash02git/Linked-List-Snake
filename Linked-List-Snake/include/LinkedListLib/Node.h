#pragma once
#include "Player/BodyPart.h"

namespace LinkedListLib
{
	struct Node
	{
		Player::BodyPart body_part;
		Node* next = nullptr;
	};
}