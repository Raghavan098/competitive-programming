long long mod_of_lcm(vector<long long> &a,long long n)
{
	long long ans=1;
	for(long long i=0;i<n;i++)
 	{
 		if(a[i]!=1)
 		{
 			for(long long j=i+1;j<n;j++)
 			{
 				a[j]/=__gcd(a[i],a[j]);
				//reducing along long remaining numbers by thier gcd with currebt number
			}
			ans=(ans*a[i])%M;//mod
		}
	}
	return ans;
}
