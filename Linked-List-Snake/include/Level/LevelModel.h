#pragma once
#include "../../include/Level/LevelData.h"
#include <vector>
namespace Level
{
	class LevelModel
	{
	private:
		std::vector<LevelData> level_configruations;
		float cell_width;
		float cell_height; 

	public:
		static const int number_of_rows = 27;//changed to 27
		static const int number_of_columns = 50;

		LevelModel();
		~LevelModel();

		void initialize(int width, int height);

		float getCellWidth();
		float getCellHeight();
	};
}