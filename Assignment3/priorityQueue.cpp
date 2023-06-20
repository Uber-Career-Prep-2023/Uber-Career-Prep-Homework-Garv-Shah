#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class PriorityQueue {
private:
    int size;
    int max;
    pair<string, int> *arr; // the underlying array

public:
    PriorityQueue(int max){
        size = 0;
        this -> max = max;
        arr = new pair<string, int>[max];
        for(int i=0; i<max; i++){
            arr[i] = {"", -1};
        }
    }
    string top(){
        return arr[0].first;
    } // returns the highest priority (first) element in the PQ

    void insert(string x, int weight){
        if(size == max){
            cout << "Max size reached" << endl;
            return;
        }
        arr[size] = {x, weight};
        size++;
        int i = size-1;
        while(i > 0 && arr[parent(i)].second < arr[i].second){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    } // adds string x to the PQ with priority weight

    void remove(){
        assert(size != 0);
        pair<string, int> *last = &arr[size-1];
        arr[0] = *last;
        *last = {"", -1};
        size--;
        maxHeapify(0);
    } // removes the highest priority (first) element in the PQ

    void maxHeapify(int i){
        int l = 2*i+1;
        int r = 2*i+2;
        int largest = i;
        if(l < size && arr[l].second > arr[i].second)
            largest = l;
        if(r < size && arr[r].second > arr[largest].second)
            largest = r;
        if(largest != i){
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    int parent(int i){
        return i > 0 ? (i - 1)/2 : -1;
    }
};

int main() {
    PriorityQueue* a = new PriorityQueue(5);
    a->insert("Pizza", 5);
    a->insert("Burger", 3);
    cout << a->top() << endl; // Pizza
    a->insert("Cookie", 4);
    a->insert("Nachos", 6);
    cout << a->top() << endl; // Nachos
    a->insert("Pasta", 2);
    a->insert("Salad", 0); // Max size reached
    a->remove();
    a->remove();
    cout << a->top() << endl; // Cookie
    return 0;
}
