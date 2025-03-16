#pragma once
#include "../../include/Level/LevelConfig.h"
#include "../../include/Element/ElementData.h"//might be a problem for circular dependancy

namespace Level
{
	//struct ElementData;
	
	struct LevelData
	{
		LevelNumber level_index;
		std::vector<Element::ElementData>* element_data_list;

		LevelData(LevelNumber ind , std::vector<Element::ElementData>* data_list)
		{
			level_index = ind;
			element_data_list = data_list;
		}
	};
}