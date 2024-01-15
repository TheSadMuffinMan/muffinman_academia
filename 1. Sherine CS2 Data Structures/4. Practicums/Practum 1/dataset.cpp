#include <iostream>
#include <math.h>
#include "dataset.h"
using namespace std;

dataset::dataset(ifstream& ins)
{

}

dataset::~dataset()
{
	// this function should destroy all dynamic members associated with this class
	// instance.
}

char* dataset::gettitle()
{
	// this function should return a pointer to an C string representing a title.
	// Please remember the concept of data hiding when writing this function.
}

int* dataset::getvalues()
{
	// this function should return a pointer to an array representing the dataset.
	// Please remember the concept of data hiding when writing this function.
}

int dataset::getnumdata() const
{
	return numvals;
}

// function finds the minimum value in the set and returns it to the caller.

double dataset::getmin() const
{
	double min = -1;

	for (int i = 0; i < numvals; i++)
	{
		if (i == 0)
			min = values[i];
		else
		{
			if (values[i] < min)
				min = values[i];
		}
	}
	return min;
}

// function finds the maximum value in the set and returns it to the caller.

double dataset::getmax() const
{
	double max = -1;

	for (int i = 0; i < numvals; i++)
	{
		if (i == 0)
			max = values[i];
		else
		{
			if (values[i] > max)
				max = values[i];
		}
	}
	return max;
}

// function computes the mean and returns it to the caller.

double dataset::getmean() const
{
	double total;

	for (int i = 0; i < numvals; i++)
		total += values[i];

	return (total / numvals);
}

// function computes median

double dataset::getmedian() const
{

	// write the function to compute the median - median is the middle value if the size
	// of the set is odd OR the average of the two middle values if even.
	// To do this, the set must be orderd.
}

// function computes std deviation

double dataset::getstddev() const
{
	double sum = 0;

	if (numvals == -1)
		return -1;

	for (int i = 0; i < numvals; i++)
	{
		double value_dev = values[i] - getmean();
		value_dev = value_dev * value_dev;
		sum += value_dev;
	}

	return (sqrt(sum / numvals));
}

