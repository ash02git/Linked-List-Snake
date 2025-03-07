#include "../../include/Food/FoodItem.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"

namespace Food
{
	
	FoodItem::FoodItem()
	{
		food_image = new UI::UIElement::ImageView();
	}
	FoodItem::~FoodItem()
	{
		delete(food_image);
	}
	sf::String FoodItem::getFoodTexturePath()
	{
		switch (food_type)
		{
		case Food::FoodType::APPLE:
			return Global::Config::apple_texture_path;

		case Food::FoodType::MANGO:
			return Global::Config::mango_texture_path;

		case Food::FoodType::ORANGE:
			return Global::Config::orange_texture_path;

		case Food::FoodType::PIZZA:
			return Global::Config::pizza_texture_path;

		case Food::FoodType::BURGER:
			return Global::Config::burger_texture_path;

		case Food::FoodType::CHEESE:
			return Global::Config::cheese_texture_path;

		case Food::FoodType::POISON:
			return Global::Config::poision_texture_path;

		case Food::FoodType::ALCOHOL:
			return Global::Config::alcohol_texture_path;
		}
	}
	sf::Vector2f FoodItem::getFoodImagePosition()
	{
		float screen_position_x = Level::LevelView::border_offset_left + (cell_width * grid_position.x);
		float screen_position_y = Level::LevelView::border_offset_top + (cell_height * grid_position.y);

		return sf::Vector2f(screen_position_x, screen_position_y);
	}
	void FoodItem::initializeFoodImage()
	{
		food_image->initialize(getFoodTexturePath(),cell_width,cell_height,getFoodImagePosition());
		food_image->show();
	}
	void FoodItem::initialize(sf::Vector2i grid_pos, float width, float height, FoodType type)
	{
		grid_position = grid_pos;
		cell_width = width;
		cell_height = height;
		food_type = type;

		initializeFoodImage();
	}
	void FoodItem::update()
	{
		food_image->update();
	}
	void FoodItem::render()
	{
		food_image->render();
	}
	FoodType FoodItem::getFoodType()
	{
		return food_type;
	}
}