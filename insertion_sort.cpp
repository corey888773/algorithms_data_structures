#include <iostream>
#include <time.h>

using namespace std;

void insertion_sort(int *arr){
    int value;
    int index;
    for (int i = 0; i <= sizeof(arr) + 1; i++){
        value = arr[i];
        index = i-1;
        while(index >= 0 && value < arr[index]){
            arr[index+1] = arr[index];
            index --;
        }
        arr[index+1] = value;
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
    insertion_sort(a);
    print(a);

}
