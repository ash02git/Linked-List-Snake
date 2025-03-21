#include "../../include/Player/PlayerService.h"
#include "../../include/Player/SnakeController.h"

namespace Player
{
	
	PlayerService::PlayerService()
	{
		snake_controller = nullptr;
		createController();
	}
	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}
	PlayerService::~PlayerService()
	{
		delete(snake_controller);
	}
	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}
	void PlayerService::update()
	{
		snake_controller->update();
	}
	void PlayerService::render()
	{
		snake_controller->render();
	}
	void PlayerService::spawnPlayer(Level::LinkedListType level_type)
	{
		snake_controller->createLinkedList(level_type);
		snake_controller->spawnSnake();
	}
	std::vector<sf::Vector2i> PlayerService::getCurrentSnakePositionList()
	{
		return snake_controller->getCurrentSnakePositionList();
	}
	int PlayerService::getPlayerScore()
	{
		return snake_controller->getPlayerScore();
	}
	TimeComplexity PlayerService::getTimeComplexity()
	{
		return snake_controller->getTimeComplexity();
	}
	LinkedListOperations PlayerService::getLastOperation()
	{
		return snake_controller->getLastOperation();
	}
	bool PlayerService::isPlayerDead()
	{
		return snake_controller->isSnakeDead();
	}
}