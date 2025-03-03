#include "../../include/LinkedList/SingleLinkedList.h"

namespace LinkedList
{
	
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}
	SingleLinkedList::~SingleLinkedList()
	{
	}
	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Player::Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}
	void SingleLinkedList::render()
	{
	}
	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}
}