#include <bits/stdc++.h>
#define mod 998244353 // header file includes every Standard library
using namespace std;

int main() {

	// Your code here
	int t;
	cin>>t;
	while(t)
	{
		long long int n;
		cin>>n;

		cout<<((2*(n%998244353))%998244353*((2*(n%998244353))%998244353-1))%998244353<<endl;

		t--;
	}

	return 0;
}