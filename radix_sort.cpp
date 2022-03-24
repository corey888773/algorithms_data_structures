#include <iostream>
#include <ctime>
#include <cmath>
#include <list>

using namespace std;

void radix_sort(int *arr, int n, int max) {
    int m, p, index, temp;
    list<int> pocket[10];
    for(int i = 0; i < max; i++) {
        m = pow(10, i+1);
        p = pow(10, i);
        for(int j = 0; j<n; j++) {
            temp = arr[j] % m;
            index = temp / p;
            pocket[index].push_back(arr[j]);
        }
        int count = 0;
        for(int j = 0; j<10; j++) {
            while(!pocket[j].empty()) {
                arr[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
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
        a[i] = rand() % 1000;
    }

    print(a);
    radix_sort(a, 10 ,3);
    print(a);
}
