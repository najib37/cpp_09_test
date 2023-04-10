/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:18:31 by nramadan          #+#    #+#             */
/*   Updated: 2023/03/24 17:18:32 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

Btc::Btc(std::string name)
{
	std::ifstream file(name);
	std::string key, value, temp;
	size_t a = 1;

	if (!file.is_open())
	{
		std::cerr << "error: unable to open the database file" << std::endl;
		exit(1);
	}
	std::getline(file, temp);
	if (temp != "date,exchange_rate")
		file.seekg(std::ios_base::beg);
	while (!file.eof())
	{
		std::getline(file, temp);
		if (temp.empty())
			continue;
		split_string(temp, key, value, ",");
		if (key.empty() || value.empty())
		{
			std::cerr << "error: parsing database" << std::endl;
			exit(1);
		}
		if (!valid_date(key))
		{
			std::cerr << "error: invalid time at line number: " << a << std::endl;
			exit(1);
		}
		database.insert(std::make_pair(key, value));
		a++;
	}
}

Btc::Btc(const Btc &other) : database(other.database)
{
}

Btc &Btc::operator=(const Btc &other)
{
	database = other.database;
	return (*this);
}

Btc::~Btc()
{
}

bool is_sign(char c)
{
	return (c == '+' || c == '-');
}

bool is_allowed(char c)
{
	return (!isdigit(c) && c != '.' && c != '+' && c != '-');
}

void Btc::split_string(const std::string &line, std::string &key, std::string &value,
				  const std::string &limiter)
{
	unsigned long a = 0;
	key.clear();
	value.clear();
	
	a = line.find(limiter);
	if (a == std::string::npos)
	{
		key = line;
		return;
	}
	key = line.substr(0, a);
	value = &line[a + limiter.length()];
}


bool Btc::valid_date(const std::string &key)
{
    std::tm time;
    std::stringstream out;
    std::stringstream in;

	in << key;
    in >> std::get_time(&time, "%Y-%m-%d");
	out << std::put_time(&time, "%Y-%m-%d");
	if (!time.tm_mday || !time.tm_year || in.str() != out.str())
		return false;

	return true;
}

void Btc::parse_file(std::string filename)
{
	std::ifstream file(filename);
	std::string key, value, temp;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(1);
	}
	std::getline(file, temp);
	if (temp != "date | value")
		file.seekg(std::ios_base::beg);
	while (!file.eof())
	{
		temp.clear();
		std::getline(file, temp);
		if (temp.empty())
			continue;
		split_string(temp, key, value, " | ");
		print_pair(key, value);
	}
}

float check_price_error(const std::string &price, const std::string &date)
{
	float fnum;
	char *str;

	fnum = strtod(price.c_str(), &str);	
	if (*str || std::find_if(price.begin(), price.end(), is_allowed) != price.end())
	{
		std::cerr << "Error: bad input => " << date;
		if (!price.empty())
			std::cerr << " | " << price << std::endl;
		else std::cerr << std::endl;
		return (-1);
	}
	if (fnum > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (-1);
	}
	else if (fnum < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (-1);
	}
	
	return (fnum);
}

void Btc::print_pair(std::string &date, std::string &price)
{
	float fnum = check_price_error(price, date);
	float product;
	std::map<std::string, std::string>::iterator it;

	if (fnum == -1)
		return;
	if (!valid_date(date))
	{
		std::cerr << "Error: bad input => " << date;
		if (!price.empty())
			std::cerr << " | " << price << std::endl;
		else std::cerr << std::endl;
		return;
	}

	it = database.upper_bound(date);
	if (date != it->first)
		--it;
	product = strtod(it->second.c_str(), NULL) * fnum;
	std::cout << date << " => " << fnum << " = " << product << std::endl;
}
