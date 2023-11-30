#include<iostream>
#include <string>
using namespace std;
class tree {
public:
	string name;
	tree* left;
	tree* right;
	tree* root;
	tree() {
		name = "";
		left = NULL;
		right = NULL;
		root = NULL;
	}
	tree* insert(tree* root, string n) {
		tree* temp = new tree;
		temp->name = n;
		temp->left = NULL;
		temp->right = NULL;
		if (root == NULL) {
			root = temp;
		}
		if (n < root->name) {
			root->left = insert(root->left, n);
		}
		if (n > root->name) {
			root->right = insert(root->right, n);
		}
		return root;
	}
	tree* preorder(tree* root) {
		if (root == NULL)
		{
			return root;
		}
		cout << root->name << " ";
		preorder(root->left);
		preorder(root->right);
	}
	bool search(tree* root, string key) {
		if (root == NULL)
		{
			cout << "No Data exist" << endl;
			return false;
		}
		if (root->name == key)
		{
			cout << "Found";
			return true;
		}
		else if (key > root->name)
		{
			search(root->right, key);
		}
		else
		{
			search(root->left, key);
		}
	}
	tree*inpred(tree*root){
		if (root == NULL){
			return root;
		}
		else{
			root = root->left;
			while (root->right != NULL){
				root = root->right;
			}
		}
		return root;
	}
	tree*postpred(tree*root){
		if (root == NULL){
			return root;
		}
		else{
			root = root->right;
			while (root->left != NULL){
				root = root->left;
			}
		}
		return root;
	}
	tree* deletedata(tree*root, string key){
		if (root == NULL){
			cout << "Directory is empty.\n";
			return NULL;
		}
		if (root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}
		if (root->name > key){
			root->left = deletedata(root->left, key);
		}
		else if (root->name < key){
			root->right = deletedata(root->right, key);
		}
		else{
			tree*temp = NULL;
			if (root->left == NULL){
				temp = postpred(root);
				root->name = temp->name;
				root->right = deletedata(root->right, temp->name);
			}
			else if (root->right == NULL){
				temp = inpred(root);
				root->name = temp->name;
				root->left = deletedata(root->left, temp->name);
			}
			else{
				temp = inpred(root);
				root->name = temp->name;
				root->left = deletedata(root->left, temp->name);
			}
		}
	}
};
int main() {
	tree obj;
	tree* root = NULL;
	int menu;
	string a, b, c;
	while (true){
		
		cout << "Please select from the menu: \n";
		cout << "Press 1 to add a new contact.\n";
		cout << "Press 2 to delete a contact.\n";
		cout << "Press 3 to display.\n";
		cout << "Press 4 to search a contact.\n";
		cout << "Press 5 to exit.\n";
		cin >> menu;
		switch (menu){
		case 1:
			cout << "Enter the name to add: ";
			cin >> a;
			root = root->insert(root, a);
			cout << endl;
			break;
		case 2:
			cout << "Enter the name to delete: ";
			cin >> b;
			root = obj.deletedata(root, b);
			cout << endl;
			break;
		case 3:
			obj.preorder(root);
			cout << endl;
			break;
		case 4:
			cout << "Enter the name to search: ";
			cin >> c;
			obj.search(root, c);
			cout << endl;
			break;
		case 5:
			cout << "Thank You\n";
			exit(0);
		default:
			cout << "Invalid input.\n";
		}
	}
	return 0;
}
