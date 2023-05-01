/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:52:36 by nramadan          #+#    #+#             */
/*   Updated: 2023/04/09 15:52:37 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER__
#define __HEADER__

#include <_ctype.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include <sys/time.h>

void print(std::pair<int, int> mypair);
void printi(int a);
void parse(char **av, std::vector<int>&v_arr, std::deque<int> &d_arr);
std::pair<int, int> myMinMax(int a, int b);
void VectorInsertionSort(std::vector<int> &arr);
void DequeInsertionSort(std::deque<int> &arr);

#endif
