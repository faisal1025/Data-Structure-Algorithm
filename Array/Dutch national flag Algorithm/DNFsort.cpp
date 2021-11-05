/*
PROBLEM STATEMENT:-
sort a array having element 0, 1 and 2 
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void dnfSort(int arr[], int n){
    int i = 0;
    int mid = 0;
    int j = n-1;

    while(mid <= j){
        if(arr[mid] == 0){
            swap(arr[i], arr[mid]);
            i++; mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else if(arr[mid] == 2){
            swap(arr[j], arr[mid]);
            j--;
        }
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    dnfSort(arr, n);
    printArr(arr, n);
    return 0;
}