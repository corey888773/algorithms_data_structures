#include <iostream>
#include <ctime>

using namespace std;
void print(int arr[]);

void counting_sort(int *arr, int range){
    int size = sizeof(arr) + 2;
    int temp[range];
    int output[size];
    for(int i = 1; i < range; i++){
        temp[i] = 0;
    }
    for(int j = 0; j < size; j++){
        temp[arr[j]] ++;
        output[j] = 0;
    }
    for(int i = 1; i < range;i++){
        temp[i] += temp[i-1];
    }
    for(int i = 0; i < size; i++ ){
        output[temp[arr[i]]-1] = arr[i];
        temp[arr[i]]--;
    }
    for(int i = 0; i < sizeof(arr)+2; i++){
        arr[i] = output[i];
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
    counting_sort(a, 100);
    print(a);

}
