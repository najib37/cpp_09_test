#include <cstring>
#include <iostream>
#include <sstream>
#include <locale>
#include <cstring>
#include <iomanip>
#include <strings.h>


bool valid_date(const std::string &key)
{
    std::tm time;
    std::stringstream out;
    std::stringstream in;

	in << key;

	std::cout << "al7mar" << std::endl;
    in >> std::get_time(&time, "%Y-%m-%d");
	out << std::put_time(&time, "%Y-%m-%d");
	std::cout << "in = " << in.str() << std::endl;
	std::cout << "out = " << out.str() << std::endl;
	if (time.tm_mday <= 0 || time.tm_mon <= 0 || time.tm_year <= 0 || in.str() != out.str())
		return false;

	std::cout << "hanta " << time.tm_mon << std::endl;
	return true;
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "error" << std::endl;
		return 1;
	}
	std::cout << (valid_date(av[1]) ? "valid" : "invalid") << std::endl;
}
