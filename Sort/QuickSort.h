#pragma once
#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_


#include "Sort.h"
#include<iostream>
#include<random>

class QuickSort :
	public Sort
{
public:
	QuickSort();
	~QuickSort();
	void sort(std::vector<int>&vec)override
	{
		this->quickSort(vec, 0, vec.size() - 1);
	}

	void sort(std::vector<int>&vec,std::string s)
	{
		if(s=="RANDOM")
			this->randomQuickSort(vec, 0, vec.size() - 1);
	}

	void quickSort(std::vector<int>&vec, int p, int r)const
	{
		if (p < r) {
			auto q =this->partition(vec, p, r);
			//for (auto &r : vec)
			//	std::cout << r << " ";
			//std::cout << std::endl;
			quickSort(vec, p, q - 1);
			quickSort(vec, q + 1, r);
		}
	}
	
	void randomQuickSort(std::vector<int>&vec, int p, int r)const
	{
		if (p < r) {
			auto q = this->randomPartition(vec, p, r);
			//std::cout << std::endl;
			randomQuickSort(vec, p, q - 1);
			randomQuickSort(vec, q + 1, r);
		}
	}

	int partition(std::vector<int>&vec, int p, int r)const
	{
		int x = vec[r];
		int i = p - 1;
		for (int j = p; j != r ; ++j) {
			if (vec[j] <= x) {
				i++;
				std::swap(vec[i], vec[j]);
				//std::cout << "i = " << i << "||j = " << j << ":";
				//for (auto &r : vec)
				//	std::cout << r << " ";
				//std::cout << std::endl;
			}
		}
		std::swap(vec[i + 1], vec[r]);
		//std::cout << "return : " << i + 1 << std::endl;
		return i + 1;
	}
	int randomPartition(std::vector<int>&vec, int p, int r)const
	{
		//auto t = randomNum(p, r);
		static std::default_random_engine e;
		static std::uniform_int_distribution<unsigned>u(p, r);
		auto t = u(e);
		std::swap(vec[r], vec[t]);
		return this->partition(vec, p, r);
	}

	friend unsigned randomNum(int p, int r);
//{
//	static default_random_engine e;
//	static uniform_int_distribution<unsigned>u(p, r);
//	return u(e);
//}
};

#endif // !_QUICKSORT_H_
