#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merge;
        int i = 0, j = 0;
        while(i < m and j < n){
            if(nums1[i] <= nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }else if(nums1[i] > nums2[j]){
                merge.push_back(nums2[j++]);
            }
        }
        for(int z = 0; z < merge.size(); z++){
            cout<<merge[z]<<" ";
        }
        cout<<"\n";
        while(i < m){
            merge.push_back(nums1[i++]);
        }
        while(j < n){
            merge.push_back(nums2[j++]);
        }
        for(int z = 0; z < m+n; z++){
            nums1[z] = merge[z];
        }
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> nums1(m+n);
    vector<int> nums2(n);

    for(int i = 0; i < m; i++){
        cin>>nums1[i];
    }
    for(int j = 0; j < n; j++){
        cin>>nums2[j];
    }

    Solution obj;
    obj.merge(nums1, m, nums2, n);
    for(int i = 0; i < nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout<<"\n";
}