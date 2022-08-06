#include <iostream>
struct bstNode {
	int data;
	bstNode* left;
	bstNode* right;
};

bstNode* getNewNode(int data) {
	bstNode* newNode = new bstNode();
	newNode->data = data;
	newNode->left = newNode->right = nullptr;
	return newNode;
}

bstNode* insert(bstNode* root, int data) {
	if (root == NULL) {
		root = getNewNode(data);
	}
	else if (data <= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
		return root;
}


bool search(bstNode* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}



int main() {
	bstNode* root = nullptr;
	int sortedNumbers[7] = { 2,4,6,9,12,14,16 };

	for (int i = 0; i < 7; i++) {
		root = insert(root, sortedNumbers[i]);
	}

	/*root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 25);
	root = insert(root, 8);
	root = insert(root, 12);*/
	int number;
	std::cout << "Enter number to be searched\n";
	std::cin >> number;
	if (search(root, number) == true)
		std::cout << "found\n";
	else
		std::cout << "not found!\n";
	return 0;
}