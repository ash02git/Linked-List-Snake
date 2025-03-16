#pragma once
#include "../../include/LinkedListLib/SingleLinked/SingleLinkedList.h"

#include "../../include/Food/FoodType.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		SnakeState current_snake_state;
		LinkedListLib::SingleLinked::SingleLinkedList* single_linked_list;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;

		const float movement_frame_duration = 0.1f;
		float elapsed_duration;

		const float restart_duration = 2.0f;
		float restart_counter;

		InputState current_input_state;

		int player_score;

		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollission();
		void handleRestart();
		void reset();

		void createLinkedList();

		void delayedUpdate();

		void processBodyCollission();
		void processElementsCollission();
		void processFoodCollission();

		void OnFoodCollected(Food::FoodType type);
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}