#include <iostream>

using namespace std;

class MinHeap {

public: 
	MinHeap();

	void insert(int element); //inserts element into the heap, takes O(log(n)) time

	int findMin(); //finds and returns the smallest element in the heap, takes O(1) time
	int deleteMin(); //deletes the smallest element in the heap and returns it, takes O(log(n)) time

	int remove(int position); //removes elements from a specific position

	void increaseKey(int position, int increaseValue); //increases the value of an element at a specific position and shifts it depending on result
	void decreaseKey(int position, int increaseValue); //decreases the value of an element at a specific position and shifts it depending on result

	bool isEmpty(); //determines if the heap is empty
	bool isFull(); //determines if the heap is full or not

	void clear(); //deletes all elements within the heap

	void printHeap(); //prints out the contents of the heap

	void buildHeap(int list[], int listSize); //builds the heap from a list of elements, takes O(N) time
	int findKthLargest(int list[], int listSize, int k); //finds the Kth largest from a given list
private: 

	void percolateUp(int position); //moves element down in the heap if necessary
	void percolateDown(int position); //moves element up the heap if necessary

	int size; //current amount of elements in the heap
	int maxSize; //maximun numberof elements allowed in heap
	int *heap; //array that represents elements in a heap
};