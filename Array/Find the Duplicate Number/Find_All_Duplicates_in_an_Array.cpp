#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        vector<int> dup;
        
        for(int i = 0; i < nums.size(); i++){
            nums[nums[i]%n] = nums[nums[i]%n] + n; 
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]/n > 1) dup.push_back(i);
        }
        return dup;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    Solution obj;
    vector<int> dup = obj.findDuplicates(arr);
    for(int i = 0; i < dup.size(); i++){
        cout<<dup[i]<<" ";
    }
}