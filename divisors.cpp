// Code By -- Vineet Jha

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
using namespace std;

ll n,p[MAX],k,t;
vector <ll> v;

void primeFactors(ll n)
{
    while (n%2 == 0)
    {
        v.push_back(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        v.push_back(n);
}

int main()
{
	ll j;
	cin>>t;
	while(t--)
	{
		ll i,prd=1,cnt;
		cin>>n;
		primeFactors(n);
		rep(i,0,v.size())
		{
			cnt=1;
			j=i;
			if(i+1<v.size())
			{
				while(v[i]==v[i+1])
				{
					cnt++;
					++i;
					if(i==v.size())
					break;
				}
			}
			prd*=((pow(v[j],cnt+1)-1)/(v[j]-1));
		}
		//cout<<prd<<endl;
		if(prd==2*n)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		v.clear();
	}
	//rep(i,0,v.size())
	//cout<<v[i]<<" ";
	return 0;
}
