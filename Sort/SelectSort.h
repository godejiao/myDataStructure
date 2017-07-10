#pragma once
#ifndef _SELECTSORT_H_
#define _SELECTSORT_H


#include "Sort.h"
class SelectSort :
	public Sort
{
public:
	SelectSort();
	~SelectSort();
	void sort(std::vector<int>& vec)override
	{
		for (int i = 0; i != vec.size()-1; ++i) {
			int k = i;
			for (int j = i + 1; j != vec.size() ; ++j) {
				if (vec[j] < vec[k]) {
					k = j;
				}
				   std::swap(vec[i], vec[k]);
			}
		}
	}
};

#endif // !_SELECTSORT_H_