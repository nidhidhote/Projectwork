#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s1,s2;
	cin>>s1>>s2;
	int i,j,dp[s1.size()+1][s2.size()+1],max=0;
	for(i=0;i<=s1.size();i++)
	{
		for(j=0;j<=s2.size();j++)
		{
			if(i==0||j==0)dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			dp[i][j]=0;
		}
	}
	for(i=0;i<=s1.size();i++)
	{
		for(j=0;j<=s2.size();j++)
		{
			if(max<dp[i][j])max=dp[i][j];
		}
	}
	cout<<max<<'\n';
}
	
}
