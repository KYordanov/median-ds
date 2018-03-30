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

