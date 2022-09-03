#include <iostream>
#include <concurrent_priority_queue.h>
#include <vector>
#include <queue>


template<typename Q>
void print_queue1(std::string_view name, Q q) {
	// NB: q is passed by value because there is no way to traverse
	// priority_queue's content without erasing the queue.
	for (std::cout << name << ": \t"; !q.empty(); q.pop())
		std::cout << q.top() << ' ';
	std::cout << '\n';
}

template <typename  T>
void print_queue(std::string name,T  q)
{
	for(std::cout<<name<<":\t";!q.empty(); q.pop())
	{
		std::cout << q.top() << " ";
	}
	std::cout << '\n';
}
int main()
{
	struct test
	{
		bool operator()(const int a,const int b)
		{
			return a > b;
		}
	};
	std::vector<int> q{ 1,3,1,1,2,9,1,0,3,2,31,1,0 };
	std::priority_queue<int, std::vector<int>, test> b;
	for(auto a:q)
	{
		b.push(a);
	}
	print_queue("haha", b);
	

}