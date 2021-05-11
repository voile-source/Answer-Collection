/**
一条直线上摆放着一行共n堆的石子。现要将石子有序地合并成一堆。规定每次只能选相邻的两堆合并成新的一堆，并将新的一堆石子数记为该次合并的得分。请编辑计算出将n堆石子合并成一堆的最小得分和将n堆石子合并成一堆的最大得分。
Input
输入有多组测试数据。

每组第一行为n(n<=100)，表示有n堆石子，。

二行为n个用空格隔开的整数，依次表示这n堆石子的石子数量ai（0<ai<=100）

Output
每组测试数据输出有一行。输出将n堆石子合并成一堆的最小得分和将n堆石子合并成一堆的最大得分。 中间用空格分开。
Sample Input
3

1 2 3

Sample Output
9 11

解题思路：区间dp,开两个dp数组，一个存最大值，一个存最小值。
**/

#include<iostream>
#include<cstring>
using namespace std;

int a[110];
int dp1[110][110],dp2[110][110];

int main()
{
	int n;
	while(cin>>n){
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	for(int len=1;len<=n;len++){
		for(int j=1;j<=n-len;j++){
			int end=j+len;
			dp1[j][end]=999999;
			dp2[j][end]=-999999;
			for(int i=j;i<end;i++){
				dp1[j][end]=min(dp1[j][end],dp1[j][i]+dp1[i+1][end]+a[end]-a[j-1]);
				dp2[j][end]=max(dp2[j][end],dp2[j][i]+dp2[i+1][end]+a[end]-a[j-1]);
			}
		}
	}
	cout<<dp1[1][n]<<' '<<dp2[1][n]<<endl;
	}	
}

