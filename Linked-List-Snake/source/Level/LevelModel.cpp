#include "../../include/Level/LevelModel.h"
#include "../../include/Level/LevelData.h"

namespace Level
{
	LevelModel::LevelModel() = default;
	
	LevelModel::~LevelModel() = default;
	
	void LevelModel::initializeLevelData()
	{
		level_configurations.push_back(LevelData(Level::LevelNumber::ONE, &level_one_element_list));
		level_configurations.push_back(LevelData(Level::LevelNumber::TWO, &level_two_element_list));
	}

	void LevelModel::initialize(int width, int height)
	{
		cell_width = width / number_of_columns;
		cell_height = height / number_of_rows;

		initializeLevelData();
	}
	float LevelModel::getCellWidth()
	{
		return cell_width;
	}
	float LevelModel::getCellHeight()
	{
		return cell_height;
	}
	const std::vector<Element::ElementData>& LevelModel::getElementDataList(int level_to_load)
	{
		return *level_configurations[level_to_load].element_data_list;
	}
}