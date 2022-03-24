#include <iostream>
#include <ctime>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int s_i, int e_i){
    int last = arr[e_i], temp = s_i - 1;
    for(int j = s_i; j < e_i; j++){
        if(arr[j] <= last){
            temp++;
            swap(arr[temp], arr[j]);
        }
    }
    swap(arr[temp+1], arr[e_i]);
    return temp + 1;
}
void quick_sort(int *arr, int s_i, int e_i) {
    if(s_i < e_i){
        int pivot_index = partition(arr, s_i, e_i);
        quick_sort(arr, s_i, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, e_i);
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
    quick_sort(a, 0 ,9);
    print(a);

}
