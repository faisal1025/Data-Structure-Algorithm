#include<bits/stdc++.h>
using namespace std;

 int removableParanthesisNo(string s){
     stack<char> st;
     for(int i = 0; i < s.length(); i++){
         if (s[i] == '('){
             st.push(s[i]);
         }
         else if(s[i] == ')'){
             if(st.empty()){
                st.push(s[i]);
             }else if(st.top() == ')'){
                 st.push(s[i]);
             }else{
                 st.pop();
             }
         }
     }
     return st.size();
 }

 bool is_valid(string s){
     int cnt = 0;
     for(int i = 0; i < s.length(); i++){
         if(s[i] == '(')
            cnt++;
         else if(s[i] == ')')
            cnt--;

         if(cnt < 0){
             return false;
         }
     }

     if (cnt == 0)
        return true;
     else
        return false;
 }

 void validStrings (string s, vector<string> &ans, int validSize, int start){
     if(s.length() == validSize){
         if(is_valid(s) && find(ans.begin(), ans.end(), s) == ans.end()){
             ans.push_back(s);
         }
         return;
     }
     for(int i = start; i < s.length(); i++){
         char ch = s[i];
         if(ch == '(' or ch == ')'){
              s.erase(s.begin()+i);
              validStrings(s, ans, validSize, i);
              s.insert(s.begin()+i, ch);
         }
     }
     return ;
 }

int main(){
    string s;
    cin>>s;
    // number of invalid paranthesis
    int rm = removableParanthesisNo(s);
    int validSize = s.length()-rm;
    vector<string> ans;
    validStrings(s, ans, validSize, 0);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
