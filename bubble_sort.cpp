#include <iostream>
#include <time.h>

using namespace std;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int *arr){
    for (int i = 0; i <= sizeof(arr); i++){
        for (int j = 0; j <= sizeof(arr); j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubble_sort(a);
    print(a);

}
