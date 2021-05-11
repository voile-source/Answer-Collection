/**
　　zuojiliuchang与yejinmingcuc在玩一个游戏。

　　他们先各自写下一串字符，然后互相展示。展示过后，他们再从自己写的那串字符中依次挑出若干字符（保持原有顺序不变），组成新的一串。他们希望自己新组成的字符串与对方新组成的完全相同，并且尽可能长。

　　例如，zuojiliuchang写下abcde，yejinmingcuc写下aeiou，然后zuojiliuchang挑出自己那串里的第1和第5个字符组成新串ae，yejinmingcuc挑出自己那串中的第1、2个字符，也组成字符串ae。ae就是他们能共同挑出的最长串。

　　现在，zuojiliuchang和yejinmingcuc分别写出了自己的字符串，请帮他们算一下他们能共同挑出组成的字符串最长有多长。

Input
　　输入包含多组数据，处理至文件结尾。

　　每组数据占一行，包括以空格分隔的两个字符串，分别是zuojiliuchang和yejinmingcuc写下的字符串。两个字符串长度都在1000以内。

Output
　　对于每组输入，输出一个整数，即他们能共同挑出组成的字符串的最大长度。

Sample Input
abcfbc abfcab
programming contest 
abcd mnp
Sample Output
4
2
0

解题思路：区间dp，dp[i][j]储存i~j中的最长公共子序列。
**/

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int dp[1010][1010];

int main()
{
	string a,b;
	while(cin>>a>>b){
		for(int i=1;i<=a.size();i++){
			for(int j=1;j<=b.size();j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[a.size()][b.size()]<<endl; 
	}
}
