#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    void all_permutation(string str, int l, int len, string osf){
        if (len == l){
            cout<<osf<<"\n";
            return;
        }
        unordered_set<char> s;
        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            if(s.count(ch) == 0){
                s.insert(ch);
                string rsf = str.substr(0, i)+str.substr(i+1);
                all_permutation(rsf, l, len+1, osf+ch);
            }
        }
    }
};

int main(){
    string str;
    cin>>str;
    int l = str.size();
    Solution obj;
    obj.all_permutation(str, l, 0, "");
    return 0;
}