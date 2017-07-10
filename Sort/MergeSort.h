#pragma once
#include "Sort.h"
class MergeSort :
	public Sort
{
public:
	MergeSort();
	~MergeSort();
	void sort(std::vector<int>&vec)override
	{
		this->mergeSort(vec, 0, vec.size()-1);
	}
private:
	void mergeSort(std::vector<int>&vec, const int p, const int r)
	{
		if (p < r) {
			int q = (p + r) / 2;
			mergeSort(vec, p, q);
			mergeSort(vec, q + 1, r);
			merge(vec, p, q, r);
		}
	}
	void merge(std::vector<int>&vec, int p, int q, int r)const
	{
		int n1 = q - p + 1;
		int n2 = r - q;
		std::vector<int> L(n1+1, 0), R(n2+1, 0);
		for (int i = 0; i != n1; ++i)
		{
			L[i] = vec[p + i ];
		}
		for (int j = 0; j != n2; ++j)
			R[j] = vec[q + j+1];
		L[n1] = INT_MAX;
		R[n2] =INT_MAX;
		for (int i = 0, j = 0, k = p; k != r+1; ++k) {
			if (L[i] <= R[j]) {
				vec[k] = L[i];
				++i;
			}
			else {
				vec[k] = R[j];
				++j;
			}
		}
	}
};

