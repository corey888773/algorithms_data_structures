#include <iostream>
#include <time.h>

using namespace std;

void merge(int *arr, int s_i, int m_i, int e_i){
    int temp_array[sizeof(arr)+2];
    int x = s_i;
    int y = m_i + 1;
    int temp_index = s_i;

    while (x <= m_i && y <= e_i) {
        if (arr[x] < arr[y]) {
            temp_array[temp_index] = arr[x];
            temp_index++;
            x++;
        }
        else  {
            temp_array[temp_index] = arr[y];
            temp_index++;
            y++;
        }
    }
    while (x <= m_i) {
        temp_array[temp_index] = arr[x];
        temp_index++;
        x++;
    }
    while (y <= e_i) {
        temp_array[temp_index] = arr[y];
        temp_index++;
        y++;
    }
    for (x = s_i; x < temp_index; x++)  {
        arr[x] = temp_array[x];
    }
}
void merge_sort(int *arr, int s_i, int e_i){
    int m_i;
    if (s_i < e_i)
    {
        m_i = (s_i + e_i) / 2;
        merge_sort(arr, s_i, m_i);
        merge_sort(arr, m_i +1, e_i);
        merge(arr, s_i, m_i, e_i);
    }
}
void print(int *arr){
    for (int i = 0; i < 10; i++){
        cout << arr[i] << "\t";
    }
    cout<<endl;

}

int main(){
    srand(time(nullptr));
    int a[10];
    for (int & i : a){
        i = rand() % 100;
    }

    print(a);
    merge_sort(a, 0, 9);
    print(a);

}
