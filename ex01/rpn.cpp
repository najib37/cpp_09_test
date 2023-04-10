#include <cctype>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>

bool is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void opertion(std::stack<int> &polish, char oper)
{
	int temp = 0;

	temp = polish.top();
	polish.pop();
	if (oper == '+')
		polish.top() += temp;
	else if (oper == '-')
		polish.top() -= temp;
	else if (oper == '*')
		polish.top() *= temp;
	else if (oper == '/')
		polish.top() /= temp;
}

void rpn(std::string line)
{
	std::stack<int> polish;
	std::string::iterator it = line.begin();

	while (it != line.end())
	{
		if (isdigit(*it))
			polish.push(*it - '0');
		else if (is_operator(*it) && polish.size() > 1)
			opertion(polish, *it);
		else if (!isspace(*it))
		{
			std::cout << "error: not a valid input" << std::endl;
			return ;
		};
		++it;
	}
	if (!polish.empty())
		std::cout << polish.top() << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "error: not a valid input" << std::endl;
		return 1;
	}
	rpn(av[1]);
}
