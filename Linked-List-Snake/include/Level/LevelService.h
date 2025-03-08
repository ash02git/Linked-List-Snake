#pragma once
#include "../../include/Level/LevelNumber.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void spawnPlayer();

		void spawnLevelElements(Level::LevelNumber level_to_load);//this function was added after setting up levelModel to include elementdata

		void spawnFood();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_load);
		float getCellWidth();
		float getCellHeight();
	};
}