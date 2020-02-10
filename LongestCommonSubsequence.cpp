//recussive solution for LCS
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int i,j,dp[s1.size()+1][s2.size()+1];
	for(i=0;i<=s1.size();i++)
	{
		for(j=0;j<=s2.size();j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
		   else	if(s1[i-1]==s2[j-1]){
		   	dp[i][j]=1+dp[i-1][j-1];
		   }
		   else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(i=0;i<=s1.size();i++){
		for(j=0;j<=s2.size();j++)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}
	string k;
	j=s1.size();
	i=s2.size();
		for(i=s2.size();i>0;)
		{
			for(j=s1.size();j>0;){
	        //max dp[i][j-1]||dp[i-1][j]
	        if(dp[i][j]==dp[i][j-1])j=j-1;
	        else if(dp[i][j]==dp[i-1][j])i=i-1;
	        else if(dp[i][j]==1+dp[i-1][j-1])
			{
				k+=s2[j];
				i--;
				j--;
		}
		if(i==0||j==0)break;
	}
	}
	cout<<"String is"<<k<<' ';
}
