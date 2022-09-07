
#include <unordered_set>
#include <iostream>
#include <list>

int main()
{
	std::list<int> a{1,2,3,4,5,6,7,8,9};
	auto it = a.begin();
	for(int i=0;i<10;i++)
	{
		a.insert(it, i);
	}
	for(auto &s:a)
	{
		std::cout << s << std::endl;
	}
}