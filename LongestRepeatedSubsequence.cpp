#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n;
	 cin>>n;
	string s;
	cin>>s;
	int dp[s.size()+1][s.size()+1],i,j;
	for(i=0;i<=s.size();i++)
	{
		for(j=0;j<=s.size();j++)dp[i][j]=0;
	}
	for(i=0;i<=s.size();i++)
	{
		for(j=i;j<=s.size();j++)
		{
			if(i==j||i==0||j==0)
			dp[i][j]=0;
			else if(s[i-1]==s[j-1])
			     dp[i][j]=1+dp[i-1][j-1];
			 else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
/*	for(i=0;i<=s.size();i++)
	{
		for(j=0;j<=s.size();j++){
		cout<<dp[i][j]<<' ';
	}
	cout<<'\n';
	}*/
	cout<<dp[s.size()-1][s.size()]<<'\n';
}
	
}
