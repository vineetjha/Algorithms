#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MM(a,x) memset(a,x,sizeof(a))
#define boost ios::sync_with_stdio(false) 
using namespace std;

int n,m,a[MAX],st[MAX],en[MAX],cur,E[MAX],arr[MAX],lvl[MAX],X[MAX],distinct,ans[MAX],block_size,cnt[MAX],LCA[MAX],BL[MAX],d[MAX];
pair<int,int> seg[MAX];
pair< pair<int,int> ,int > qu[MAX];
bool vis[MAX];
vector<int> v[MAX];

struct que{
	int id, l, r, lc;
	bool operator < (const que& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAX];

inline bool cmp(pair< pair<int,int> , int > &x,pair< pair<int,int> , int > &y)
{
	ll blk_x = x.F.F/block_size;
	ll blk_y = x.F.F/block_size;
	if(blk_x != blk_y)
	return blk_x < blk_y;
	return x.F.S<y.F.S;
}

int dfs(int s,int parent)
{
	vis[s] = true;
	st[s] = cur;
	arr[cur] = s;
	lvl[s] = lvl[parent] + 1;
	E[cur++] = s;
	for(int i=0;i<v[s].size();i++)
	{
		if(!vis[v[s][i]])
		{
			dfs(v[s][i],s);
		}
	}
	en[s] = cur;
	arr[cur] = s;
	E[cur++] = parent;
	return 0;
}

int build_tree(int idx,int st,int en)
{
	if(st == en)
	{
		seg[idx].F = X[st];
		seg[idx].S = st;
	}
	else
	{
		int mid = (st+en)/2;
		build_tree(2*idx+1,st,mid);
		build_tree(2*idx+2,mid+1,en);
		seg[idx].F = min(seg[2*idx+1].F,seg[2*idx+2].F);
		seg[idx].S = seg[2*idx+1].F < seg[2*idx+2].F ? seg[2*idx+1].S : seg[2*idx+2].S;
	}
}

int query(int node,int start,int end,int l,int r)
{
	if(l>end||start>r)
	return MAX;
	if(l<=start&&r>=end)
	{
		return node;
	}
	int p1,p2;
	int mid=(start+end)/2;
	p1=query(2*node+1,start,mid,l,r);
	p2=query(2*node+2,mid+1,end,l,r);
	return seg[p1].F < seg[p2].F ? p1 : p2 ;
}

inline int add(ll x)
{
	//cout<<"adding "<<x<<endl;
	x = a[x];
	if(cnt[x] == 1)
	distinct--;
	cnt[x]++;
	if(cnt[x] == 1)
	distinct++;
}

inline int remove(ll x)
{
	//cout<<"removing "<<x<<endl;
	x = a[x];
	if(cnt[x] == 1)
	distinct--;
	cnt[x]--;
	if(cnt[x] == 1)
	distinct++;
}


int main()
{
	int x,y;
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	for (int i = 1; i <= n; i++) 
	cin>>a[i];
	memcpy(d + 1, a + 1, sizeof(int) * n);
 	int K;
	sort(d + 1, d + n + 1);
	K = unique(d + 1, d + n + 1) - d - 1;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(d + 1, d + K + 1, a[i]) - d;
	rep(i,0,n-1)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	cur = 0;
	dfs(1,-1);
	

	int lca_size = cur-1;
	block_size = sqrt(cur);
	for (int i = 1; i < cur; i++) 
	BL[i] = (i - 1) / block_size + 1;
	rep(i,0,lca_size)
	{
		X[i] = lvl[E[i]];
	}
	build_tree(0,0,lca_size-1);
	seg[MAX].F = MAX;
	rep(i,0,m)
	{
		int XX;
		cin>>x>>y;
		if(st[x]>st[y])
		{
			XX = query(0,0,cur-1,st[y],st[x]);
		}
		else
		{
			XX = query(0,0,cur-1,st[x],st[y]);
		}
		Q[i].lc = E[seg[XX].S];
		if (st[x] > st[y]) swap(x, y);
		if (Q[i].lc == x) Q[i].l = st[x], Q[i].r = st[y];
		else Q[i].l = en[x], Q[i].r = st[y];
		Q[i].id = i;
		LCA[i] = E[seg[XX].S];
	}
	
	sort(qu,qu+m);
	distinct = 0;
	int mleft = 0,mright = -1;
	for(int i=0;i<m;i++)
	{
		int left = Q[i].l;
		int right = Q[i].r;
		
		while(mright < right) {
            mright++;
            add(arr[mright]);
        }
        while(mright > right) {
            remove(arr[mright]);
            mright--;
        }

        while(mleft < left) {
            remove(arr[mleft]);
            mleft++;
        }
        while(mleft > left) {
            mleft--;
            add(arr[mleft]);
        }
        if(LCA[Q[i].lc] != Q[i].l)
		ans[Q[i].id] = ++distinct;
		else
		ans[Q[i].id] = distinct;
	}
	rep(i,0,m)
	cout<<ans[i]<<endl;
	
	return 0;
}
