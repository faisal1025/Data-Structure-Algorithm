#include<bits/stdc++.h>
using namespace std;

bool is_valid(string str){
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            cnt++;
        }
        else if(str[i] == ')'){
            cnt--;
        }
        if(cnt < 0)
            return false;
    }
    if(cnt == 0)
    return true;
    else
    return false;
}

void validParanthesis(string str, vector<string> &ans, int start, int &max){
    for(int i = start; i < str.length(); i++){
        if(str[i] == '(' or str[i] == ')'){
            char item = str[i];
            str.erase(str.begin()+i);
            if(is_valid(str) and find(ans.begin(), ans.end(), str) == ans.end()){
                if(max < str.length())
                    max = str.length();
                ans.push_back(str);
            }
            validParanthesis(str, ans, i, max);
            str.insert(str.begin()+i, item);
        }
    }
}

int main(){
    string str;
    cin>>str;
    vector<string> ans;
    int max = 0;
    if(is_valid(str) and find(ans.begin(), ans.end(), str) == ans.end()){
        if(max < str.length()){
            max = str.length();
        }
        ans.push_back(str);
    }
    validParanthesis(str, ans, 0, max);
    int size = ans.size();
    vector<string> ans2;
    for(int i = 0; i < size; i++){
        if(ans[i].length() == max){
            ans2.push_back(ans[i]);
        }
    }

    for(int i = 0; i < ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }
}

