#pragma once
#include "stdafx.h"

struct MyMap
{
	vector<vector<int>> stage = vector<vector<int>> (MAPMAXW, vector<int>(MAPMAXH, 0));
	vector<vector<vector<int>>> stages = vector<vector<vector<int>>>(4, stage);

	MyMap()
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

		CreateBox(1, 13, 16, 14, 13);
		CreateBox(1, 5, 8, 2, 3);
		CreateBox(1, 35, 35, 2, 3);

		CreateBox(2, 5, 8, 2, 35);
		CreateBox(2, 2, 35, 2, 30);
		CreateBox(2, 35, 18, 2, 3);
		CreateBox(2, 15, 35, 2, 3);
	
		CreateBox(3, 8, 2, 6, 3);		// x y h w
		CreateBox(3, 2, 8, 3, 5);		// x y h w

	};

	void CreateBox(int stg, int x, int y, int h, int w)
	{
		for (int i = y - 1; i < y + h - 1; ++i)
		{
			for (int j = x - 1; j < x + w - 1; ++j)
			{
				stages[stg][i][j] = 1;
			}
		}
	}
};