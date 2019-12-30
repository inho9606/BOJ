// time: o(nLog2n)
#include <cstdio>
using namespace std;
int heap[100001];
int last = 1;

void insert(int n) {
	int tmp;
	heap[last] = n;
	for(int i=last; i>0; i/=2) {
		if(heap[i] < heap[i/2] && i/2 > 0) {
			tmp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = tmp;
		}
		else break;
	}
	last += 1;
}

int remove() {
	int min, tmp, deleted = heap[1];
	last -= 1;
	heap[1] = heap[last];
	heap[last] = 0;
	for(int i=1; i*2<last;) {
		if(i*2+1 < last) {
			if(heap[i*2] < heap[i*2+1]) min = i*2;
			else min = i*2+1;
		}
		else if(i*2+1 == last) min = i*2;
		if(heap[i] > heap[min]) {
			tmp = heap[i];
			heap[i] = heap[min];
			heap[min] = tmp;
			i = min;
		}
		else break;
	}
	return deleted;
}
int main() {
	int n, x;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		if(x == 0) {
			if(last == 1) printf("0\n");
			else printf("%d\n", remove());
		}
		else insert(x);
	}
	return 0;
}