/**
There is going to be a party to celebrate the 80-th Anniversary of the Ural State University. The University has a hierarchical structure of employees. It means that the supervisor relation forms a tree rooted at the rector V. E. Tretyakov. In order to make the party funny for every one, the rector does not want both an employee and his or her immediate supervisor to be present. The personnel office has evaluated conviviality of each employee, so everyone has some number (rating) attached to him or her. Your task is to make a list of guests with the maximal possible sum of guests' conviviality ratings.


有个公司要举行一场晚会。为了让到会的每个人不受他的直接上司约束而能玩得开心，公司领导决定：如果邀请了某个人，那么一定不会再邀请他的直接的上司，但该人的上司的上司，上司的上司的上司……都可以邀请。已知每个人最多有唯一的一个上司。
已知公司的每个人参加晚会都能为晚会增添一些气氛，求一个邀请方案，使气氛值的和最大。
Input
Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go T lines that describe a supervisor relation tree. Each line of the tree specification has the form:
L K
It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line
0 0 <>
注意包含多组输入
第1行一个整数N表示公司的人数。
接下一行N个整数。第i行的数表示第i个人的气氛值x（-128<=x<=127）
接N-1下来每行两个整数L,K。表示第K个人是第L个人的上司。
输入以两个0结尾
Output
Output should contain the maximal sum of guests' ratings.
一个数，最大的气氛值和。
Sample Input
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output
5

解题思路：公司的每个都只有两种状态，去参加派对or不去参加。当某位上司去参加派对时，这个人的直接下属都不能去参加派对，而当某位上司不去参加派对时，他的下属可去，也可以不去。在搞清楚这层关系之后，我们就可以用树形dp解决
这个问题了。对于公司的每个人，我们用dp[i][0]表示这个不去参加派对，dp[i][1]表示这个人参加派对,对于每个dp[i][1]=他的所有下属的dp[j][0]，对于每个dp[i][0]=max(下属参加，下属不参加).

**/

#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
const int max_n=6010;
typedef long long ll;

int a[max_n];
int pre[max_n],ne[max_n],e[max_n];
ll dp[max_n][2];
int cnt;

void init()
{
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	memset(pre,0,sizeof(pre));
	cnt=1;
}

void add(int u,int v)
{
	e[cnt]=v;
	ne[cnt]=pre[u];
	pre[u]=cnt++; 
} 

void dfs(int x)
{
	for(int i=pre[x];i;i=ne[i]){
		dfs(e[i]);
		dp[x][1]+=dp[e[i]][0];
		dp[x][0]+=max(dp[e[i]][1],dp[e[i]][0]);
	}
}

int main()
{
	int n;
	while(cin>>n){
		init();
		for(int i=1;i<=n;i++)cin>>dp[i][1];
		int x,y;
		while(cin>>x>>y&&x&&y){
			add(y,x);
			a[x]++;
		}
		x=1;
		while(a[x]&&x<=n)x++; 
		dfs(x);
		cout<<max(dp[x][1],dp[x][0])<<endl;
	}
} 
