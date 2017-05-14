// Priority_Queue.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "string"
#include <iostream>

using namespace std;

class priority_queue
{
	int *tree, length;
public:
	priority_queue(int n) : length(0)
	{
		tree = new int[n];
	}
	void get()
	{
		cout << tree[0] << endl;
	}
	void add(int value);
	void del();
	void print()
	{
		for (int i = 0; i < length; i++)
		{
			cout << tree[i] << " ";
		}
		cout << endl;
	}
	~priority_queue()
	{
		if (tree)
			delete[] tree;
	}
};

void priority_queue::add(int value)
{
	int node_num = length;
	tree[node_num] = value;
	int parent_index = (node_num - 1) / 2;
	while (tree[parent_index] > value && node_num != 0)
	{
		tree[node_num] = tree[parent_index];
		tree[parent_index] = value;
		node_num = parent_index;
		parent_index = (node_num - 1) / 2;
	}
	length += 1;
	print();
}

void priority_queue::del()
{
	int node_num = 0;
	int left = 1, right = 2, value = tree[length - 1];
	tree[node_num] = tree[length - 1];
	length--;
	while (node_num <= length - 1 && value > tree[left] && value > tree[right])
	{
		int index;
		if (tree[left] > tree[right])
			index = right;
		else
			index = left;
		tree[node_num] = tree[index];
		tree[index] = value;
		node_num = index;
		left = node_num * 2 + 1;
		right = node_num * 2 + 2;
	}
	print();
}


int main()
{
	int n;
	string cmd;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите количество чисел: ";
	cin >> n;
	priority_queue pq(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			int value;
			cin >> value;
			pq.add(value);
		}
	}
back:cin >> cmd;
	if (cmd == "del")
		pq.del();
	if (cmd == "get")
		pq.get();
	if (cmd == "exit")
		return 0;
	goto back;
	system("pause");
}

