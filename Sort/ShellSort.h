#pragma once
#ifndef _SHELLSORT_H_
#define _SHELLSORT_H_


#include "Sort.h"
class ShellSort :
	public Sort
{
public:
	ShellSort();
	~ShellSort();
	void sort(std::vector<int>&vec)override
	{
		int dk = 1;
		while (dk * 2 < vec.size()) dk = dk * 2 + 1;
		while (dk >= 1) {
			for (int i = 1; i != vec.size(); ++i) {
				for (int j = i; j - dk > 0 && vec[j] < vec[j - dk]; j -= dk) {
					std::swap(vec[j], vec[j - dk]);
				}
			}
			dk /= 2;
		}
	}
};

#endif // !_SHELLSORT_H_