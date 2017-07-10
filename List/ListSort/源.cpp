#include"listsort.h"
#include<random>
using namespace std;
int main()
{
	ListNode dummy(INT_MIN);
	ListNode *pNode = &dummy;
	ListNode *pCurr=new ListNode(0);
	static uniform_int_distribution<int>u(0, 9);
	static default_random_engine e;
	for (size_t i = 0; i != 10; ++i) {
		pCurr = new ListNode(0);
		pCurr->val = u(e);
		pNode->next = pCurr;
		pNode = pNode->next;
	}

	ListNode *p = dummy.next;
	while (p) {
		cout <<p->val<<" ";
		p=p->next;
	}
	cout << endl;
	ListNode *q = dummy.next;
	ListSort sort;
	auto l=sort.insertionSortList(q);
	while (l) {
		cout << l->val << " ";
		l = l->next;
	}
	{
		cout << endl;
	}
	delete pCurr;
	pCurr = nullptr;
	ListNode dummy1(INT_MIN);
	ListNode* pHead = &dummy1;
	//ListNode* pCurr;
	for (int i = 0; i != 10; ++i) {
		pCurr = new ListNode(i);
		pHead->next = pCurr;
		pHead = pHead->next;
		//delete pCurr;
	}
	ListNode* pHead2 = dummy1.next;
	while (pHead2) {
		cout << pHead2->val << " ";
		pHead2 = pHead2->next;
	}
	cout << endl;
	ListNode *pHead3 = dummy1.next;
	sort.reorderList(pHead3);
	while (pHead3) {
		cout << pHead3->val << " ";
		pHead3 = pHead3->next;
	}
	cout << endl;
	ListNode *pHead4 = dummy1.next;
	sort.reorderList(pHead4);
	while (pHead4) {
		cout << pHead4->val << " ";
		pHead4 = pHead4->next;
	}
	cout << endl;
	ListNode *p1 = dummy.next;
	auto p2 = dummy1.next;
	sort.mergeTwoList(dummy.next,dummy1.next);
	ListNode *p3 =dummy.next;
	while(p3){
		cout << p3->val<<" ";
		p3 = p3->next;
	}
	cout << endl;
	system("pause");
}