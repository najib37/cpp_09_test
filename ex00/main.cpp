/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:09 by nramadan          #+#    #+#             */
/*   Updated: 2023/03/24 17:24:12 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
#include <_ctype.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

void print_two(std::pair<std::string, std::string> mypair)
{
	std::cout << mypair.first << " = " << mypair.second << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	
	Btc btc("data.csv");
	btc.parse_file(av[1]);
	// btc.print();
}
