#include<bits/stdc++.h>

using namespace std;

vector<int> getSubarray(vector<int> a, int n, int s){
    vector<int> ans;
    int curr_s = a[0];
    int x = 0, y = 0;
    while (x < n && y < n)  
    {
        if(curr_s < s){
            y++;
            curr_s = curr_s + a[y];
        }else if(curr_s > s){
            curr_s = curr_s - a[x];
            x++;
        }else if(curr_s == s and x > y){
            y++;
            curr_s = curr_s + a[y];
        }else if (curr_s == s and x <= y){
            ans.push_back(x+1);
            ans.push_back(y+1);
            break;
        }
    }
    
    return ans;
}

int main(){
    // taking input
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int s;
    cin>>s;

    // Solution
    vector<int> ans = getSubarray(a, n, s);

    // displaying output
    for(int i = 0; i < 2; i++){
        cout<<ans[i]<<" "; 
    }
    cout<<endl;
    return 0;
}