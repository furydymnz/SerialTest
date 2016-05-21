#pragma once
class RingBuffer {

public:
	RingBuffer(int size) 
	{
		index = 0;
		this->size = size;
		buffer = new int[size];
		memset(buffer, 0, sizeof(buffer));
	}

	~RingBuffer()
	{
		delete buffer;
	}

	void push(int data)
	{
		buffer[index] = data;
		index = (index + 1) % size;
	}

	double calculateAverage()
	{
		double sum = 0;

		for (int i = 0; i < size; i++)
			sum += buffer[i];

		return sum / size;
	}

private:
	int *buffer;
	int index;
	int size;
};
