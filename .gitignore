#pragma once
#include <iostream> 
using namespace std;

struct node
{
	int value;
	node *next;
};

class IntSet
{
private:
	int count;
	node *head;
public:
	IntSet();
	IntSet(const IntSet& s);
	IntSet(int intArray[], int length);
	~IntSet();

	bool is_element(int e) const; //判断元素e是否属于当前集合

	void print() const; //向标准输出打印集合中的元素 
	IntSet& operator+=(int e); //添加元素
	IntSet& operator-=(int e); //删除元素
	IntSet operator|(const IntSet& s) const; //集合求并
	IntSet operator&(const IntSet& s) const; //集合求交
}; 
