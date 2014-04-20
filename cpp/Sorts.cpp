#include "Sorts.h"

void xchg(short& a, short& b)
{
	short temp = a;
	a = b;
	b = temp;
	return;
}

// Selection Sort implementation 
void selectionSort(vector<short int> & vec)
{
	//cout << "Selections Sort" << endl;
	short size = vec.size();
	short minIndex = 0; // keep track of the index with the current min value
	for(short i=0; i<size; i++) // iterate through whole vector
	{
		minIndex = i; // initialize the min index to current index
		for(short j=i+1; j<size; j++) // go through rest of vector looking for a new min value
		{
			if(vec[j] < vec[minIndex]) // if you find new min value
				minIndex = j;			// update to new min index
		}
		if(i != minIndex) // if min index is different from current index swap the values
			xchg(vec[i], vec[minIndex]); //swap elements
	}
	return;
}

// Insertion Sort implementation
void insertionSort(vector<short> & vec)
{
	//cout << "insertion sort" << endl;
	short size = vec.size();
	short i, j; // variables to iterate through vector
	for(i=1; i<size; i++) // start @ 2nd element because 1st is trivially sorted
	{
		j = i;
		while(j>0 && vec[j-1] > vec[j]) //if the one to the left is smaller then exchange
		{
			xchg(vec[j-1], vec[j]);
			j--; //decrement j index, go towards the left
		}
	}
}

// Shell sort implementation
void shellSort(vector<short> & vec)
{
	//first calculate gap [h] values using 2^k-1 where k >= 1
	short size = vec.size();
	vector<short> gaps(0);
	short k=2;
	short gap=1;
	while(gap<size) // add gaps to vector of gaps logest must be smaller than size of vector
	{
		gaps.push_back(gap);
		gap = pow(2,k++)-1;
	}
	//short gapIndex = gaps.size()-1;
	for(short gapIndex = gaps.size()-1; gapIndex >= 0; gapIndex--)
	{
		for(short i=gaps[gapIndex]; i < size; i++)
		{
			short temp = vec[i];
			short j;
			for(j=i; j>=gaps[gapIndex] && vec[j-gaps[gapIndex]] > temp; j-=gaps[gapIndex])
			{
				vec[j] = vec[j-gaps[gapIndex]];
			}
			vec[j] = temp;
		}
	}
}

/*************** Merge Sort ***************/
void mergeSort(vector<short>& vec)
{
	mergeSortHelper(vec, 0, vec.size()-1);
}

void mergeSortHelper(vector<short>& vec, short low, short high)
{
	if(low < high)
	{
		short mid = (low+high)/2; // low+(high-low)/2
		mergeSortHelper(vec, low, mid);
		mergeSortHelper(vec, mid+1, high);
		merge(vec, low, mid, high);
	}
}

void merge(vector<short> & vec, short low, short mid, short high)
{
	short leftIndex = low; // index for the left array
	short rightIndex = mid+1; // index for the right array
	vector<short> tempVec (0);

	while(leftIndex <= mid && rightIndex <= high)
	{
		if(vec[leftIndex] < vec[rightIndex])
		{
			tempVec.push_back(vec[leftIndex]);
			leftIndex++;
		}else{
			tempVec.push_back(vec[rightIndex]);
			rightIndex++;
		}
	}
	while(leftIndex <= mid)
	{
		tempVec.push_back(vec[leftIndex++]);
	}
	while(rightIndex <= high){
		tempVec.push_back(vec[rightIndex++]);
	}

	short vecIndex = low;
	for(unsigned short i=0; i<tempVec.size(); i++)
		vec[vecIndex++] = tempVec[i];
}

/*************** Quick Sort ***************/
// Quick Sort - with a random pivot
void quickSort(vector<short>& vec)
{
	quick_sort(vec, 0, vec.size()-1); // call helper function with values
}

// quick sort algo actuall starts here
void quick_sort(vector<short>& vec, short low, short high)
{
	if(low < high)
	{
		short q = random_partition(vec, low, high); // get pivot in correct position
		quick_sort(vec, low, q-1); // recursively sort the left sub array
		quick_sort(vec, q+1, high); // recursively sort the right sub array
	}
}

// to make quicksort perform slightly better use a randomized pivot
short random_partition(vector<short>& vec, short low, short high)
{
	short i = rand()%(high-low+1)+low; // get random value between low and high
	xchg(vec[i], vec[high]);
	return partition(vec, low, high); // call the real partition function
}

// quick sort helper functions
short partition(vector<short>& vec, short low, short high)
{
	short pivot = vec[high]; // set pivot to the last element
	short i = low-1; // index
	// for loop to place values is left sub array < pivot value < right sub array
	for(short j=low; j < high; j++) // from begining to end of current sub array
	{
		if(vec[j] <= pivot) // if value is less than pivot
		{
			i++;
			xchg(vec[i], vec[j]); // move to the left sub array
		}
	}
	xchg(vec[i+1], vec[high]); // move pivot to its correct position
	return i+1; // return pivot index
}