#pragma once
#include <SFML/System/Vector2.hpp>

namespace Food
{
	enum class FoodType;
	class FoodItem;
	
	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		void spawnFood();
		FoodItem* createFood(sf::Vector2i position, FoodType type);
	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}