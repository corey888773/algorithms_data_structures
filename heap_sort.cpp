#include <iostream>
#include <ctime>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(int *arr, int size, int p_i){
    int max_i = p_i;
    int l_i = p_i * 2 + 1;
    int r_i = p_i * 2 + 2;
    if(l_i < size && arr[l_i] > arr[max_i]){
        max_i = l_i;
    }
    if(r_i < size && arr[r_i] > arr[max_i]){
        max_i = r_i;
    }
    if(max_i != p_i){
        swap(arr[p_i], arr[max_i]);
        max_heapify(arr, size, max_i);
    }
}
void heap_sort(int *arr){
    int size = sizeof(arr) + 2;
    int last_p = size / 2 - 1;

    for (int i = last_p; i >= 0; i-- ){
        max_heapify(arr, size, i);
    }

    for (int j = size - 1; j > 0; j--){
        swap(arr[0], arr[j]);
        max_heapify(arr, j, 0);
    }
}
void print(int arr[]){
    for (int i = 0; i < 10; i++){
        cout << arr[i] << "\t";
    }
    cout<<endl;

}

int main(){
    srand(time(NULL));
    int a[10];
    for (int & i : a){
        i = rand() % 100;
    }

    print(a);
    heap_sort(a);
    print(a);

}
