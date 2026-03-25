#include <iostream>
using namespace std;
#define MAX 200
void InputArray(int numbers[], int n){
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
}
void InsertionSort(int numbers[], int n){
    for(int i = 1; i < n; i++){
        cout << "i = " << i << endl;
        int e = numbers[i];
        cout << "Mang truoc khi xu ly: ";
        for(int j = 0; j < n; j++){
            cout << numbers[j] << " ";
        }
        cout << endl;
        cout << "Phan tu dang xet A[" << i << "] = " << e << endl;
        int k = i - 1;
        cout << "Chen " << e << " vao vi tri k = " << k << endl;
        for(k; k > -1; k--){
            if(numbers[k] < e)break;
            numbers[k + 1] = numbers[k];
        }
        numbers[k + 1] = e;
        cout << "Mang sau khi xu ly: ";
        for(int j = 0; j < n; j++){
            cout << numbers[j] << " ";
        }
        cout << endl;
        cout << endl;
    }
}
void OutputArray(int numbers[], int n){
    for(int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }
}
int main(){
    int numbers[MAX];
    int n;
    cin >> n;
    InputArray(numbers, n);
    cout << "Mang truoc khi sap xep: " << endl;
    for(int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Sap xep: " << endl;
    InsertionSort(numbers, n);
    cout << "Mang sau khi sap xep: " << endl;
    OutputArray(numbers, n);
    return 0;
}
