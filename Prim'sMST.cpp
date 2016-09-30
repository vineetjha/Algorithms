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

ll s,n,m,g[1003][1003],key[1003],parent[1003];

int findMin(bool mstset[])
{
	ll i,mini=INF,idx=-1;
	for(i=0;i<n;i++)
	{
		if(mstset[i]==false && key[i]<mini)
		{
			mini=key[i];
			idx=i;
		}
	}
	if(idx!=-1)
	return idx;
}

int primMST(ll s)
{
	ll i;
	bool mstset[n]={false};
	rep(i,0,n)
	{
		key[i]=INF,parent[i]=-1;
	}
	key[s]=0;
	for(i=0;i<n;i++)
	{
		int u=findMin(mstset);
		mstset[u]=true;
		for(int j=0;j<n;j++)
		{
			if(mstset[j]==false && g[u][j]!=0 && key[j]>g[u][j])
			{
				parent[j]=u;
				key[j]=g[u][j];
			}
		}
	}
	return 0;
}

int main()
{
	ll i,j,x,y,w;
	cin>>n;
	cin>>m;
	rep(i,0,n)
	rep(j,0,n)
	g[i][j]=0;
	rep(i,0,m)
	{
		cin>>x>>y>>w;
		g[x][y]=g[y][x]=w;
	}
	cin>>s;
	primMST(s);
	rep(i,1,n)
	cout<<parent[i]<<"  "<<i<<"  "<<key[i]<<endl;
	cout<<endl;
	return 0;
}
