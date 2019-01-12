/*
 * Ankit Raj, NIT Agartala
 */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_RANGE 1007
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
#define pb push_back
#define mp make_pair
typedef pair<int,int> P;
int h,w;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int matrix[MAX_RANGE][MAX_RANGE];
bool used[MAX_RANGE][MAX_RANGE];
bool inside(int x,int y)
{
	if(x>=0 && x<h && y>=0 && y<w)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int solve()
{
	//build matrix first or take the input
	//apply bfs or dfs to traverse the matrix
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(used[i][j])continue;
			queue<P>Q;
			Q.push(P(i,j));
			used[i][j] = true;
			while(!Q.empty())
			{
				P p = Q.front();
				Q.pop();
				int x = p.first;
				int y = p.second;
				for(int d=0;d<4;d++)
				{
					int ni = x + dx[d];
					int nj = y + dy[d];
					if(inside(ni,nj))
					{
						if(//check condition)
						{
							if(!used[ni][nj])
							{
								used[ni][nj] = true;
								Q.push(P(ni,nj));
							}
						}
					}
				}
			}
		}
	}
			
}
int main()
{
}
