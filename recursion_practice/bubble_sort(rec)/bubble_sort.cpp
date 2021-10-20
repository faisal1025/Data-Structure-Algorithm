#include <bits/stdc++.h>
using namespace std;
#define size 100

class sorting{
    public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void bubble_sort(int *arr, int n, int i, int j){
        if (i == n){
            return;
        }
        if(j < n-i-1){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
            bubble_sort(arr, n, i, j+1);
        }
        bubble_sort(arr, n, i+1, 0);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[size];
    cin>>n;
    for(int k = 0; k < n; k++){
        cin>>arr[k];
    }
    sorting obj;
    obj.bubble_sort(arr, n, 0, 0);
    for(int k = 0; k < n; k++){
        cout<<arr[k]<<" ";
    }
}