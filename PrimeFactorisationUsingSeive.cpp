ll seive()
{
	for(ll i=2;i<MAX;i++)
	p[i] = i;
	for(ll i=2;i*i<MAX;i++)
	{
		if(p[i] == i)
		{
			for(ll j=i*i;j<MAX;j+=i)
			{
				if(p[j] == j)
				p[j] = i;
			}
		}
	}
	return 0;
}
 
ll primeFac()
{
	for(ll i=2;i<MAX;i++)
	{
		map<ll,ll> mm;
		if(p[i] == i)
		{
			mm[i]++;
		}
		else
		{
			ll x = i;
			while(x!=1)
			{
				mm[p[x]]++;
				x/=p[x];
			}
		}
		pf[i].pb(mm);
	}
	return 0;
}
