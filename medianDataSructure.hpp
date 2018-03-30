
class MedianDS
{
public:
	MedianDS();
	~MedianDS();

	void push(int Value);
	double getMedian();
	void clear();
	void print();

private:
	std::list<int> medianHolder;

};