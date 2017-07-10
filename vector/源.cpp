#include"qh_vector.h"
#include<iostream>
#include <assert.h>
#include<string>
using namespace std;
using namespace qh;
int main()
{
	//vector<int>veci;
	//cout << veci.size() << endl;
	//for (int i = 0; i != 10; ++i)
	//	veci.push_back(i);
	//cout << veci.size() << endl;
	//veci.pop_back();
	//for (auto &r : veci)
	//	cout << r << " ";
	//cout << endl;

	//cout << veci.size() << endl;
	//for(int i=0;i!=veci.size();++i)
	//cout << veci[i] << " ";
	//vector<int>veci;
	//assert(veci.size() == 0);
	////cout << veci.size() << endl;
	//for (int i = 0; i != 10; ++i)
	//	veci.push_back(i);
	//veci.pop_back();
	//size_t index = 0;
	//for (auto &r : veci)
	//	assert(r == veci[index++]);
	//assert(veci.size() == 9);
	//cout << veci.size() << endl;
	//for (int i = 0; i != veci.size(); ++i)
	//	assert(veci[i] == i);
	vector<string> vecs;
	vecs.push_back("hello world!");
	cout <<vecs.size()<< endl;
	for (auto &r : vecs)
		cout << r << endl;
	system("pause");
	return 0;
}