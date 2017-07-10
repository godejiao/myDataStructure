#include "QuickSort.h"



QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}

unsigned randomNum(int p, int r)
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<int> u(p,r);
	return u(e);
}
