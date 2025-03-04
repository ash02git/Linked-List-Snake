#pragma once
#include "../../include/Level/LevelNumber.h"

namespace Level
{
	struct LevelData
	{
		LevelNumber level_index;

		LevelData(LevelNumber ind)
		{
			level_index = ind;
		}
	};
}