#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> coin(n);
    vector<int> temp(10005);
    for(int i = 0; i < n; i++) cin>>coin[i];
    set<int> dp;
    for(int i = 0; i < n; i++){
        temp.clear();
        if(dp.empty()){
            dp.insert(coin[i]);
            continue;
        }else{
            for(auto it : dp){
                int s = it+coin[i];
                temp.push_back(s);
            }
            dp.insert(coin[i]);
            for(auto it : temp){
                dp.insert(it);
            }
        }
    }
    cout<<dp.size()<<endl;
    for(auto it : dp){
        cout<<it<<" ";
    }
}