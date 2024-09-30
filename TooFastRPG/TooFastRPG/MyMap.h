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
		for (int stage = 0; stage < 4; ++stage)
		{
			if (stage == 0) stages[stage][1][MAPMAXH - 2] = 2;
			if (stage == 1) stages[stage][MAPMAXW - 2][MAPMAXH - 2] = 2;
			if (stage == 2) stages[stage][1][1] = 2;
			if (stage == 3) stages[stage][MAPMAXW - 2][2] = 2;

		}
		



		CreateBox(0, 5, 8, 2, 3);
		CreateBox(0, 10, 8, 2, 3);
		CreateBox(0, 15, 8, 2, 3);
		CreateBox(0, 20, 8, 2, 3);
		CreateBox(0, 25, 8, 2, 3);
		CreateBox(0, 30, 8, 3, 2);


		CreateBox(0, 35, 35, 2, 3);
		CreateBox(0, 30, 35, 2, 3);
		CreateBox(0, 25, 35, 2, 3);
		CreateBox(0, 20, 35, 2, 3);
		CreateBox(0, 15, 35, 2, 3);
		CreateBox(0, 10, 34, 3, 2);




	};

	void CreateBox(int stg, int x, int y, int w, int h)
	{
		for (int i = y - 1; i < y + w - 1; ++i)
		{
			for (int j = x - 1; j < x + h - 1; ++j)
			{
				stages[stg][i][j] = 1;
			}
		}
	}
};