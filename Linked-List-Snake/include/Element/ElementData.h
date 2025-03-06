#pragma once
#include <SFML/System/Vector2.hpp>

namespace Element
{
	enum class ElementType
	{
		OBSTACLE
	};

	struct ElementData
	{
		ElementType element_type;
		sf::Vector2i position;

		ElementData(ElementType type, sf::Vector2i pos)
		{
			element_type = type;
			position = pos;
		}
	};
}