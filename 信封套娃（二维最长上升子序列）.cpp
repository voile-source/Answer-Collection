/**
猪猪侠 决定祝他来自黑色玫瑰的朋友生日快乐，并给他的朋友寄明信片。为了让礼物更神秘，猪猪侠 决定制作一个 连环套。这里的连环套表示一系列的信封 A = {a1,  a2,  ...,  an}，其中第 i 个信封的宽度和高度，分别严格大于第 (i  -  1) 个信封的宽度和高度。连环套的尺寸是指连环套中的信封数目。

猪猪侠想要从自己拥有的信封制作出最大尺寸的连环套，使得该连环套能够放入一张明信片。如果名信片的宽度和高度分别小于连环套中最小信封的宽度和高度，则表示名信片可以被放入连环套。禁止旋转名信片和信封。

猪猪侠 拥有很多信封，但时间很有限，他还要节约时间去泡妹子，因此将这一困难的任务委托给您完成。

输入
第一行包含整数 n, w, h (1  ≤ n ≤ 5000, 1 ≤ w,  h  ≤ 106) — 猪猪侠 拥有的信封编号，以及相应的明信片宽度和高度。接下来的 n 行，每行包含两个整数 wi 和 hi — 表示第 i 个信封的宽度和高度 (1 ≤ wi,  hi ≤ 106)。

输出
在第一行中，打印连环套的最大尺寸。在第二行中，打印信封的编号 (以空格间隔)，构成所要求的连环套，以最小信封的编号开始。请记住，名信片应当能够放入最小的信封。如果最大尺寸的连环套不唯一，则打印所有答案中的任意一种。

如果名信片无法放入任何一个信封，则在单一的行中打印数字 0 。

示例
输入
2 1 1
2 2
2 2
输出
1
1 
输入
3 3 3
5 4
12 11
9 8
输出
3
1 3 2 

解题思路：一个信封能装下另一个信封的条件是长和宽都严格大于另一个，那我们只要保证所选的信封序列的长和宽严格单调递增，也就是求出一个最长二维单调递增子序列。处理数据的时候,只保存能够放进明信片的信封，
然后按照宽为第一关键字，长为第二关键字排序。
**/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int max_n=5010;

struct node{
	int w,h,num;
}a[max_n];
 
int dp[max_n],p[max_n];
int k,W,H;

bool cmp(node a,node b)
{
	if(a.w==b.w)return a.h<b.h;
	return a.w<b.w;
}

void print(int x)
{
	if(p[x]==-1){
		cout<<a[x].num<<' ';
		return ;
	}
	print(p[x]);
	cout<<a[x].num<<' ';
	return ;
}

int main()
{
	cin>>k>>W>>H;
	int n=0;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		if(x>W&&y>H)a[++n].w=x,a[n].h=y,a[n].num=i;
		dp[i]=1;
	}
	if(n==0){
		cout<<0<<endl;
	}else{
		memset(p,-1,sizeof p);
		sort(a+1,a+n+1,cmp);
		for(int i=2;i<=n;i++){
			int m=0;
			for(int j=1;j<i;j++){
				if(a[i].w>a[j].w&&a[i].h>a[j].h&&dp[j]+1>dp[m]+1)m=j;
			}
			if(dp[m]+1>dp[i]){
				dp[i]=dp[m]+1;
				p[i]=m;
			}
		}
		int m=1;
		for(int i=2;i<=n;i++)if(dp[i]>dp[m])m=i;
		cout<<dp[m]<<endl;
		print(m);
	}
}
