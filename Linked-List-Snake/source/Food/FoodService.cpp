#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Level/LevelModel.h"

namespace Food
{
	
	FoodService::FoodService() : random_engine(random_device())
	{
		current_food_item = nullptr;
	}

	FoodService::~FoodService()
	{
		destroyFood();
	}
	void FoodService::initialize()
	{
		elapsed_duration = spawn_duration;
	}
	void FoodService::update()
	{
		if (current_spawning_status == FoodSpawningStatus::ACTIVE)
		{
			updateElapsedDuration();
			handleFoodSpawning();
		}

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
		current_spawning_status = FoodSpawningStatus::ACTIVE;

		cell_width = Global::ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		cell_height = Global::ServiceLocator::getInstance()->getLevelService()->getCellHeight();
	}

	void FoodService::stopFoodSpawning()
	{
		current_spawning_status = FoodSpawningStatus::INACTIVE;
		destroyFood();
		reset();
	}

	bool FoodService::processFoodCollission(LinkedListLib::Node* head_node, FoodType& out_food_type)
	{
		if (current_food_item && current_food_item->getFoodPosition() == head_node->body_part.getPosition())
		{
			out_food_type = current_food_item->getFoodType();

			destroyFood();//new line added
			reset();
			spawnFood();
			return true;
		}

		return false;
	}

	

	void FoodService::spawnFood()
	{
		current_food_item = createFood(getRandomPosition(), getRandomFoodType());
	}
	void FoodService::destroyFood()
	{
		if (current_food_item)
			delete(current_food_item);
	}
	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* item = new FoodItem();
		item->initialize(position, cell_width, cell_height, type);

		return item;
	}
	sf::Vector2i FoodService::getRandomPosition()
	{
		// Coordinate distribution for selecting a random position for food
		std::uniform_int_distribution<int> x_distribution(0, Level::LevelModel::number_of_columns - 1);
		std::uniform_int_distribution<int> y_distribution(0, Level::LevelModel::number_of_rows - 1);

		int x_position = x_distribution(random_engine);
		int y_position = y_distribution(random_engine);

		return sf::Vector2i(x_position, y_position);
	}
	bool FoodService::isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position)
	{
		for (int i = 0; i < position_data.size(); i++)
		{
			if (food_position == position_data[i]) return false;
		}
		return true;
	}
	sf::Vector2i FoodService::getValidSpawnPosition()
	{
		std::vector<sf::Vector2i> player_position_data = Global::ServiceLocator::getInstance()->getPlayerService()->getCurrentSnakePositionList();
		std::vector<sf::Vector2i> elements_position_data = Global::ServiceLocator::getInstance()->getElementService()->getElementsPositionList();
		sf::Vector2i spawn_position;

		do
		{
			spawn_position = getRandomPosition();
		}
		while (!isValidPosition(player_position_data, spawn_position) || !isValidPosition(elements_position_data, spawn_position));

		return spawn_position;
	}
	FoodType FoodService::getRandomFoodType()
	{
		std::uniform_int_distribution<int> distribution(0, FoodItem::number_of_foods - 1);
		return static_cast<FoodType>(distribution(random_engine));
	}
	void FoodService::reset()
	{
		elapsed_duration = 0.0f;
	}
	void FoodService::updateElapsedDuration()
	{
		elapsed_duration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void FoodService::handleFoodSpawning()
	{
		if (Global::ServiceLocator::getInstance()->getPlayerService()->isPlayerDead()) return;

		
		if (elapsed_duration >= spawn_duration)
		{
			destroyFood();
			reset();
			spawnFood();
		}
	}
}