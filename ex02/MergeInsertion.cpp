/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:52:01 by nramadan          #+#    #+#             */
/*   Updated: 2023/04/09 15:52:02 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void print(std::pair<int, int> mypair)
{
	std::cout << "[" << mypair.first << " , " << mypair.second << "]";
}

void printi(int a)
{
	std::cout << a << " ";
}

void parse(char **av, std::vector<int>&v_arr, std::deque<int> &d_arr)
{
	++av;
	while (*av)
	{
		if (**av && **av == '+')
			(*av)++;

		if ( !**av || (!isdigit(**av)) )
		{
			std::cerr << "error: unvalid input" << std::endl;
			exit(1);
		}
		v_arr.push_back(atoi(*av));
		d_arr.push_back(atoi(*av));
		av++;
	}
}

long GetTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long(tv.tv_sec *  1000000) + tv.tv_usec);
}

int main(int ac, char **av)
{
	long timeStart;
	long timeEnd;
	std::vector<int> v_arr;
	std::deque<int> d_arr;

	if (ac <= 1)
	{
		std::cerr << "error: unvalid input" << std::endl;
		return 1;
	}

	parse(av, v_arr, d_arr);

	std::cout << "Before: ";
	std::for_each(v_arr.begin(), v_arr.end(), printi);
	std::cout << std::endl;

	timeStart = GetTime();
	VectorInsertionSort(v_arr);
	timeEnd = GetTime();
	
	std::cout << "After: ";
	std::for_each(v_arr.begin(), v_arr.end(), printi);
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << v_arr.size() 
		<< " elements with std::vector : " 
		<< float(timeEnd - timeStart) << " us" << std::endl;

	timeStart = GetTime();
	DequeInsertionSort(d_arr);
	timeEnd = GetTime();

	// std::for_each(d_arr.begin(), d_arr.end(), printi);
	std::cout << "Time to process a range of " << d_arr.size() 
		<< " elements with std::deque : "
		<< float(timeEnd - timeStart) << " us" << std::endl;
}
