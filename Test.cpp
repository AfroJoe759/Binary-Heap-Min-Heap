#include "MinHeap.h"

int main() {

	MinHeap mh;
	int choice;
	int position;
	int value;
	bool active = true;

	while (active == true) {
		cout << "Input the choice that matches the operation you wish to test" << endl;
		cout << "1 - insert\n2 - remove\n3 - findMin\n4 - deleteMin\n5 - increaseKey\n6 - decreaseKey\n7 - isEmpty" <<
			"\n8 - isFull\n9 - clear\n10 - printHeap\n11 - exit\nChoice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "Input a number you wish to insert: ";
			cin >> value;

			mh.insert(value); 
			cout << "Inserted: " << value << endl << endl;
			break;

		}
		case 2: {
			cout << "Input the position of the element you wish to remove: ";
			cin >> position;

			int removed = mh.remove(position);

			if (removed == -1) {
				cout << "The list is empty so nothing was removed" << endl;
			}

			else {
				cout << "Value removed from position " << position << ": " << removed << endl;
			}

			cout << endl;
			break;
		}
		case 3: {
			int min = mh.findMin();
			if (min == -1) {
				cout << "The list is empty" << endl;
			}

			else {
				cout << "Min Value: " << min << endl;
			}

			cout << endl;
			break;
		}
		case 4: {
			int deleted = mh.deleteMin();
			if (deleted == -1) {
				cout << "The list is empty so no number was deleted" << endl;
			}

			else {
				cout << "Deleted: " << deleted << endl;
			}

			cout << endl;
			break;
		}
		case 5: {
			cout << "Input the elements position: ";
			cin >> position;

			cout << "input the value to increase the element by: ";
			cin >> value;

			mh.increaseKey(position, value);
			cout << "The elements value has been increased" << endl << endl;
			break;
		}
		case 6: {
			cout << "Input the elements position: ";
			cin >> position;

			cout << "input the value to decrease the element by: ";
			cin >> value;

			mh.decreaseKey(position, value);
			cout << "The elements value has been decreased" << endl << endl;
			break;
		}
		case 7: {
			if (mh.isEmpty()) {
				cout << "The heap is empty!" << endl;
			}

			else {
				cout << "The heap is not empty" << endl;
			}

			cout << endl;
			break;
		}
		case 8: {
			if (mh.isFull()) {
				cout << "The heap is full!" << endl;
			}

			else {
				cout << "The heap is not full" << endl;
			}

			cout << endl;
			break;
		}
		case 9: {
			mh.clear();
			cout << "The heap has been cleared" << endl << endl;
			break;
		}
		case 10: {
			mh.printHeap();
			cout << endl;
			break;
		}
		case 11: {
			active = false;
			cout << endl;
			break;
		}

		default: {
			cout << "The number selected is not a valid option" << endl;
		}
		}
	}

	return 0;
}