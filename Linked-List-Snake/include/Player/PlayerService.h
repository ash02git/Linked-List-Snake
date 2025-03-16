#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Level/LevelConfig.h"

namespace Player
{
	class SnakeController;
	enum class TimeComplexity;
	enum class LinkedListOperations;
	
	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer(Level::LinkedListType level_type);

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();

		bool isPlayerDead();
	};
}