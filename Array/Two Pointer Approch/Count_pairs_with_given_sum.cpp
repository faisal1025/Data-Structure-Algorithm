#include<iostream>
#include<unordered_map>

using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i ++){
            if(mp.find(k - arr[i]) != mp.end()){
                cnt += mp[k - arr[i]];
            }
            mp[arr[i]]++;
        }
        return cnt;
    }
};

int main(){
    int n, k;
    cin>>n;
    cin>>k;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }


    Solution obj;
    cout<<obj.getPairsCount(arr, n, k);


}