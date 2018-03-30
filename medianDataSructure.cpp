#include <list>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "medianDataSructure.hpp"

MedianDS::MedianDS()
{
}

MedianDS::~MedianDS()
{
}

void MedianDS::push(int Value)
{
	medianHolder.push_back(Value);
}

double MedianDS::getMedian()
{
	double median = 0;
	std::list<int>::iterator it = medianHolder.begin();
	medianHolder.sort();
	if (0 == (medianHolder.size() % 2))
	{//even
		for (size_t i = 0; i < medianHolder.size() / 2; i++)
		{
			it++;
		}
		median = ((double)*it + *--it) / 2;
	}
	else
	{//odd
		for (size_t i = 0; i < medianHolder.size() / 2; i++)
		{
			it++;
		}
		median = *it;
	}
	return median;
}

void MedianDS::clear()
{
	medianHolder.clear();
}


void MedianDS::print()
{
	std::list<int>::iterator it;

	medianHolder.sort();
	std::cout << "Last added values: \n";
	for (it = medianHolder.begin(); it != medianHolder.end(); it++)
		std::cout << "[" << *it << "]";

	std::cout << "\n";
	std::cout << "Median of the values: " << getMedian() << "\n";
	std::cout << "Number of values: " << medianHolder.size() << "\n";
	std::cout << "---------\n";
}


int main()
{
	MedianDS myMedianDS;

	myMedianDS.push(1);
	myMedianDS.push(2);
	myMedianDS.push(3);
	myMedianDS.push(12);
	myMedianDS.print();

	myMedianDS.clear();
	std::cout << "Values Cleared\n";
	std::cout << "---------\n";

	for(int i = 0; i < 10; i++)
		myMedianDS.push(i * 15);

	myMedianDS.push(63);
	myMedianDS.print();

	return 0;
}

