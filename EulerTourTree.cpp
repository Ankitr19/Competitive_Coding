/*
 * Ankit Raj, NIT Agartala
 */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAXI 1001
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define F first
#define S second
vector<int>Graph[MAXI];
int vis[MAXI];
int Euler[2*MAXI];
void add_edge(int u,int v)
{
	Graph[u].pb(v);
	Graph[v].pb(u);
}
void EulerTree(int u, int& index)
{
	vis[u] = 1;
	Euler[index++] = u;
	for(auto it:Graph[u])
	{
		if(vis[it]!=1)
		{
			EulerTree(it, index);
			Euler[index++] = u;
		}
	}
}
void printEulerTour(int root, int N)
{
	int index = 0;
	EulerTree(root, index);
	for(int i=0;i<(2*N-1);i++)
	{
		cout<<Euler[i]<<" ";
	}
}
int main()
{
	BOOST;
	NITRO;
	clock_t t1,t2;
	t1 = clock();
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/ 
	//Main Code
	int N = 4;
	add_edge(1, 2);
	add_edge(2, 3);
	add_edge(2, 4);
	printEulerTour(1, N);

	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	//cout<<"\n"<<execution_time;
	//system("pause");
}
