/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:31:11 by nramadan          #+#    #+#             */
/*   Updated: 2023/04/09 15:50:49 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BTC__
#define __BTC__

#include <iomanip>
#include <ctime>
#include <algorithm>
#include <utility>
#include <iostream>
#include <_ctype.h>
#include <fstream>
#include <sstream>
#include <map>
#include <_ctype.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <utility>
#include <vector>

class Btc
{
	private:
		std::map<std::string, std::string> database;
	public:
		Btc(std::string name);
		Btc(const Btc &);
		Btc &operator=(const Btc &);
		~Btc();
		void parse_file( std::string );
		// long convert_time( const std::string &);
		bool valid_date(const std::string &);
		void split_string(const std::string &, std::string &, std::string &, const std::string &);
		void print_pair(std::string &, std::string &);
};

bool is_allowed(char c);
bool is_sign(char c);

#endif
