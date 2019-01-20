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
#define V 9
int Euler[2*V - 1];
int level[2*V - 1];
int firstOccurence[V+1];
int ind;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* newNode(int k)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = k;
	temp->left = temp->right = NULL;
	return temp;
}
int RMQUtil(int index, int ss, int se, int qs, int qe, int* st)
{
	if(qs<=ss && se<=qe)
	{
		return st[index];
	}
	else if(se < qs || ss > qe)
	{
		return -1;
	}
	int mid = (ss+se)/2;
	int q1 = RMQUtil(2*index+1,ss,mid,qs,qe,st);
	int q2 = RMQUtil(2*index+2,mid+1,se,qs,qe,st);
	if(q1==-1)
	{
		return q2;
	}
	else if(q2==-1)
	{
		return q1;
	}
	return (level[q1]<level[q2])? q1:q2;
}
int RMQ(int* st, int n, int qs, int qe)
{
	if(qs<0 || qe>(n-1) || qs>qe)
	{
		cout<<"Wrong Input"<<"\n";
		return -1;
	}
	return RMQUtil(0, 0, n-1, qs, qe, st);
}
void constructSTUtil(int si,int ss, int se, int arr[],int* st)
{
	if(ss==se)
	{
		st[si] = ss;
	}
	else
	{
		int mid = (ss+se)/2;
		constructSTUtil(si*2+1,ss,mid,arr,st);
		constructSTUtil(si*2+2,mid+1,se,arr,st);
		if(arr[st[2*si+1]]<arr[st[2*si+2]])
		{
			st[si] = st[2*si+1];
		}
		else
		{
			st[si] = st[2*si+2];
		}
	}
}
int Log2(int x)
{
	int ans = 0;
	while(x>>=1)
	{
		ans++;
	}
	return ans;
}
int* constructST(int arr[],int n)
{
	int x = Log2(n)+1;
	int mx_size = 2*(1<<x) - 1;
	int* st = new int[mx_size];
	constructSTUtil(0,0,n-1,arr,st);
	return st;
}
void eulerTour(Node* root, int l)
{
	if(root)
	{
		Euler[ind] = root->data;
		level[ind] = l;
		ind++;
		if(firstOccurence[root->data]==-1)
		{
			firstOccurence[root->data] = ind;
		}
		if(root->left)
		{
			eulerTour(root->left,l+1);
			Euler[ind]=root->data;
			level[ind]=l;
			ind++;
		}
		if(root->right)
		{
			eulerTour(root->right,l+1);
			Euler[ind] = root->data;
			level[ind] = l;
			ind++;
		}
	}
}
int findLCA(Node* root,int u,int v)
{
	memset(firstOccurence,-1,sizeof(firstOccurence));
	ind = 0;
	eulerTour(root, 0);
	int *st = constructST(level,2*V-1);
	if(firstOccurence[u]>firstOccurence[v])
	{
		swap(u,v);
	}
	int qs = firstOccurence[u];
	int qe = firstOccurence[v];
	cout<<qs<<" "<<qe<<"\n";
	int index = RMQ(st,2*V-1,qs,qe);
	cout<<index<<"\n";
	return Euler[index];
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
	Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
  
    int u = 4, v = 9; 
    printf("The LCA of node %d and node %d is node %d.\n",  
            u, v, findLCA(root, u, v));

	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	//cout<<"\n"<<execution_time;
	//system("pause");
}
