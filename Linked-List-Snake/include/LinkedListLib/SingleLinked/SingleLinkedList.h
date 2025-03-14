#pragma once
#include "LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	namespace SingleLinked
	{
		class SingleLinkedList:public LinkedList
		{
		protected:
			virtual Node* createNode() override;

		public:
			SingleLinkedList();
			~SingleLinkedList();

			void insertNodeAtHead() override;
			void insertNodeAtTail() override;
			void insertNodeAtIndex(int index) override;
			void insertNodeAtMiddle() override;

			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);//private to public

			void removeNodeAtHead() override;
			void removeNodeAt(int index) override;
			void removeNodeAt(int index) override;
			void removeNodeAtMiddle() override;
			void removeNodeAtTail() override;
			void removeHalfNodes() override;
			void removeAllNodes() override;

			void shiftNodesAfterRemoval(Node* cur_node);//private to public

			Player::Direction reverse() override;
			void reverseNodeDirections();
		};
	}
}