#pragma once
#ifndef _RANDOMIZEDSELECT_H_
#define _RANDOMIZEDSELECT_H_
#include"QuickSort.h"

class RandomizedSelect
{
	friend class QuickSort;
public:
	RandomizedSelect();
	~RandomizedSelect();
	int select(std::vector<int>&vec, int i)
	{
		return this->select(vec,0,vec.size()-1,i);
	}
private:
	QuickSort qs;
private:
	int select(std::vector<int>&vec, int p, int r, int i)
	{
		if (p == r)
			return vec[p];
		auto q = qs.randomPartition(vec, p, r);
		auto k = q - p + 1;
		if (i == k)
			return vec[q];
		else if (i < k)
			return this->select(vec, p, q - 1, i);
		else
			return this->select(vec, q + 1, r, i - k);
	}
};
#endif // !_RANDOMIZEDSELECT_H_
