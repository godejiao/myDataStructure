#pragma once
#ifndef _INSERTSORT_H_
#define _INSERTSORT_H_

#include  <vector>
#include "Sort.h"
class InsertSort :
	public Sort
{
public:
	InsertSort()=default;
	//InsertSort(std::vector<int> v) :vec(v){}
	~InsertSort() {};
	void sort(std::vector<int>&vec)override;
	
private:
	//std::vector<int> vec;
};
#endif // !_INSERTSORT_H_
