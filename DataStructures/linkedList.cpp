#include<iostream>
using namespace std;

//Node Class
class node {
public:
	int data;
	node* next;
	node(int val) {
		data = val;
		next = nullptr;
	}
};
//linked list class
class li {

public:
	li(){
		head = nullptr;
	}
	li(int val) {
		head = new node(val);
	}
	//will check if the list is empty or not
	bool empty() {
		if (head == nullptr)
			return true;
		return false;
	}
	//will insert the value at the very end
	void insertAtEnd(int val) {
		if (empty()) {
			head = new node(val);
			return;
		}
		node* i = head; //	i is the iterator that will help us move to the last node
		while (i->next != nullptr)
			i = i->next;
		i->next = new node(val);
	}
	//insert value at end
	void insertAtStart(int val){
		node* temp = new node(val);
		temp->next = head;
		head = temp;
	}
	//delete value at end
	void deleteEnd() {
		if (empty()) {
			cout << "List is empty" << endl;
			return;
		}
		node* i;
		for (i = head; i->next->next != nullptr; i = i->next);
		i->next = nullptr;
	}
	//delete value at start
	void deleteStart() {
		if (empty()) {
			cout << "List is empty" << endl;
			return;
		}
		head = head->next;
	}
	//Display
	void display() {
		if (empty()) {
			cout << "List is empty" << endl;
			return;
		}
		for (node* i = head; i != nullptr; i = i->next)
			cout << i->data << ",";
		cout << endl;
	}
	//Display Reverse
	void reverseDisplay() {
		if (empty()) {
			cout << "List is empty" << endl;
			return;
		}
		reDisplay(head);
		cout << endl;
	}
private:
	node* head;	//head pointer of node datatype
	//Recursive functions to display
	void reDisplay(node* temp) {
		if (temp==nullptr) {
			return;
		}
		reDisplay(temp->next);
		cout << temp->data << ",";
	}
};

//Function Prototypes
void listDisplay(li);
void reverseDisplay(li obj);
int main() {
	li obj;
	obj.insertAtEnd(1);
	obj.insertAtEnd(2);
	obj.insertAtEnd(3);
	obj.insertAtEnd(4);
	obj.insertAtEnd(5);
	obj.insertAtEnd(6);
	listDisplay(obj);
	obj.deleteEnd();
	listDisplay(obj);
	obj.deleteStart();
	listDisplay(obj);
	obj.insertAtStart(55);
	listDisplay(obj);


	system("pause");
	return 0;
}

void listDisplay(li obj) {
	cout << "List : ";
	obj.display();
}
void reverseDisplay(li obj) {
	cout << "Reverse list : ";
	obj.reverseDisplay();
}
