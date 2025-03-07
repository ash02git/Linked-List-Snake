#pragma once
#include <vector>
#include "Element/ElementData.h"//maybe causes multiple include problems
namespace Level
{
	class LevelData;//forward declaring leveldata to avoid multiple includes

	class LevelModel
	{
	private:
		std::vector<LevelData> level_configurations;
		float cell_width;
		float cell_height;

		std::vector<Element::ElementData> level_one_element_list = {};
		std::vector<Element::ElementData> level_two_element_list = 
        {
            //TOP-LEFT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 3)),

            //TOP-RIGHT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 2)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 3)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 1)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46, 1)),

            //BOTTOM-LEFT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 25)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 24)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 26)),

            //BOTTOM-RIGHT
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 25)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 24)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(47, 26)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(46, 26)),

            //CENTER-TOP-BAR
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 11)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 11)),

            //CENTER-BOTTOM-BAR
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 15)),
            Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 15)),
        };;

		void initializeLevelData();
	public:
		static const int number_of_rows = 27;//changed to 27
		static const int number_of_columns = 50;

		LevelModel();
		~LevelModel();

		void initialize(int width, int height);

		float getCellWidth();
		float getCellHeight();

		const std::vector<Element::ElementData>& getElementDataList(int level_to_load);
	};
}