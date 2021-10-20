#include<bits/stdc++.h>
using namespace std;

bool search(vector<string> & dict, string word){
    for(auto i = dict.begin(); i < dict.end(); i++){
        if(*(i) == word)
        return true;
    }
    return false;
}

void getSentence(int n, vector<string> & dict, string str, string ans, int start, int end, vector<string> &ans_vec){
    if (start == end){
        int pos = ans.size()-1;
        ans.erase(ans.begin()+pos);
        ans_vec.push_back(ans);
        return;
    }
    string word = "";
    for(int i = start; i < end; i++){
        word += str[i];
        if(search(dict, word)){
            getSentence(n, dict, str, ans+word+" ", i+1, end, ans_vec);
        }
    }
    return ;
}

int main(){
    string str;
    int n;
    cin>>n;
    cin>>str;
    vector<string> dict({"cats", "cat", "and", "sand", "dog"}) ;
    vector<string> ans_vec;
    getSentence(n, dict, str, "", 0, str.length(), ans_vec);
    for(int i = 0; i < ans_vec.size(); i++){
        cout<<ans_vec[i]<<" ";
    }
    return 0;
}