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

char c1[MAX],c2[MAX];

int main()
{
	ll i,j;
	cin>>c1>>c2;
	ll x1=strlen(c1)+1,x2=strlen(c2)+1;
	ll a[x1][x2];
	
	for(i=0;i<x1;i++)
	a[i][0]=0;
	for(i=0;i<x2;i++)
	a[0][i]=0;
	for(i=1;i<x1;i++)
	{
		for(j=1;j<x2;j++)
		{
			if(c1[i]==c2[j])
			{
				a[i][j]=a[i-1][j-1]+1;
			}
			else
			{
				a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
	}
	for(i=0;i<x1;i++)
	{
		for(j=0;j<x2;j++)
		cout<<a[i][j]<<"  ";
		cout<<endl;
	}
	
	ll idx=a[x1-1][x2-1];
	char arr[idx+1];
	i=x1,j=x2;
	while(i>0 && j>0)
	{
		if(c1[i-1] == c2[j-1])
		{
			arr[idx]=c1[i-1];
			i--;
			j--;
			idx--;
		}
		else
		{
			if(a[i-1]>a[j-1])
			i--;
			else
			j--;
		}
	}
	cout<<arr<<endl;
	return 0;
}
