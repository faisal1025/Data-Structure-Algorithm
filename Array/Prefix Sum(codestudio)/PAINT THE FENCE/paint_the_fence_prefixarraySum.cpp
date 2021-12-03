#include<bits/stdc++.h>

using namespace std;

/*
   
    Time Complexity : O(N + Q * Q)
    Space Complexity : O(N)

    where 'N' is the length of the fence, 
    and 'Q' is the number of painters.
*/

int paintTheFence(vector<vector<int>>& ranges, int n, int q)
{
	vector<int> section(n + 2, 0);
	vector<int> singlePainter(n + 1, 0);
	vector<int> doublePainter(n + 1, 0);

	for (int i = 0; i < q; i++)
	{
   		section[ranges[i][0]]++;
    	section[ranges[i][1]+1]--;
	}

	for (int i = 1; i <= n; i++)
	{
    	section[i] += section[i-1];
	}

    for(int i = 1; i < section.size(); i++){
        cout<<section[i]<<" ";
    }
    cout<<endl;

	int total = n;

	for (int i = 1; i <= n; i++)
	{
		if (section[i] == 0)
    	{
			total--;
    	}
		else if (section[i] == 1)
		{
			singlePainter[i]++;
		}
		else if (section[i] == 2)
		{
			doublePainter[i]++;
		}

		singlePainter[i] += singlePainter[i-1];
		doublePainter[i] += doublePainter[i-1];
	}

    for(int i = 1; i < singlePainter.size(); i++){
        cout<<singlePainter[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i < doublePainter.size(); i++){
        cout<<doublePainter[i]<<" ";
    }
    cout<<"\n";

	
	int maxPainted = 0;

	for (int i = 0; i < q; i++)
	{
		for (int j = i + 1; j < q; j++)
		{
			int currAns = total;

			currAns -= singlePainter[ranges[i][1]] - singlePainter[ranges[i][0]-1];
			currAns -= singlePainter[ranges[j][1]] - singlePainter[ranges[j][0]-1];

			// Intersection of ranges.
			int l = max(ranges[i][0], ranges[j][0]);
			int r = min(ranges[i][1], ranges[j][1]);

			if (r >= l)
			{
				currAns += singlePainter[r] - singlePainter[l-1];
				currAns -= doublePainter[r] - doublePainter[l-1];
			}

			maxPainted = max(maxPainted, currAns);
		}
	}

	return maxPainted;
}



int main(){
    int n, q;
    cin>>n>>q;
    vector<vector<int> > ranges(n, vector<int>(2));

    for(int i = 0; i < q; i++){
        cin>>ranges[i][0];
        cin>>ranges[i][1];
    }

    cout<<paintTheFence(ranges, n, q);
}