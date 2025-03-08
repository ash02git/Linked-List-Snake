#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Food/FoodType.h"

namespace Food
{
	
	FoodService::FoodService()
	{
		current_food_item = nullptr;
	}
	FoodService::~FoodService()
	{
		if(current_food_item)
			delete(current_food_item);
	}
	void FoodService::initialize()
	{
	}
	void FoodService::update()
	{
		if (current_food_item)
			current_food_item->update();
	}
	void FoodService::render()
	{
		if (current_food_item)
			current_food_item->render();
	}
	void FoodService::startFoodSpawning()
	{
		cell_width = Global::ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		cell_height = Global::ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		spawnFood();
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(sf::Vector2i(4, 6), FoodType::BURGER);
	}
	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* item = new FoodItem();
		item->initialize(position, cell_width, cell_height, type);

		return item;
	}
}