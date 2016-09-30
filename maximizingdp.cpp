	rep(i,1,strlen(s))
	{
		dp[i]=max(a[i],a[i]+dp[i-1]);
		maxi=max(dp[i],maxi);
		//cout<<dp[i]<<"  "<<maxi<<endl;
	}
