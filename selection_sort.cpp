#include <iostream>
#include <time.h>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int *arr){
    int min_index;
    int k = 0;
    for(int i = 0; i <= sizeof(arr)+1; i++){
        min_index = k;
        for(int j = k; j <= sizeof(arr)+1; j++ ){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        if(min_index != k)
            swap(arr[min_index], arr[k]);
        k++;

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
    for (int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }

    print(a);
    selection_sort(a);
    print(a);

}
