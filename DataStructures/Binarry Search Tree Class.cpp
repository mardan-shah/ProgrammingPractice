#include<iostream>
using namespace std;

#define COUNT 5
class node {
public:
	int data;
	node* left, * right;
	node(int val) {
		data = val;
		left = right = NULL;
	}
};

class BinaryTree {
public:
	BinaryTree() {
		root = NULL;
	}
	BinaryTree(int val) {
		root = new node(val);
	}
	//will check if tree is empty
	bool empty() {
		if (root == NULL)
			return true;
		return false;
	}
	//Insertion of data
	void insert(int val) {
		if (empty())
			root = new node(val);
		dataInsertion(root, val);
	}
	//in order traversal
	void InOrderDisplay() {
		cout << "In Order traversal : " << endl;
		inOrder(root);
		cout << endl;
	}
	//Pre order traversal
	void PreOrderDisplay() {
		cout << "Pre Order traversal : " << endl;
		preOrder(root);
		cout << endl;
	}
	//Post Order traversal
	void postOrderDisplay() {
		cout << "Post Order traversal : " << endl;
		postOrder(root);
		cout << endl;
	}
	//search
	void search(int val) {
		if (searchForVal(root, val)) {
			cout << "value exists" << endl;
		}
		cout << "value doesn't exists" << endl;
	}
	//Delete
	void deletevalue(int val) {
		del(root, val);
	}
	//mirror of BST
	void mirror() {
		if (empty()) {
			cout << "Tree is empty" << endl;
			return;
		}
		Mirror(root);
		cout << endl;
		cout << "Mirror Done" << endl;
	}
	//current level of node
	void currentLevel(int level) {
		cout << "Current level of tree" << endl;
		current(root, level);
	}
	//level order traversal
	void printLevelOrder() {
		allLevel(root);
	}
	// Wrapper over print2DUtil()
	void print2D() {
		// Pass initial space count as 0
		print2DUtil(root, 0);
	}

private:
	node* root;
	//recursive functions 

	//recursive insertion
	node* dataInsertion(node* root, int val) {
		if (root == NULL) {
			root = new node(val);
		}
		if (val < root->data)
			root->left = dataInsertion(root->left, val);
		else if (val > root->data)
			root->right = dataInsertion(root->right, val);
		return root;
	}
	//recursive InOrder Display
	void inOrder(node* root) {
		if (root == NULL) return;
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
	//pre Order recursion function
	void preOrder(node* root) {
		if (root == NULL) return;
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	//Post Order recursive funtion
	void postOrder(node* root) {
		if (root == NULL) return;
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
	//for search
	bool searchForVal(node* root, int val) {
		if (root == NULL) return false;

		if (root->data == val) return true;
		searchForVal(root->left, val);
		searchForVal(root->right, val);
		return false;
	}
	//Recursive delete
	node* del(node* root, int val) {
		if (root == NULL)return root;
		if (val < root->data)
			root->left = del(root->left, val);
		else if (val > root->data)
			root->right = del(root->right, val);
		else {
			if (isLeaf(root))
				root = NULL;
			else if (root->left == NULL) {
				node* temp = root->right;
				root = NULL;
				return temp;
			}
			else if (root->right == NULL) {
				node* temp = root->left;
				root = NULL;
				return temp;
			}
			node* temp = minNode(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);
		}
		return root;
	}
	//Minumum value Node
	node* minNode(node* root) {
		if (root->left == NULL)return root;
		return minNode(root->left);
	}
	//Check if value is leaf
	bool isLeaf(node* root) {
		if (root->left == NULL && root->right == NULL) return true;
		return false;
	}
	//recursive mirror
	void Mirror(node* root) {
		if (root == NULL) return;
		Mirror(root->left);
		Mirror(root->right);
		swap(root->left, root->right);
	}
	//function to measure height
	int height(node* root)
	{
		if (root == NULL)
			return 0;
		else {
			int leftHeight = height(root->left);
			int rightHeight = height(root->right);

			if (leftHeight > rightHeight) {
				return (leftHeight + 1);
			}
			else {
				return (rightHeight + 1);
			}
		}
	}
	//function to print all levels
	void allLevel(node* root) {
		int h = height(root);
		for (int i = 1; i <= h; i++) {
			cout << "level " << i << " : ";
			current(root, i);
			cout << endl;
		}
	}
	//function to print current level of array
	void current(node* root, int level) {
		if (root == NULL)
			return;
		if (level == 1) {
			cout << root->data << " ";
		}
		else if (level > 1) {
			current(root->left, level - 1);
			current(root->right, level - 1);
		}
	}


	//2D TREE
	void print2DUtil(node* root, int space)
	{
		if (root == NULL)
			return;

		space += COUNT;

		print2DUtil(root->right, space);

		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << root->data << "\n";

		// Process left child
		print2DUtil(root->left, space);
	}
};

//functions
void menu();
void doTask(BinaryTree* obj);

int main() {
	int data;
	BinaryTree obj;
	cout << "Enter data and press -1 to exit" << endl;
	while (1) {
		cin >> data;
		if (data < 0) break;
		obj.insert(data);
	}
	doTask(&obj);


	return 0;
}

void menu() {
	system("cls");
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "0.Exit" << endl;
	cout << "1.Input Nuber" << endl;
	cout << "2.In Ordered traversal" << endl;
	cout << "3.Pre Order traversal" << endl;
	cout << "4.Post Order traversal" << endl;
	cout << "5.Level Order traversal" << endl;
	cout << "6.Display 2d Binary Search tree" << endl;
	cout << "7.Mirror Tree" << endl;
	cout << "8.Delete Node from Tree" << endl;
	cout << "9.Search for Value" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
}

void doTask(BinaryTree* obj) {
	int choice;
	while (1) {
		menu();
		cin >> choice;
		if (choice == 0) {
			cout << "Thank you for using" << endl;
			break;
		}
		else if (choice == 1) {
			cout << "Enter Number : ";
			cin >> choice;
			obj->insert(choice);
			obj->InOrderDisplay();
		}
		else if (choice == 2) {
			obj->InOrderDisplay();
		}
		else if (choice == 3) {
			obj->PreOrderDisplay();
		}
		else if (choice == 4) {
			obj->postOrderDisplay();
		}
		else if (choice == 5) {
			obj->printLevelOrder();
		}
		else if (choice == 6) {
			cout << "\t\t\t\t2D REPRESENTATION OF TREE" << endl;
			obj->print2D();
		}
		else if (choice == 7) {
			obj->mirror();
		}
		else if (choice == 8) {
			cout << "Enter the node you want to delete" << endl;
			cin >> choice;
			obj->deletevalue(choice);
		}
		else if (choice == 9) {
			cout << "Enter value you want to search" << endl;
			cin >> choice;
			obj->search(choice);
		}
		else {
			cout << "Wrong Entry Try again" << endl;
		}
		system("pause");
	}
}
