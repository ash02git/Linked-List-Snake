#include "../../include/Level/LevelService.h"
#include "../../include/Global/ServiceLocator.h"

namespace Level
{
	void LevelService::spawnPlayer()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
	}
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}
	LevelService::~LevelService()
	{
		delete(level_controller);
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
		spawnPlayer();
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