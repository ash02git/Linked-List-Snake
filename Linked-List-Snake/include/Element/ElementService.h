#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>//this might be causing circular dependancy, bcoz ElementService.cpp file includes Obstacle.h which already includes ImageView, which might include Vector2.hpp
#include "../../include/LinkedListLib/Node.h"

namespace Element
{
	class Obstacle;
	struct ElementData;
	class Node;
	
	class ElementService
	{
	private:
		std::vector<Obstacle*> obstacle_list;

		void spawnObstacle(sf::Vector2i position,float cell_width,float cell_height);
	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		const void spawnElements(std::vector<ElementData>& element_data_list,float cell_width,float cell_height);

		std::vector<sf::Vector2i> getElementsPositionList();

		bool processElementsCollission(LinkedListLib::Node* head_node);
	};
}