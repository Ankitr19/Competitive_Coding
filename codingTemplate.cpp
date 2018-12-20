/*
 * Ankit Raj, NIT Agartala
 */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_RANGE 10000007
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
int main()
{
	BOOST;
	NITRO;
	clock_t t1,t2;
	t1 = clock();
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//Main Code



	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	cout<<"\n"<<execution_time;
	system("pause");
}
