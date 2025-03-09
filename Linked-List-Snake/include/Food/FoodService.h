#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include "LinkedList/Node.h"

namespace Food
{
	enum class FoodType;
	class FoodItem;
	
	enum FoodSpawningStatus
	{
		ACTIVE,
		INACTIVE
	};

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		// To generate random values.
		std::default_random_engine random_engine;

		// To give random seed to generator.
		std::random_device random_device;

		const float spawn_duration = 4.0f;
		float elapsed_duration;

		FoodSpawningStatus current_spawning_status;

		void spawnFood();
		FoodItem* createFood(sf::Vector2i position, FoodType type);

		sf::Vector2i getRandomPosition();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i getValidSpawnPosition();

		FoodType getRandomFoodType();

		void reset();

		void updateElapsedDuration();

		void handleFoodSpawning();
	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void stopFoodSpawning();

		void destroyFood();

		bool processFoodCollission(LinkedList::Node* head_node, FoodType& out_food_type);
	};
}