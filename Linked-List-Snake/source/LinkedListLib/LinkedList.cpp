#include "../../include/LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	sf::Vector2i LinkedList::getNewNodePosition(Node* reference_node, Operation operation)
	{
		switch (operation)
		{
		case Operation::HEAD:
			return reference_node->body_part.getNextPosition();
		case Operation::TAIL:
			return reference_node->body_part.getPrevPosition();
		}

		return default_position;
	}
	Player::Direction LinkedList::getReverseDirection(Player::Direction reference_direction)
	{
		switch (reference_direction)
		{
		case Player::Direction::DOWN:
			return Player::Direction::UP;
			break;
		case Player::Direction::UP:
			return Player::Direction::DOWN;
			break;
		case Player::Direction::LEFT:
			return Player::Direction::RIGHT;
			break;
		case Player::Direction::RIGHT:
			return Player::Direction::LEFT;
			break;
		}
	}
	Node* LinkedList::findNodeAtIndex(int index)
	{
		Node* cur_node = head_node;
		int current_index = 0;

		while (cur_node != nullptr && current_index <= index - 1)
		{
			cur_node = cur_node->next;
			current_index++;
		}

		return cur_node;

		//try if this code snippet works
	}

	void LinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
	{
		if (reference_node == nullptr)
		{
			new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
			return;
		}

		sf::Vector2i position = getNewNodePosition(reference_node, operation);
		new_node->body_part.initialize(node_width, node_height, position, reference_node->body_part.getDirection());
	}

	/*
		1,2,3,4,5  :: 1
		current_index = 0
		cure_node - 1
	*/

	int LinkedList::findMiddleNode()
	{
		Node* fast = head_node;

		int mid_index = 0;

		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;

			mid_index++;
		}

		return mid_index;
	}
	LinkedList::LinkedList()
	{
		head_node = nullptr;
	}
	LinkedList::~LinkedList()
	{
		//removeAllNodes();
	}
	void LinkedList::initialize(float width, float height, sf::Vector2i position, Player::Direction direction)
	{
		linked_list_size = 0;

		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}
	void LinkedList::render()
	{
		Node* cur_node = head_node;

		while (cur_node != nullptr)
		{
			cur_node->body_part.render();
			cur_node = cur_node->next;
		}
	}
	void LinkedList::updateNodePosition()
	{
		Node* cur_node = head_node;

		while (cur_node != nullptr)
		{
			cur_node->body_part.updatePosition();
			cur_node = cur_node->next;
		}
	}
	void LinkedList::updateNodeDirection(Player::Direction direction_to_set)
	{
		Node* cur_node = head_node;

		while (cur_node != nullptr)
		{
			Player::Direction previous_direction = cur_node->body_part.getDirection();
			cur_node->body_part.setDirection(direction_to_set);
			direction_to_set = previous_direction;

			cur_node = cur_node->next;
		}
	}
	Node* LinkedList::getNodeHead()
	{
		return head_node;
	}
	int LinkedList::getLinkedListSize()
	{
		return linked_list_size;
	}
	bool LinkedList::processNodeCollission()
	{
		if (head_node == nullptr)
			return false;

		sf::Vector2i predicted_position = head_node->body_part.getNextPosition();

		Node* cur_node = head_node->next;
		//checking if each body nodes nextPosition == headNodes nextPosition
		while (cur_node!=nullptr)
		{
			if (cur_node->body_part.getNextPosition() == predicted_position)
				return true;

			cur_node = cur_node->next;
		}

		return false;//if code reaches here then no collissions happened
	}
	void LinkedList::reverseNodeDirections()//reverses the nodes directions based on their previous frame direction
	{
		Node* cur_node = head_node;
		Player::Direction direction;

		while (cur_node != nullptr)
		{
			cur_node->body_part.setDirection(getReverseDirection(cur_node->body_part.getPreviousDirection()));
			cur_node = cur_node->next;
		}
	}
	std::vector<sf::Vector2i> LinkedList::getNodesPositionList()
	{
		std::vector<sf::Vector2i> position_list;

		Node* cur_node = head_node;

		while (cur_node != nullptr)
		{
			position_list.push_back(cur_node->body_part.getPosition());
			cur_node = cur_node->next;
		}

		return position_list;
	}
}

/*
	1,2,3,4,5

	fast-5
	slow-3

	mid_index=2
*/