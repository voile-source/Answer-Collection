/**
Today is army day, but the servicemen are busy with the phalanx for the celebration of the 60th anniversary of the PRC.
A phalanx is a matrix of size n*n, each element is a character (a~z or A~Z), standing for the military branch of the servicemen on that position.
For some special requirement it has to find out the size of the max symmetrical sub-array. And with no doubt, the Central Military Committee gave this task to ALPCs.
A symmetrical matrix is such a matrix that it is symmetrical by the “left-down to right-up” line. The element on the corresponding place should be the same. For example, here is a 3*3 symmetrical matrix:
cbx
cpb
zcc
Input
There are several test cases in the input file. Each case starts with an integer n (0<n<=1000), followed by n lines which has n character. There won’t be any blank spaces between characters or the end of line. The input file is ended with a 0.
Output
Each test case output one line, the size of the maximum symmetrical sub- matrix.
Sample Input
3
abx
cyb
zca
4
zaba
cbab
abbc
cacq
0
Sample Output
3
3

题目大意：给出一个矩阵，求出以这个矩阵的斜对角线为对称轴矩阵的最大长度。

解题思路：区间dp，用dp[i][j]表示以i,j为左下角的矩阵的最大对称矩阵的边长，然后就是区间状态转移，从当前点开始向右上遍历，判断对称长度，如果>=子区间的长度，那么dp[i][j]=子区间长度+1,否则就等于子区间长度。
**/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int max_n=1010;

int dp[max_n][max_n];
string e[max_n];

int main()
{
	int n;
	while(cin>>n&&n){
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;i++)cin>>e[i];
		int ans=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==0||j==n-1){
					dp[i][j]=1;
				}else{
					int x=i,y=j;
					while(x>=0&&y<n&&e[x][j]==e[i][y])x--,y++;
					if(i-x>=dp[i-1][j+1]+1)dp[i][j]=dp[i-1][j+1]+1;
					else dp[i][j]=i-x;
					ans=max(ans,dp[i][j]); 
				}
			}
		}
		cout<<ans<<endl;
	}
return 0;
}
