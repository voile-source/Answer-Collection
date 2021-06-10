/**
有N个学生合影，站成左对齐的k排，每行分别有N1,N2…NK个人，第一排站最后，第k排站之前。
学生身高依次是1…N。在合影时候要求每一排从左到右递减，每一列从后面到前也递减，一共有多少总方案
Input
输入
每组测试数据包含两行。第一行给出行数k
第二行包含从后到前（n1，n2，…，nk）的行的长度，作为由单个空格分隔的十进制整数。
问题数据以0结束。
N<=30, k<=5;
Output
输出
输出每组数据的方案数
Sample Input
1
30
5
1 1 1 1 1
3
3 2 1
4
5 3 3 1
5
6 5 4 3 2
2
15 15
0
Sample Output
1
1
16
4158
141892608
9694845

解题思路：这道题的矩阵构造规则刚好满足杨氏矩阵构造规则，所以我们可以直接用杨氏矩阵的勾子公式求出方案数，需要注意的点是，这个题目没一行的排列是从后往前排列的，而且每一行的列数也不是严格单调递减的
所以，我们需要提前处理好每个格子的勾长，然后利用勾子公式求出总方案数。

**/

#include<iostream>
using namespace std;

int a[35];
int t[35];

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n;
	while(cin>>n&&n) {
		
		for(int i=1;i<=n;i++)cin>>a[i];
		int cnt=1;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=a[i];j++) {
				t[cnt]=a[i]-j+1;
				for(int k=i+1;k<=n;k++) {
					if(a[k]>=j)t[cnt]++;
				}
				cnt++;
			}
		} 
		long long ans=1,div=1;
		for(int i=1;i<cnt;i++) {
			ans*=i;
			div*=t[i];
			int x=gcd(ans,div);
			ans/=x;
			div/=x;
		}
		cout<<ans/div<<endl;
	}	
} 
