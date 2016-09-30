#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define MM(a,x) memset(a,x,sizeof(a)) 
using namespace std;

int count( int S[], int m, int n )
{
    int i, j, x, y;
    int table[n+1][m];
    for (i=0; i<m; i++)
    table[0][i] = 1;  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }
    rep(i,0,n+1)
    {
    	rep(j,0,m)
    	{
    		cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
    return table[n][m-1];
}

int main()
{
    int i,n,m,arr[1003];
    cin>>n;
    rep(i,0,n)
    cin>>arr[i];
    cin>>m;
    count(arr, n, m);
    return 0;
}
