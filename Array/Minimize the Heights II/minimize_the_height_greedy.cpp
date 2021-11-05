#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:
    int min(int a, int b){
        return ((a<b)?a:b);
    }
    int max(int a, int b){
        return ((a>b)?a:b);
    }
    public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        int minE = 0, maxE = 0, r;
        sort(arr, arr+n);
        r = arr[n-1] - arr[0];
        for(int i=0; i < n; i++){
            if(arr[i] - k >= 0){
                minE = min(arr[i]-k, arr[0]+k);
                maxE = max(arr[i-1]+k, arr[n-1]-k);
                r = min(r, maxE-minE);
            }
        }
        return r;
    }

};


int main(){
    int n, k;
    cin>>k>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    Solution obj;
    cout<<obj.getMinDiff(arr, n, k);
}