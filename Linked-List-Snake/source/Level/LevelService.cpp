#include "../../include/Level/LevelService.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelController.h"

namespace Level
{
	void LevelService::spawnPlayer()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->spawnPlayer(current_linked_list_type);
	}
	void LevelService::spawnLevelElements(Level::LevelNumber level_to_load)
	{
		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

		std::vector<Element::ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
		Global::ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);
	}
	void LevelService::spawnFood()
	{
		Global::ServiceLocator::getInstance()->getFoodService()->startFoodSpawning();
	}
	LevelService::LevelService()
	{
		level_controller = nullptr;
		level_controller = new LevelController();
	}
	LevelService::~LevelService()
	{
		delete(level_controller);
	}

	void LevelService::createLevel(LinkedListType linked_list_type)
	{
		current_linked_list_type = linked_list_type;
		spawnLevelElements(current_level);
		spawnFood();
		spawnPlayer();
	}

	float LevelService::getCellWidth()
	{
		return level_controller->getCellWidth();
	}

	float LevelService::getCellHeight()
	{
		return level_controller->getCellHeight();
	}

	LevelNumber LevelService::getCurrentLevel()
	{
		return current_level;
	}

	void LevelService::setCurrentLevelNumber(LevelNumber number)
	{
		current_level = number;
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}
	void LevelService::update()
	{
		level_controller->update();
	}
	void LevelService::render()
	{
		level_controller->render();
	}
}