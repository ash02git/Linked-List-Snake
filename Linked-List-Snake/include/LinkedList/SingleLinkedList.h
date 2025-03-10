#pragma once
#include "Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL
	};
	
	class SingleLinkedList
	{
	private:
		Node* head_node;
		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Player::Direction default_direction;

		Node* createNode();

		sf::Vector2i getNewNodePosition(Node* reference_node,Operation operation);

		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();

		void insertNodeAtTail();

		void updateNodeDirection(Player::Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollission();

		void removeNodeAtHead();
		void removeAllNodes();

		std::vector<sf::Vector2i> getNodesPositionList();

		Node* getHeadNode();
	};
}