// Tree Version
// time: O(n^2) because of waiting list queue
#pragma warning(disable: 4996) 
#include <cstdio>
#include <queue>
using namespace std;

class node {
	public:
	node* parent = NULL;
	node* left = NULL;
	int data;
	node* right = NULL;
	node(int n) { data = n; }
};

class tree {
	public:
	node* root = NULL;
	tree() { root = new node(1); }

	node* search(node* ptr, int n) {
		node* temp = NULL;
		if(ptr == NULL) return ptr;
		if(n == ptr->data) return ptr;
		if(ptr->left != NULL) temp = search(ptr->left, n);
		if(temp != NULL && temp->data == n) return temp;
		if(ptr->right != NULL) temp = search(ptr->right, n);
		if(temp != NULL && temp->data == n) return temp;
		return temp;
	}
	bool add(int p, int c) {
		int t;
		node* ptr = search(root, p);
		if(ptr == NULL) {
			ptr = search(root, c);
			t = p;
			p = c;
			c = t;
		}
		if(ptr != NULL) {
			if(ptr->left == NULL) {
				ptr->left = new node(c);
				(ptr->left)->parent = ptr;
			}
			else if(ptr->right == NULL) {
				ptr->right = new node(c);
				(ptr->right)->parent = ptr;
			}
		}
		else return 0;
		return 1;
	}
	void result(int n) {
		node* ptr;
		for(int i=2; i<=n; i++) {
			ptr = search(root, i);
			printf("%d\n", ptr->parent->data);
		}
	}
};

int main() {
	int n, parent, child;
	queue<pair<int,int> > waiting;
	tree t;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++) {
		scanf("%d%d", &parent, &child);
		waiting.push({parent, child});
	}
	while(waiting.empty() == 0) {
		if(t.add(waiting.front().first, waiting.front().second) == 1) waiting.pop();
		else {
			waiting.push(waiting.front());
			waiting.pop();
		}
	}
	t.result(n);
	return 0;
}