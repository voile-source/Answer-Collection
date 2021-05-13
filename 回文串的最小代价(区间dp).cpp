/**
给定一个字符串S，字符串S的长度为M(M≤2000)，字符串S所含有的字符的种类的数量为N(N≤26)，然后给定这N种字符Add与Delete的代价，求将S变为回文串的最小代价和。

Input
第一行：两个由空格分隔的整数 N 和 M

第二行：这一行给出了恰好 M 个字符，表示初始状态下的ID字符串

接下来的 N 行：每一行给出了由空格分隔的三部分。首先是一个字符，保证出现在了输入的字符串中。接下来是两个整数，表示你增添这个字符的代价，然后是删除这个字符的代价

Output
你只需要输出一行，且只输出一个整数。表示你将给定字符串变成回文串所需的最小代价。

Sample Input
3 4
abcb
a 1000 1100
b 350 700
c 200 800
Sample Output
900

解题思路：区间dp,对于一个长度为n的字符串s(s[1]~s[n-1]为已处理好的回文串）,如果s[i]==s[j],那么dp[i][j]=dp[i+1][j-1]（已计算好回文串的开销），否则dp[i][j]=min(dp[i+1][j],dp[i][j-1])(添上一个字符或者删除一个字符）
**/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int max_n=2005;

long long v[26];
long long dp[max_n][max_n];

int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		char c;
		int x,y;
		cin>>c>>x>>y;
		v[c-'a']=min(x,y);
	}
	for(int i=m-1;i;i--){
		for(int j=i+1;j<=m;j++){
			if(s[i-1]!=s[j-1]){
				dp[i][j]=min(dp[i+1][j]+v[s[i-1]-'a'],dp[i][j-1]+v[s[j-1]-'a']);
			}else dp[i][j]=dp[i+1][j-1];
		}
	}
	cout<<dp[1][m];
}
