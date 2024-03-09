#include"Set.cpp"
#include<iostream>

using namespace std;

int main()
{
	Set<int> a;

	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	cout << a.size() << endl;
	a.del(3);
	cout << a.size() << endl;

	Set<char> b;
	b.add('a');
	b.add('b');
	b.add('c');
	cout << b.size() << endl;
}