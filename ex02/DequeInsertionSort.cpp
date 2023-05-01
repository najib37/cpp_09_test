/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeInsertionSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:51:36 by nramadan          #+#    #+#             */
/*   Updated: 2023/04/09 15:51:37 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void DequeInsertionSort(std::deque<int> &arr)
{
	int temp;
	bool isStraggler = false;
	std::deque<int>::iterator it;
	std::deque<std::pair<int, int> > vpairs;
	std::deque<std::pair<int, int> >::iterator vit;

	it = arr.begin();
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
	vit = vpairs.begin();
	arr.clear();
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
