#pragma once
#include "LinkedListLib/Node.h"

namespace LinkedListLib
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL
	};

	class LinkedList
	{
	protected:
		Node* head_node;
		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Player::Direction default_direction;

		int linked_list_size;

		virtual Node* createNode() = 0;
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		Player::Direction getReverseDirection(Player::Direction reference_direction);
		
		Node* findNodeAtIndex(int index);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

		int findMiddleNode();
	public:
		LinkedList();
		virtual ~LinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();

		virtual void insertNodeAtTail() = 0;
		virtual void insertNodeAtHead() = 0;
		virtual void insertNodeAtMiddle() = 0;
		virtual void insertNodeAtIndex(int index) = 0;

		virtual void removeNodeAtTail() = 0;
		virtual void removeNodeAtHead() = 0;
		virtual void removeNodeAtMiddle() = 0;
		virtual void removeNodeAt(int index) = 0;
		virtual void removeAllNodes() = 0;
		virtual void removeHalfNodes() = 0;

		virtual Player::Direction reverse() = 0;

		virtual void updateNodePosition();
		virtual void updateNodeDirection(Player::Direction direction_to_set);

		Node* getNodeHead();
		int getLinkedListSize();
		bool processNodeCollission();
		void reverseNodeDirections();

		std::vector<sf::Vector2i> getNodesPositionList();
	};
}