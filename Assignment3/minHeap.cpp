#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Heap {
private:
    int size;
    int max;
    int *arr; // the underlying array

public:
    Heap(int max){
        size = 0;
        this -> max = max;
        arr = new int[max]; // creates an array with size = max
        for(int i=0; i<max; i++){
            arr[i] = -1; // initially sets all elements to -1
        }
    }
    int top(){
        return arr[0];
    } // returns the min (top) element in the heap

    void insert(int x){
        if(size == max){
            cout << "Max size reached" << endl;
            return;
        }
        arr[size] = x; // initially insert element at the end as a leaf node
        size++;
        int i = size-1;
        while(i > 0 && arr[parent(i)] > arr[i]){ // keep performing swap operations until element is in the right position
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    } // adds int x to the heap in the appropriate position

    void remove(){
        assert(size != 0);
        int *last = &arr[size-1];
        arr[0] = *last;
        *last = -1;
        size--;
        minHeapify(0);
    } // removes the min (top) element in the heap

    void minHeapify(int i){
        int l = 2*i+1; // left child index
        int r = 2*i+2; // right child index
        int smallest = i; // index of parent
        if(l < size && arr[l] < arr[i])
            smallest = l;
        if(r < size && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int parent(int i){
         return i > 0 ? (i - 1)/2 : -1; // returns the parent index of index i, provided i is valid
    }
};

int main() {
    Heap* a = new Heap(5);
    a->insert(5);
    a->insert(4);
    cout << a->top() << endl; // 4
    a->insert(3);
    a->insert(2);
    cout << a->top() << endl; // 2
    a->insert(1);
    a->insert(0); // Max size reached
    a->remove();
    a->remove();
    cout << a->top() << endl; // 3
    return 0;
}
