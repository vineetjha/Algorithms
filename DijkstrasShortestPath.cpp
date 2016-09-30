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

ll n,g[1003][1003],m,x,y,s,dist[1003];

int findMin(bool sptset[])
{
	int mini=INF,idx=-1;
	for(int i=0;i<n;i++)
	{
		if(sptset[i]==false && mini>dist[i])
		{
			mini=dist[i];
			idx=i;
		}
	}
	if(idx!=-1)
	return idx;
}

int dj()
{
	bool sptset[n];
	memset(sptset,false,sizeof(sptset));
	cin>>s;
	for(int i=0;i<n;i++)
	dist[i]=INF;
	dist[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=findMin(sptset);
		cout<<u<<endl;
		sptset[u]=true;
		for(int j=0;j<n;j++)
		{
			if(sptset[j]==false && g[u][j]!=0 && dist[u]!=INF && dist[u]+g[u][j]<dist[j] )
			{
				dist[j]=dist[u]+g[u][j];
			}
		}
	}
	return 0;
}

int main()
{
	ll i,j,w;
	cin>>n>>m;
	rep(i,0,n)
	rep(j,0,n)
	g[i][j]=0;
	rep(i,0,m)
	{
		cin>>x>>y>>w;
		g[x][y]=g[y][x]=w;
	}
	rep(i,0,n)
	{
		rep(j,0,n)
		cout<<g[i][j]<<" ";
		cout<<endl;
	}
	dj();
	for(i=0;i<n;i++)
	cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}
