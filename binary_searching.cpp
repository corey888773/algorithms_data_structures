#include <iostream>
#include <time.h>

using namespace std;

bool binary_searching(int *arr, int x){
    for (int i = 0; i <= sizeof(arr) + 1; i++){
        if (arr[i] == x) {
            cout << "liczba " << x << " znajduje sie w tablicy" << endl;
            return true;
        }
    }
    cout << "liczba " << x << " nie znajduje sie w tablicy" << endl;
    return false;
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
    int b;
    for (int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }

    print(a);
    cout << "podaj liczbe ktorej szuaksz: ";
    cin >> b;
    binary_searching(a, b);

}