#include <bits/stdc++.h>
#define mod 998244353 // header file includes every Standard library
using namespace std;

int main() {

	// Your code here
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int side = ((n-1)*4)*2;
		long long int r = (n-1)*2;
		long long int c = 2;
		long long int l = ((n-2)*(n-1))/2;
		long long int li = l*2*4;
		long long int ans;
		if(n > 2)
			ans = (side%mod+r%mod+c%mod+li%mod)%mod;
		else
			ans = (side%mod+r%mod+c%mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}