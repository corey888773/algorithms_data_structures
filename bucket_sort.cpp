#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

void bucket_sort(float *arr, int size){;
    vector <float> bucket[size];
    for (int i = 0; i < size; i++){
        int bucket_number = size * arr[i];
        bucket[bucket_number].push_back(arr[i]);
    }

    for (int i = 0; i < size; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for(int i = 0; i<size; i++) {
        while (!bucket[i].empty()) {
            arr[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
}
void print(float arr[]){
    for (int i = 0; i < 10; i++){
        cout << arr[i] << "\t";
    }
    cout<<endl;

}
int main(){
    srand(time(NULL));
    float a[10];
    for (int i = 0; i < 10; i++){
        a[i] = (rand() % 100);
        a[i] /=100;
    }

    print(a);
    bucket_sort(a, 10);
    print(a);

}

