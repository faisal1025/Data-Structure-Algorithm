#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void rearrange(int arr[], int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            swap(arr, i, j);
            j++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i ++){
        cin>>arr[i];
    }

    rearrange(arr, n);

    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }

}