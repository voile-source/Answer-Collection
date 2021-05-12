/**
题目描述
在一个地图上有NN个地窖(N \le 20)(N≤20)，每个地窖中埋有一定数量的地雷。同时，给出地窖之间的连接路径。当地窖及其连接的数据给出之后，某人可以从任一处开始挖地雷，然后可以沿着指出的连接往下挖（仅能选择一条路径），当无连接时挖地雷工作结束。设计一个挖地雷的方案，使某人能挖到最多的地雷。

输入格式
有若干行。

第11行只有一个数字，表示地窖的个数NN。

第22行有NN个数，分别表示每个地窖中的地雷个数。

第33行至第N+1N+1行表示地窖之间的连接情况：

第33行有n-1n−1个数（00或11），表示第一个地窖至第22个、第33个、…、第nn个地窖有否路径连接。如第33行为1 1 0 0 0 … 011000…0，则表示第11个地窖至第22个地窖有路径，至第33个地窖有路径，至第44个地窖、第55个、…、第nn个地窖没有路径。

第44行有n-2n−2个数，表示第二个地窖至第33个、第44个、…、第nn个地窖有否路径连接。

… …

第n+1n+1行有11个数，表示第n-1n−1个地窖至第nn个地窖有否路径连接。（为00表示没有路径，为11表示有路径）。

输出格式
有两行

第一行表示挖得最多地雷时的挖地雷的顺序，各地窖序号间以一个空格分隔，不得有多余的空格。

第二行只有一个数，表示能挖到的最多地雷数。

输入输出样例
输入 #1复制
5
10 8 4 7 6
1 1 1 0
0 0 0
1 1
1
输出 #1复制
1 3 4 5
27

解题思路，dfs+存储路径,每次搜索到一个点，判断这个点是否有与其相连的其他点，如果没有，则更新最大值和路径。
**/

#include<iostream>
#include<vector> 
using namespace std;

int e[21][21];
int a[21],p[21],ans[21];
int an,m,k,s,n;

int check(int x)
{
	int flag=1;
	for(int i=x+1;i<=n;i++){
		if(e[x][i])flag=0;
	}
	if(flag)return 1;
	return 0;
}

void dfs(int x)
{
	if(check(x))
	{
		if(m>an)
		{
			an=m;
			for(int i=0;i<k;i++)
			{
				ans[i]=p[i];
			}
			s=k;
		}
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(e[x][i])
		{
			p[k++]=i;
			m+=a[i];
			dfs(i);
			k--;
			m-=a[i];
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int x;
			cin>>x;
			if(x)e[i][j]=e[j][i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		k=0;
		m=a[i];
		p[k++]=i;
		dfs(i);
	}
	for(int i=0;i<s;i++)cout<<ans[i]<<' ';
	cout<<endl;
	cout<<an;
}
