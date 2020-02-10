#include<bits/stdc++.h>
using namespace std;
int lps(string s,int i,int j,int l)
/*	if(i>j)
	return 0;
	if(s[i]!=s[j])
	return max(lps(s,i+1,j,l),lps(s,i,j-1,l));
	if(i==j)
	return 1;
	if(s[i]==s[j])
	return 2+lps(s,i+1,j-1,l);
}*/
{
	int dp[l+1][l+1],max1=0;
	for(i=0;i<=l;i++)
	{
		for(j=0;j<=l;j++)dp[i][j]=0;
	}
	for(i=1;i<=l;i++)
	{
		for(j=l;j>0;j--)
		{
		//	if(i==0||j==l)dp[i][j]=0;
			if(i>j){
			break;
			
		}
			if(i==j)dp[i][j]=1+dp[i-1][j+1];
			else if(s[i-1]==s[j-1])
			dp[i][j]=dp[i-1][j+1]+2;
			if(s[i-1]!=s[j-1])dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
			if(max1<dp[i][j])max1=dp[i][j];
			
		}
	}
	/*for(i=0;i<=l;i++)
	{
		for(j=0;j<=l;j++)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	return max1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s1;
	cin>>s1;
	int l,i,j;
	l=s1.size();
	int k=lps(s1,0,l-1,l);
	cout<<k<<'\n';
}
}

