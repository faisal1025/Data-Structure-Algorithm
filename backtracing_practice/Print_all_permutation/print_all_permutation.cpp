#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	    void permutation(string s, int i, int n, string ans, vector<string> &result){
	        if(i == n){
	            result.push_back(ans);
	            return;
	        }
	        for(int k = 0; k < s.length(); k++){
	            string newString = s.substr(0, k)+s.substr(k+1);
	            permutation(newString, i+1, n, ans+s[k], result);
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