#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:

    int min(int a, int b){
        return ((a < b)?a:b);
    }
    int max(int a, int b){
        return ((a > b)?a:b);
    }
    
    int getDiff(int arr[], int i, int k, int n, int minE, int maxE){
        int inc = 0, red = 0;
        if(i == n){
            cout<<maxE<<"-"<<minE<<"="<<maxE-minE<<endl;
            return (maxE - minE);
        }
        arr[i] = arr[i] + k;
        if(arr[i] >= 0){
            inc = getDiff(arr, i+1, k, n, min(minE, arr[i]), max(maxE, arr[i]));
        }
        arr[i] = arr[i] - k - k;
        
        if(arr[i] >= 0){
            red = getDiff(arr, i+1, k, n, min(minE, arr[i]), max(maxE, arr[i]));
        }else{
            arr[i] = arr[i] + k;
            return inc;
        }
        arr[i] = arr[i] + k;
        
        return min(inc, red);

    }
  public:

    int getMinDiff(int arr[], int n, int k) {
        // code here
        int minE = INT_MAX;
        int maxE = INT_MIN;
        return getDiff(arr, 0, k, n, minE, maxE);
    }
};

int main(){
    int n, k;
    cin>>k>>n;
    int arr[n];
    for(int i = 0; i < n; i ++){
        cin>>arr[i];
    }

    Solution obj;
    cout<<obj.getMinDiff(arr, n, k);
    return 0;
}