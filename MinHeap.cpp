#include "MinHeap.h"

MinHeap::MinHeap() {
	size = 0;
	maxSize = 10;
	heap = new int[maxSize];
}

void MinHeap::percolateUp(int position) {
	int parent = position / 2; //formula to find the parents position
	int index = position; //position of the child  

	//if the child value is less than the parents, swap
	while (parent != 0 && heap[index] < heap[parent]) {
		int temp = heap[parent];
		heap[parent] = heap[index];
		heap[index] = temp;

		index = parent;
		parent = parent / 2;
	}
}

void MinHeap::percolateDown(int position) {
	int left = position * 2; //location of left child
	int right = (position * 2) + 1; //location of right child
	int index = position; //position of the element to be shifted

	//evaluates whether or not 
	while (left <= size || right <= size) {
		int temp = heap[index];

		//swaps with left child
		if (heap[left] < heap[right] && heap[index] > heap[left]) {
			heap[index] = heap[left];
			heap[left] = temp;
			index = left;
		}

		//swaps with right child
		else if (heap[right] < heap[left] && heap[index] > heap[right]) {
			heap[index] = heap[right];
			heap[right] = temp;
			index = right;
		}

		else {
			break;
		}

		left = index * 2;
		right = (index * 2) + 1;
	}
}

void MinHeap::insert(int element) {
	if (!isFull()) {
		heap[size + 1] = element; //inserts element at end of array

		//shifts elements up the heap if possible
		if (size > 0) {
			percolateUp(size + 1);
		}

		size++;
	}
}

int MinHeap::findMin() {
	if (!isEmpty()) {
		return heap[1];
	}

	else {
		return -1;
	}
}

int MinHeap::deleteMin() {
	int min = -1;

	if (!isEmpty()) {
		min = heap[1];

		if (size == 1) {
			size--;
		}

		//replaces first element in a heap with the value of the last element
		//remove the last element from the list
		//perculate the new first element down the list
		else {
			heap[1] = heap[size];
			size--;
			percolateDown(1);
		}
	}

	return min;
}

int MinHeap::remove(int position) {
	int removed = -1;

	//set the element in the specified position to smallest number in heap - 1
	//perculate the number upwards in order to make it the root
	//perform the delete min opertion
	if (!isEmpty()) {
		removed = heap[position];
		int min = findMin();
		heap[position] = min - 1;

		percolateUp(position);
		min = deleteMin();
	}

	return removed;
}

void MinHeap::increaseKey(int position, int increaseValue) {
	int element = heap[position];
	int keyValue = element + increaseValue;
	heap[position] = keyValue;

	percolateDown(position);
}

void MinHeap::decreaseKey(int position, int decreaseValue) {
	int element = heap[position];
	int keyValue = element - decreaseValue;
	heap[position] = keyValue;

	percolateUp(position);
}

bool MinHeap::isEmpty() {
	if (size == 0) {
		return true;
	}

	return false;
}

bool MinHeap::isFull() {
	if (size + 1 == maxSize) {
		return true;
	}

	return false;
}

void MinHeap::clear() {
	size = 0;
}

void MinHeap::printHeap() {

	cout << "Heap: ";
	for (int i = 1; i <= size; i++) {
		cout << heap[i] << " ";
	}

	cout << endl;
}
