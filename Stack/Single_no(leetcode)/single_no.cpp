/*[4, 1, 2, 1, 2]
output: 4 count: 1
*/
#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
        stack<int> st;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(!st.empty()){
                if(st.top() == nums[i]){
                    st.pop();
                }
            }else{
                st.push(nums[i]);
            }
        }
        return st.top();
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans = singleNumber(nums);
    cout<<ans<<endl;
}