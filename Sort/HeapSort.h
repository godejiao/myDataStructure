#pragma once
#include "Sort.h"
#include<iostream>
class HeapSort :
	public Sort
{
public:
	HeapSort();
	~HeapSort();
	//void sort(std::vector<int>&vec)override
	//{
	//	for (int i = vec.size(); i != 0; --i) {
	//		this->maxHeapify(vec, i);
	//		std::swap(vec[i-1], vec[0]);
	//	}
	//}
	void sort(std::vector<int>&vec)override
	{
		this->buildMinHeap(vec);
		for (auto &r : vec)
			std::cout << r << " ";
		std::cout << std::endl;
		int size = vec.size();
		for (int i = size - 1; i != 0; --i) {
			std::swap(vec[0], vec[i]);
			--size;
			this->minHeapify(vec, 0, size);
		}
	}
private:
	//void maxHeapify(std::vector<int>&vec, int size)const
	//{
	//	for (int j = size-1; j >= 0; --j) {
	//		int parent = j / 2;
	//		int child = j;
	//		if (j < size - 1 && vec[j] < vec[j + 1])++child;
	//		if (vec[parent] < vec[child])
	//			std::swap(vec[parent], vec[child]);

	//	}
	//}
	void maxHeapify(std::vector<int>&vec, const int node, const int size)const
	{
		int lchild = 2 * node + 1;
		int rchild = 2 * (node + 1);
		int maxnum = node;
		if (lchild < size&&vec[maxnum] < vec[lchild])
			maxnum = lchild;
		if (rchild < size&&vec[maxnum] < vec[rchild])
			maxnum = rchild;
		if (node != maxnum) {
			std::swap(vec[node], vec[maxnum]);
			this->maxHeapify(vec, maxnum, size);
		}
	}
	void buildMaxHeap(std::vector<int>&vec)const
	{
		for (int i = vec.size() /2-1; i >= 0; --i) {
			this->maxHeapify(vec, i,vec.size());
		}
	}
	void minHeapify(std::vector<int>&vec, const int node,const int size)const
	{
		int lchild = 2 * node + 1;
		int rchild = 2 * (node + 1);
		int minnum = node;
		if (lchild < size&&vec[lchild] < vec[minnum])
			minnum = lchild;
		if (rchild < size&&vec[rchild] < vec[minnum])
			minnum = rchild;
		if (node != minnum) {
			std::swap(vec[minnum], vec[node]);
			minHeapify(vec, minnum, size);
		}
	}
	void buildMinHeap(std::vector<int>&vec)const
	{
		for (int i = vec.size() / 2 - 1; i >= 0; --i) {
			minHeapify(vec, i, vec.size());
		}
	}
};

