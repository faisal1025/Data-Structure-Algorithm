#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int s1 = l;
         int s2 = m+1;
         vector<int> arr1;
         while(s1 <= m and s2 <= r){
             if(arr[s1] < arr[s2]){
                 arr1.push_back(arr[s1]);
                 s1++;
             }else{
                 arr1.push_back(arr[s2]);
                 s2++;
             }
         }
         if(s1 <= m){
             for(; s1 <= m; s1++){
                 arr1.push_back(arr[s1]);
             }
         }
         if(s2 <= r){
             for(; s2 <= r; s2++){
                 arr1.push_back(arr[s2]);
             }
         }
         int j = 0;
         for(int i = l; i <= r; i++){
             arr[i] = arr1[j++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l == r) return;
        
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
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
    obj.mergeSort(arr, 0, n-1);
    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

}