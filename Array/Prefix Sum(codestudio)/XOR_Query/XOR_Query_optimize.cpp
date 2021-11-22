#include<bits/stdc++.h>

using namespace std;

vector<int> xorQuery(vector<vector<int>> &queries)
{
    // Create an empty array ans
	vector<int>ans;

	// Create an array xorArray of the size of 10^5+1 initialized with 0
	vector<int> xorArray(100001, 0);
    
    // Iterate over all the queries
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i][0] == 1)
		{
			ans.push_back(queries[i][1]);
		}
		else
		{
			xorArray[0] ^= queries[i][1];
			xorArray[ans.size()] ^= queries[i][1];
		}

	}
    for(int i = 0; i <= ans.size(); i++){
        cout<<xorArray[i]<<" ";
    }
    cout<<"\n";

	// Computing cumulative prefix XOR and evaluating the answer
	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0)
		{
			ans[i] = ans[i] ^ xorArray[i];
		}
		else
		{
			xorArray[i] ^= xorArray[i - 1];
			ans[i] ^= xorArray[i];
		}

	}

    for(int i = 0; i <= ans.size(); i++){
        cout<<xorArray[i]<<" ";
    }
    cout<<"\n";

	return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        vector<vector<int> > queries(q, vector<int> (2));
        for(int i = 0; i < q; i++){
            for(int j = 0; j < 2; j++){
                cin>>queries[i][j];
            }
        }

        vector<int> arr = xorQuery(queries);
        for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

}