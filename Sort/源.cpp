#include"InsertSort.h"
#include"shellsort.h"
#include"selectsort.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include<iostream>
#include "HeapSort.h"
#include"MergeSort.h"
#include<ctime>
#include<vector>
#include<random>
#include"RandomizedSelect.h"
using namespace std;
//void sort(vector<int>&vec)
//{
//	for (int i = 1; i != vec.size(); ++i) {
//		for (int j = i; j != 0; --j) {
//			if (vec[j] < vec[j - 1]) {
//				std::swap(vec[j], vec[j - 1]);
//			}
//		}
//	}
//}

vector<int> randVec(size_t n, int minimum, int maximum)//生成随机数，n:数目，范围[minimum,maximum]
{
	vector<int> data_input;
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(minimum, maximum);
	for (size_t i = 0; i != n; ++i)
		data_input.push_back(u(e));

	return data_input;
}
int main()
{
	vector<int>v1{ 2,7,3,5,9,8,5,2};
	vector<int>v2{ 2,8,7,1,3,5,6,4 };
	vector<int>v3;
	srand((unsigned)time(NULL));
	int len = rand() % 100;
	for (int i = 0; i != len; ++i) {
		v3.push_back(rand() % 100);
	}

	auto v4 = randVec(20, 0, 1000);
	InsertSort v;
	ShellSort s;
	SelectSort s1;
	BubbleSort b;
	QuickSort q;
	HeapSort h;
	MergeSort m;
	RandomizedSelect r;
	//v.sort(v1);
	//q.sort(v2);
	if (v3.size())
		q.sort(v3);//,"RANDOM");
	for (auto &r : v3) {
		cout << r << " ";
	}
	cout << endl;
	for (auto&r : v4)
		cout << r << " ";
	cout << endl;
	cout << "the 5th mini : " << r.select(v4, 5) << endl;

	for (auto&r : v4)
		cout << r << " ";
	cout << endl;


	if (v4.size())
		q.sort(v4);//,"RANDOM");
	for (auto &r : v4) {
		cout << r << " ";
	}
	cout << endl;
	
	getchar();
	return 0;
}