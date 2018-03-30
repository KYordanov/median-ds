#include <list>
#include <iostream>
#include <algorithm>
#include <stdio.h>

class MedianDS
{
public:
	MedianDS();
	~MedianDS();

	void pushBack(int insertVal);
	void pushBefore(int pushAfterVal, int Value);
	double getMedian();
	void clearLastAdded();
	void print();

private:
	std::list<int> medianHolder;
	int lastAddedSum;
	
};

MedianDS::MedianDS()
{
	lastAddedSum = 0;
}

MedianDS::~MedianDS()
{
}

void MedianDS::pushBack(int Value)
{
	lastAddedSum += Value;
	medianHolder.push_back(Value);
}

double MedianDS::getMedian()
{
	return (double)lastAddedSum / medianHolder.size();
}

void MedianDS::pushBefore(int pushAfterVal, int Value)
{
	lastAddedSum += Value;
	std::list<int>::iterator it = std::find(medianHolder.begin(), medianHolder.end(), pushAfterVal);
	if (it != medianHolder.end()) {
		medianHolder.insert(it, Value);
	}
}

void MedianDS::clearLastAdded()
{
	medianHolder.clear();
	lastAddedSum = 0;
}


void MedianDS::print()
{
	std::list<int>::iterator it;
	
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

	myMedianDS.pushBack(1);
	myMedianDS.pushBack(2);
	myMedianDS.pushBack(3);
	myMedianDS.pushBack(4);
	myMedianDS.print();

	myMedianDS.pushBefore(3, 30);
	myMedianDS.print();

	myMedianDS.clearLastAdded();
	std::cout << "Values Cleared\n";
	std::cout << "---------\n";

	for(int i = 0; i < 10; i++)
		myMedianDS.pushBack(i * 15);

	myMedianDS.pushBefore(45, 7);
	myMedianDS.print();

	return 0;
}

