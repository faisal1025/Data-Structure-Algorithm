#include<bits/stdc++.h>
using namespace std;
#define size 100

class Solution{
  public:
    int minJumps(int arr[], int n){
        int curr_jump, res = 0, limit = arr[0];
        for(int i = 0; i < limit && res < n; i++){
            if(arr[i] == 1){
                res+= arr[i];
                limit = arr[arr[i]];
            }
            else if(curr_i > 1){
                int z, max = arr[curr_i+1];
                i = curr_i+1;
                for(int j = 2; j <= arr[curr_i]; j++){
                    if(max < arr[curr_i+j]){
                        max = arr[curr_i+j];
                        i = curr_i+j;
                    }
                }
            }
            curr_jump++;
        }
        return curr_jump;
    }
};

int main(){
    int n, arr[size];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.minJumps(arr, n);
}