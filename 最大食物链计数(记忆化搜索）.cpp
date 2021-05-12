/**
题目背景
你知道食物链吗？Delia 生物考试的时候，数食物链条数的题目全都错了，因为她总是重复数了几条或漏掉了几条。于是她来就来求助你，然而你也不会啊！写一个程序来帮帮她吧。

题目描述
给你一个食物网，你要求出这个食物网中最大食物链的数量。

（这里的“最大食物链”，指的是生物学意义上的食物链，即最左端是不会捕食其他生物的生产者，最右端是不会被其他生物捕食的消费者。）

Delia 非常急，所以你只有 11 秒的时间。

由于这个结果可能过大，你只需要输出总数模上 8011200280112002 的结果。

输入格式
第一行，两个正整数 n、mn、m，表示生物种类 nn 和吃与被吃的关系数 mm。

接下来 mm 行，每行两个正整数，表示被吃的生物A和吃A的生物B。

输出格式
一行一个整数，为最大食物链数量模上 8011200280112002 的结果。

输入输出样例
输入 #1复制
5 7
1 2
1 3
2 3
3 5
2 5
4 5
3 4
输出 #1复制
5
说明/提示
各测试点满足以下约定：

【补充说明】

数据中不会出现环，满足生物学的要求。（感谢 @AKEE ）

解题思路：这道题可以用记忆化搜索+拓扑排序的思想来做，最长食物链的数量=所有入度为0的点的食物链数量。而入度为0的点的食物链数量就等于所有被他吃的动物的食物链数量（这个可以用dfs求）.
**/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int mod=80112002;

queue<int>Q; 
vector<int>s[5010];
ll dp[5010];
int a[5010];

int n,m;

ll dfs(int x){
	if(dp[x])return dp[x];
	for(vector<int>::const_iterator it=s[x].begin();it!=s[x].end();it++){
		dp[x]+=dfs(*it);
		dp[x]%=mod;
	}
	return dp[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x]++;
		s[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!a[i])Q.push(i);
		if(!s[i].size())dp[i]=1;
	}
	ll ans=0;
	while(!Q.empty()){
		int p=Q.front();
		Q.pop();
		for(vector<int>::const_iterator it=s[p].begin();it!=s[p].end();it++){
			ans+=dfs(*it);
			ans%=mod;
		}
	}
	cout<<ans;
}
