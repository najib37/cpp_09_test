/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorInsertionSort.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:52:13 by nramadan          #+#    #+#             */
/*   Updated: 2023/04/09 15:52:20 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <cstdlib>

void VectorInsertionSort(std::vector<int> &arr)
{
	int temp;
	bool isStraggler = false;
	std::vector<int>::iterator it;
	std::vector<std::pair<int, int> > vpairs;
	std::vector<std::pair<int, int> >::iterator vit;

	it = arr.begin();
	vpairs.reserve(arr.capacity() / 2 + 1);
	while (it + 2 <= arr.end())
	{
		if (it + 2 <= arr.end())
			vpairs.push_back(std::make_pair(std::min(*it, *it + 1), std::max(*it, *it + 1)));
		std::advance(it, 2);
	}
	if (it != arr.end())
	{
		temp = arr.back();
		isStraggler = true;
	}
	std::sort(vpairs.begin(), vpairs.end());
	arr.erase(arr.begin(), arr.end());
	vit = vpairs.begin();
	while (vit != vpairs.end())
	{
		arr.push_back(vit->first);
		vit++;
	}
	vit = vpairs.begin();
	if (isStraggler)
	{
		it = std::upper_bound(arr.begin(), arr.end(), temp);
		arr.insert(it, temp);
	}
	while (vit != vpairs.end())
	{
		it = std::upper_bound(arr.begin(), arr.end(), vit->second);
		arr.insert(it, vit->second);
		vit++;
	}
	// std::for_each(arr.begin(), arr.end(), printi);
}
