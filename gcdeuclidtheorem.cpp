#include<stdio.h>
ll gcd(ll,ll);
ll main()
{
	ll a,b,g;
	scanf("%ld%ld",&a,&b);
	g=gcd(a,b);
	printf("%ld",g);
	return 0;
}
ll gcd(ll a,ll b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
