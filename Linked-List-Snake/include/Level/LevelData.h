#pragma once
#include "../../include/Level/LevelNumber.h"
#include "../../include/Element/ElementData.h"

namespace Level
{
	struct LevelData
	{
		LevelNumber level_index;
		std::vector<Element::ElementData>* element_data_list;

		LevelData(LevelNumber ind,std::vector<Element::ElementData>* data_list)
		{
			level_index = ind;
			element_data_list = data_list;
		}
	};
}