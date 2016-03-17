#include<iostream>
#include"IntSet.h"
using namespace std;

int main()
{
	int a[5] = {0,1,2,3,4}, b[5] = { 0,1,6,7,8 };
	IntSet A(a, 5), B(b, 5);
	A += (5);
	A -= (3);

	A.print();
	B.print();
	(A&(B)).print();
	(A|(B)).print();
	return 0;
}
