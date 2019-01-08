/*
 * Ankit Raj, NIT Agartala
 */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_RANGE 10000007
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define F first
#define S second
int parent[200007];
int size[200007];
int nexti[200007];
//////////////////////////////DSU WITH PATH COMPRESSION AND UNION BY SIZE////////////////////////////////////////////
void make_set(int v)
{
	parent[v]=v;
	size[v]=1;
	nexti[v]=v+1;
}
int find_set(int v)
{
	if(v==parent[v])
	{
		return v;
	}
	return parent[v]=find_set(parent[v]);
}
void union_set_wo_size_rank(int a,int b)
{
	parent[find_set(b)] = find_set(a);
}
void union_set_by_size(int a,int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a!=b)
	{
		
		if(size[a]<size[b])
		{
			swap(a,b);
		}
		
		/*
		if(rand()%2)
		{
			swap(a,b);
		} 
		*/ 
		parent[b]=a;
		//size[a]+=size[b];
	}
}
void union_set_skip(int i,int j)
{
	if(i>j)
	{
		swap(i,j);
	}
	for(int l=i+1;l<=j;)
	{
		union_set_by_size(l-1,l);
		int temp = nexti[l];
		nexti[l] = max(nexti[l],j);
		l = temp;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	

	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	//cout<<"\n"<<execution_time;
	//system("pause");
}
