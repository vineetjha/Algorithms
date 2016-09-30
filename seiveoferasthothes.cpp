#include<bits/stdc++.h>
#include<string>
int seive(long long);
int main()
{
	long long n;
	scanf("%lld",&n);
	seive(n);
	return 0;
}
int seive(long long n)
{
	bool a[n+1];
	long long i,j;
	for(i=0;i<n+1;i++)
	a[i]=true;
	for(i=2;i*i<=n;i++)
	{
		a[0]=false;
		a[1]=false;
		for(j=i*i;j<=n;j+=i)
		{
			a[j]=false;
		}
	}
	long k;
	for(i=0;i<=n;i++)
	{
		if(a[i]==true)
		k++;
		//printf("\n%lld",i);
	}
	std::cout<<k;
	return 0;
}
