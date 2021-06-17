/**
一条笔直的土路连接着FJ农场上的两个田地，但它改变的海拔比FJ想要的要多。他的牛不介意爬上或下一个斜坡，但他们不喜欢交替的山丘和山谷。FJ想要增加和清除道路上的泥土，这样它就变成了一个单调的斜坡(无论是向上倾斜还是向下倾斜)。 给你N个整数A1, ... , AN (1 ≤ N ≤ 2,000) 描述海拔(0 ≤ Ai ≤ 1,000,000,000) 在路上N个等距的位置，从第一个字段开始，到另一个字段结束。FJ想把这些高度调整成一个新的序列B1, . ... , BN 这要么是不增加的，要么是不减少的。由于增加或清除沿路任何位置的污物所需的费用相同，因此修路的总费用为 | A 1 - B 1| + | A 2 - B 2| + ... + | AN - BN | 请计算他的道路分级的最低费用，使它成为一个连续的斜坡。FJ高兴地告诉你，有符号的32位整数肯定可以用来计算答案。

Input
* Line 1: A single integer: N
* Lines 2..N+1: Line i+1 contains a single integer elevation: Ai

Output
* 第1行：一个整数，它是FJ对其土路进行分级的最小成本，因此它在高程上不会增加或减少。

Sample Input
7
1
3
2
4
5
3
9
Sample Output
3
Sponsor

解题思路：题目要求的是把当前序列变成递增或递减序列的最短代价，那我们显然需要考虑两种情况（只考虑一种也能过），那我们可以dp，dp[i][j]表示前i个数，最大值为的排名为j的最小代价，
因为数据范围到了1e9，所以需要离散化；
**/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib> 
using namespace std;

long long dp[2010][2010];
int a[2010],b[2010];

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		long long t=abs(a[1]-b[i]);
		dp[1][i]=t;
	}
	for(int i=2;i<=n;i++){
		long long mi=dp[i-1][1];
		for(int j=1;j<=n;j++){
			mi=min(mi,dp[i-1][j]);
			long long t=abs(a[i]-b[j]);
			dp[i][j]=mi+t;
		}
	}
	long long ans=2e11;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans;
}

