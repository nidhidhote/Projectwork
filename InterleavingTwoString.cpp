#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	int dp[s2.size()+1][s1.size()+1],dp1[s3.size()+1][s1.size()+1],i,j;
	int hash[26]={0};
	for(i=0;i<=s2.size();i++)
	{
		hash[s2[i]-65]++;
		for(j=0;j<=s1.size();j++)
		dp[i][j]=0;
	}
	for(i=0;i<=s3.size();i++)
	{
		hash[s3[i]-65]++;
		for(j=0;j<=s1.size();j++)
		dp1[i][j]=0;
	}
	for(i=0;i<=s2.size();i++)
	{
		for(j=i;j<=s1.size();j++)
		{
			if(i==0||j==0)dp[i][j]=0;
			else if(s1[j-1]==s2[i-1])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(i=0;i<=s3.size();i++)
	{
		for(j=i;j<=s1.size();j++)
		{
			if(i==0||j==0)dp[i][j]=0;
			else if(s1[j-1]==s3[i-1])dp1[i][j]=1+dp1[i-1][j-1];
			else dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
		}
	}
	for(i=0;i<s1.size();i++)
	{
		/*if(hash[s1[i]-65]!=0)
		{
			hash[s1[i]-65]--;
		}*/
		for(j=0;j<=s1.size();j++)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}
	int f=0;
	for(i=0;i<26;i++)
	{
		if(hash[i]!=0)
		f=1;
	}
	if(f==0&&dp[s2.size()][s1.size()]==s2.size()&&dp1[s3.size()][s1.size()]==s3.size()&&dp[s2.size()][s1.size()]+dp1[s3.size()][s1.size()]==s1.size())
	cout<<"true";
	else cout<<"false";
}
