#include<iostream>
#include"IntSet.h"

IntSet::IntSet()
{
	head = NULL;
	count = 0;
}

IntSet::IntSet(const IntSet &s)
{
	head = NULL;
	count = 0;
	node *p = s.head;
	for (int i = 0; i<s.count; i++)
	{
		operator+=(p->value);
		p = p->next;
	}
}

IntSet::IntSet(int intArray[], int length)
{
	head = new node;
	count = 0;
	if (!length)
		return;
	head->value = intArray[0];
	count++;
	node *p=head;
	for (int i = 1; i<length; i++)
	{	
		node *q = new node;
		q->value = intArray[i];
		p->next = q;
		p = p->next;
		count++;
	}
}

IntSet::~IntSet()
{
	for (int i = 0; i < count; i++) {
		node *p = head;
		head = head->next;
		delete p;
	}
	count = 0;
}

bool IntSet::is_element(int e) const
{
	node *p = head;
	for (int i = 0; i < count; i++) {
		if (p->value == e) return true;
		p = p->next;
	}

	return false;
}

void IntSet::print() const
{
	node *p = head;
	for (int i = 0; i < count; i++) {
		cout << p->value << ' ';
		p=p->next;
	}
	cout << endl;
}

IntSet& IntSet::operator+=(int e)
{
	if (!is_element(e))
	{
		node *p = new node;
		p->value = e;
		p->next = head;
		head = p;
		count++;
	}
	return *this;
}

IntSet& IntSet::operator-=(int e)
{
	if (is_element(e))
	{
		if (head->value == e)
		{
			node *p = head;
			head = head->next;
			delete p;
		}
		else
		{
			for (node *p = head; p->next != NULL; p = p->next)
			{
				if (p->next->value == e)
				{
					node *temp = p->next;
					p->next = temp->next;
					delete temp;
					break;
				}
			}
		}
		count--;
	}
	else
		cout << "元素" << e << "不属于当前集合！删除失败" << endl;
	return *this;
}

IntSet IntSet::operator|(const IntSet& s) const
{
	IntSet set(s);
	node *p = head;
	for (int i = 0; i < count; i++){
		if (!set.is_element(p->value))
			set.operator+=(p->value);
		p = p->next;
	}
	return set;
}

IntSet IntSet::operator&(const IntSet& s) const
{
	IntSet set;
	node *p = head;
	for (int i = 0; i < count; i++){
		if (s.is_element(p->value))
			set.operator+=(p->value);
		p = p->next;
	}
	return set;
}
