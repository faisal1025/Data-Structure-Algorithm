#include<bits/stdc++.h>
using namespace std;

string findNonRepeating(string A){
    string ans;
    vector<int>map(26, 0);
    vector<char>v;
    for(int i = 0; i < A.length(); i++){
        if(map[A[i] - 'a'] == 0){
            v.push_back(A[i]);
        }
        map[A[i]-'a']++;
        int found = 0;
        for(int i = 0; i < v.size(); i++){
            if(map[v[i]-'a']==1){
                ans+=v[i];
                found = 1;
                break;
            }
        }
        if(found==0){
            ans+='#';
        }
    }
    return ans;
}

int main(){
    string A;
    cin>>A;
    cout<<findNonRepeating(A);
    return 0;
}