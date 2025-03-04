#include "../../include/Level/LevelController.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView();
	}
	LevelController::~LevelController()
	{
		delete(level_view);
		delete(level_model);
	}
	void LevelController::initialize()
	{
		level_view->initialize();
		level_model->initialize(level_view->getGridWidth(),level_view->getGridHeight());
	}
	void LevelController::update()
	{
		level_view->update();
	}
	void LevelController::render()
	{
		level_view->render();
	}
	float LevelController::getCellWidth()
	{
		return level_model->getCellWidth();//changed from level_view to level_model
	}
	float LevelController::getCellHeight()
	{
		return level_model->getCellHeight();//changed from level_view to level_model
	}
}