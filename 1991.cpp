// time: O(n)  n is the number of nodes
#include <iostream>
using namespace std;

class node {
public:
	node* left = NULL;
	char value;
	node* right = NULL;
	node(char input) { value = input; }
};

class tree {
public:
	node* root;
	tree() { root = NULL; }
	~tree() { delete[] root; }
	node* r() { return root; }
	node* search(node* ptr, char data) {
		node* temp;
		if (ptr == NULL) return ptr;
		if (ptr->value == data) return ptr;
		temp = search(ptr->left, data);
		if (temp != NULL) return temp;
		temp = search(ptr->right, data);
		if (temp != NULL) return temp;
		return NULL;
	}
	void insert(char a, char b, char c) {
		node* ptr = search(root, a);
		if (ptr == root) {
			root = new node(a);
			if(b != '.') root->left = new node(b);
			if(c != '.') root->right = new node(c);
		}
		else if (ptr != NULL) {
			if(b != '.') ptr->left = new node(b);
			if(c != '.') ptr->right = new node(c);
		}
	}
	void preorder(node* ptr) {
		if (ptr != NULL) {
			printf("%c", ptr->value);
			preorder(ptr->left);
			preorder(ptr->right);
		}
	}
	void inorder(node* ptr) {
		if(ptr != NULL) {
			inorder(ptr->left);
			printf("%c", ptr->value);
			inorder(ptr->right);
		}
	}
	void postorder(node* ptr) {
		if(ptr != NULL) {
			postorder(ptr->left);
			postorder(ptr->right);
			printf("%c", ptr->value);
		}
	}
};

int main() {
	int n;
	char a, b, c;
	tree t;
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> b >> c;
		t.insert(a, b, c);
	}
	t.preorder(t.r());
	printf("\n");
	t.inorder(t.r());
	printf("\n");
	t.postorder(t.r());
	return 0;
}