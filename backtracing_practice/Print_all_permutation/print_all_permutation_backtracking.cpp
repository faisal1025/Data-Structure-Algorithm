#include<bits/stdc++.h>
using namespace std;

void swap(string &s, int i, int k){
    char temp = s[i];
    s[i] = s[k];
    s[k] = temp;
}

class Solution
{
	public:
	    void permutation(string s, int i, int n, string ans, vector<string> &result){
	        if(i == n){
	            result.push_back(ans);
	            return;
	        }
	        for(int k = i; k < s.length(); k++){
	            swap(s, i, k);
	            permutation(s, i+1, n, ans+s[i], result);
                swap(s, i, k);
	        }
	        return;
	    }
        
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(), S.end());
		    vector<string> result;
		    permutation(S, 0, S.length(),  "", result);
		    return result;
		}
};

int main(){
    string S;
    cin>>S;
    Solution obj;
    vector<string>result = obj.find_permutation(S);
    for(auto per = result.begin(); per < result.end(); per++){
        cout<<*(per)<<" ";
    }
}