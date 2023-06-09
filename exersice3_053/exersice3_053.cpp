#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** andri, Node** andini);
	bool listEmpty();
	bool delNode();
	void traverse();
};

//Menambahkan node pada sebuah list
void CircularLinkedList::addNode() {
	int rollno;
	string name;
	cout << "\nEnter the roll number : " << endl;
	cin >> rollno;
	cout << "\nEnter the name : " << endl;
	cin >> name;

	Node* nodeBaru = new Node();
	nodeBaru->rollNumber;
	nodeBaru->name;

	//Menambahkan node di awal list
	if (listEmpty()) {
		nodeBaru->next = nodeBaru;
		LAST = nodeBaru;
	}

	//Menambahkan node di antara 2 node
	else if (rollno < LAST->rollNumber || rollno < LAST->next->rollNumber) {
		Node* andini = LAST->next;
		Node* andri = NULL;

		while (andini != LAST && andini->rollNumber < rollno) {
			andri = andini;
			andini = andini->next;
		}
		andri->next = nodeBaru;
		nodeBaru->next = andini;
	}

	//Menambahkan node di akhir list
	else {
		nodeBaru->next = LAST->next;
		LAST->next = nodeBaru;
		LAST = nodeBaru;
	}
	cout << "Record added successfully" << endl;
}

//Cek apakah node yang dimaksud ada atau tidak
bool CircularLinkedList::search(int rollno, Node** andri, Node** andini) {
	*andri = LAST->next;
	*andini = LAST->next;
	while (*andini != LAST) {
		if (rollno == (*andini)->rollNumber) {
			return true;
		}
		*andri = *andini;
		*andini = (*andini)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

//Menghapus node dari dalam list
bool CircularLinkedList::delNode() {
	if (listEmpty()) {
		cout << "List Empty" << endl;
		return false;
	}

	int rollno;
	cout << "Enter roll number to delete : ";
	cin >> rollno;

	Node* andri = NULL;
	Node* andini = NULL;


	if (search(rollno, &andri, &andini)) {
		//Menghapus node di awal list
		if (andini == LAST) {
			if (LAST->next == LAST) {
				LAST = NULL;
			}
			else {
				LAST->next = andini->next;
			}
		}

		//Menghapus node di akhir list
		else if (andini->next == LAST) {
			andri->next = LAST;
		}

		//Menghapus node diantara 2 node
		else {
			andri->next = andini->next;
		}
		delete andini;
		cout << "Record deleted successfully" << endl;
		return true;
	}
		else {
			cout << "Record not found" << endl;
			return false;
		}
}

//Menampilkan semua node yang ada di dalam list
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are :\n";
		Node* andiniNode = LAST->next;
		while (andiniNode != LAST) {
			cout << andiniNode->rollNumber << " " << andiniNode->name << endl;
			andiniNode = andiniNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-4): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}