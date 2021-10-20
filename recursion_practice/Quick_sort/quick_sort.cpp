#include<bits/stdc++.h>
using namespace std;
#define size 100

void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
}

int partition(int *arr, int l, int u, int i, int j){
    int pivot, mid;
    mid = (l+u)/2;
    pivot = arr[mid];
    
        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while (arr[j] > pivot);

        if(i < j){
            swap(arr[i], arr[j]);
            return partition(arr, l, u, i, j);
        }
        else if(i > j){
            swap(arr[mid], arr[j]);
            return j;
        }
}

void Quick_sort(int *arr, int l, int u){
    if (l < u){
        int k;
        k = partition(arr, l, u, l, u);

        Quick_sort(arr, l, k);
        Quick_sort(arr, k+1, u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[size];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    Quick_sort(arr, 0, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}