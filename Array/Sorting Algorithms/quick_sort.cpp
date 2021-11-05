#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int partition(int arr[], int start, int end){
        int pivot = arr[start];
        int i = start;
        int j = end;

        while(i < j){
            while(arr[i] <= pivot and i <= j){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[j], arr[start]);
        return j;
    }
    public:
    void quickSort(int arr[], int start, int end){
        if(start >= end) return;

        int m = partition(arr, start, end);
        quickSort(arr, start, m-1);
        quickSort(arr, m+1, end);
    }

    void printArr(int arr[], int size){
        
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
    }
};


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    Solution obj;
    obj.quickSort(arr, 0, n-1);
    obj.printArr(arr, n);
    return 0;
}