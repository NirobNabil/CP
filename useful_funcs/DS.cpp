#define S1 100000
//heap
#define node int
node heap[S1];
int elem_count = 0;

int parent(int i) {
	return i / 2;
}

int child(int i, int ix) {
	return (i * 2) + ix;
}

void heapify(vector<node> a) {
	for(auto i:a) push(i);
}

void push(node e) {
	elem_count++;
	int i = elem_count -1;
	heap[i] = e;
	while(heap[i] > heap[parent(i)] && i>0)
		swap(heap[i], heap[parent(i)]);
}

void pop(node e) {
	int i=1;
	while(i <= parent(elem_count-1)) {
		if(heap[child(i,1)] > heap[child(i,2)]) i = child(i,1);
		else i = child(i,2);
		swap(heap[parent(i)], heap[i]);
	}
}