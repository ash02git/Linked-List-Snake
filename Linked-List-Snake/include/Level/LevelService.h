#pragma once
#include "../../include/Level/LevelConfig.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_linked_list_type;

		void spawnPlayer();

		void spawnLevelElements(Level::LevelNumber level_to_load);//this function was added after setting up levelModel to include elementdata

		void spawnFood();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LinkedListType linked_list_type);
		float getCellWidth();
		float getCellHeight();

		LevelNumber getCurrentLevel();

		void setCurrentLevelNumber(LevelNumber number);
	};
}