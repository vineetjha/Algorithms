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
#define boost ios::sync_with_stdio(false) 
using namespace std;

ll a[MAX],BIT[MAX],n;

ll update(ll idx,ll val)
{
	idx+=1;
	while(idx<=n)
	{
		BIT[idx]+=val;
		idx+=(idx&(-1*idx));
	}
	return 0;
}

ll constructBITtree()
{
	ll i;
	rep(i,0,n+1)
	BIT[i]=0;
	rep(i,0,n)
	update(i,a[i]);
}

ll findSum(ll idx)
{
	ll sum=0;
	idx+=1;
	while(idx>0)
	{
		sum+=BIT[idx];
		idx-=(idx&(-1*idx));
	}
	return sum;
}

int main()
{
	boost;
	ll i,ch,q,idx,val;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	constructBITtree();
	rep(i,1,n+1)
	cout<<BIT[i]<<" ";
	cout<<endl;
	cin>>q;
	while(q--)
	{
		cin>>ch;
		switch(ch)
		{
			case 1:
				cin>>idx>>val;
				update(idx-1,val);
				break;
			case 2:
				cin>>idx;
				cout<<findSum(idx)<<endl;
				break;
		}
	}
	return 0;
}
