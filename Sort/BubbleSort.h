#pragma once
#include "Sort.h"
class BubbleSort :
	public Sort
{
public:
	BubbleSort();
	~BubbleSort();
	void sort(std::vector<int>&vec)override
	{
		for (int i = 0; i != vec.size(); ++i)
			for (int j = i; j != vec.size(); ++j)
				if (vec[j] < vec[i])
					std::swap(vec[j], vec[i]);
	}
};

