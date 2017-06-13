#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MM(a,x) memset(a,x,sizeof(a))
using namespace std;

ll n,a[MAX],block_size,q,ans[MAX],cnt[MAX],answer;
pair< pair<ll,ll> , ll > query[MAX];

inline bool cmp(pair< pair<ll,ll> , ll > &x,pair< pair<ll,ll> , ll > &y)
{
	ll blk_x = x.F.F/block_size;
	ll blk_y = x.F.F/block_size;
	if(blk_x != blk_y)
	return blk_x < blk_y;
	return x.F.S<y.F.S;
}

inline int add(ll x)
{
	answer -= cnt[x]*cnt[x]*x;
	cnt[x]++;
	answer += cnt[x]*cnt[x]*x;
}

inline int remove(ll x)
{
	answer -= cnt[x]*cnt[x]*x;
	cnt[x]--;
	answer += cnt[x]*cnt[x]*x;
}

int main()
{
	ll x,y;
	scanf("%I64d%I64d",&n,&q);
	//cin>>n>>q;
	block_size = sqrt(n);
	rep(i,0,n)
	scanf("%I64d",&a[i]);
	rep(i,0,q)
	{
		scanf("%I64d%I64d",&x,&y);
		x--,y--;
		query[i].F.F = x,query[i].F.S = y;
		query[i].S = i;
	}
	sort(query,query+q,cmp);
	
	ll mleft = 0,mright = -1;
	for(ll i=0;i<q;i++)
	{
		ll left = query[i].F.F;
		ll right = query[i].F.S;
		
		//right to be evaluated first
		while(mright < right) {
            mright++;
            add(a[mright]);
        }
        while(mright > right) {
            remove(a[mright]);
            mright--;
        }

        while(mleft < left) {
            remove(a[mleft]);
            mleft++;
        }
        while(mleft > left) {
            mleft--;
            add(a[mleft]);
        }
		ans[query[i].S] = answer;
	}
	rep(i,0,q)
	printf("%I64d\n",ans[i]);
	return 0;
}
