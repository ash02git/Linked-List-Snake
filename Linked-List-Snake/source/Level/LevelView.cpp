#include "../../include/Level/LevelView.h"
#include "../../include/Global/ServiceLocator.h"

#include <iostream>
namespace Level
{
	void LevelView::initializeBackground()
	{
		sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f background_size = sf::Vector2f(game_window->getSize().x, game_window->getSize().y);

		background_rectangle->initialize(background_size, sf::Vector2f(0, 0), 0, background_color);
		background_rectangle->show();
	}

	void LevelView::initializeBorder()
	{
		sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f border_size = sf::Vector2f(grid_width, grid_height);
		sf::Vector2f border_position = sf::Vector2f(border_offset_left, border_offset_top);

		border_rectangle->initialize(border_size, border_position, border_thickness, sf::Color::Transparent, border_color);
		border_rectangle->show();
	}
	
	LevelView::LevelView()
	{
		background_rectangle = nullptr;
		background_rectangle = new UI::UIElement::RectangleShapeView();

		border_rectangle = nullptr;
		border_rectangle = new UI::UIElement::RectangleShapeView();
	}
	LevelView::~LevelView()
	{
		delete(background_rectangle);
		delete(border_rectangle);
	}
	void LevelView::initialize()
	{
		initializeBackground();
		calculateGridExtents();
		initializeBorder();
	}
	void LevelView::update()
	{
		background_rectangle->update();
		border_rectangle->update();
	}
	void LevelView::render()
	{
		background_rectangle->render();
		border_rectangle->render();
	}
	float LevelView::getGridWidth()
	{
		std::cout << "Grid width passed from LevelView is "<<grid_width<< std::endl;
		return grid_width;
	}
	float LevelView::getGridHeight()
	{
		std::cout << "Grid height passed from LevelView is " << grid_height << std::endl;
		return grid_height;
	}

	void LevelView::calculateGridExtents()
	{
		sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		grid_width = game_window->getSize().x - 2 * border_offset_left;
		grid_height = game_window->getSize().y - 2 * border_offset_top-border_offset_bottom;

		std::cout << "Grid width is " << grid_width << std::endl;
		std::cout << "Grid height is " << grid_width << std::endl;
	}
}