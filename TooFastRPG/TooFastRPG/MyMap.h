#pragma once
#include "stdafx.h"

struct MyMap
{
	vector<vector<int>> stage = vector<vector<int>> (MAPMAXW, vector<int>(MAPMAXH, 0));
	vector<vector<vector<int>>> stages = vector<vector<vector<int>>>(4, stage);

	void CreateMap() 
	{
		for (auto& stage : stages)
		{
			for (int i = 0; i < stage.size(); ++i)
			{
				for (int j = 0; j < stage[0].size(); ++j)
				{
					if (i == 0 || j == 0 || i == stage.size() - 1 || j == stage[0].size() - 1)
						stage[i][j] = 1;
				}
			}
		}
	};
};