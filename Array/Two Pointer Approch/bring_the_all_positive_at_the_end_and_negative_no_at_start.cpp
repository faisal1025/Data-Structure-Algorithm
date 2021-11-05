#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void posEndNegStart(int arr[], int n){
    int i = 0;
    int j = n-1;
    while(i <= j){
        while(arr[i] < 0){
            i++;
        }
        while(arr[j] >= 0){
            j--;
        }
        if(i < j){
            swap(arr, i, j);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    posEndNegStart(arr, n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
