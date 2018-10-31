#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cmath>
#include<iomanip>
#include<string.h>
#include<limits.h>
#include<queue>
#include<set>
#include<map>
#include<bits/stdc++.h>
using namespace std;
typedef long int llt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
  float n1;
	scanf("%f%d",&n1,&m);
	int arr[(int)n1],dp[(int)n1],index[(int)n1],i;
	for(i=0;i<(int)n1;i++){
		scanf("%d",&arr[i]);
		dp[i]=0;
		index[i]=-1;
	}
	int c=ceil(sqrt(n1));
  int n;
  n = (int)n1;
	int x=n/c,a,b,p;
	while(x>=0){
		a=x*c;
		b=min(n-1,(x+1)*c-1);
		index[b]=b;
		dp[b]=1;
		for(i=b-1;i>=a;i--){
			if(i+arr[i]>b){
				dp[i]=1;
				index[i]=i;
			}
			else{
				dp[i]=dp[arr[i]+i]+1;
				index[i]=index[arr[i]+i];
			}
		}
		x--;
	}
	// for(i=0;i<n;i++)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
	// for(i=0;i<n;i++)
	// 	cout<<index[i]<<" ";
	// cout<<endl;
	while(m--){
		scanf("%d",&p);
		if(p==0){
			scanf("%d%d",&a,&b);
			a--;
			arr[a]=b;
			x=a/c;
			b=a;
			a=x*c;
			//b=min(n-1,(x+1)*c-1);
			index[b]=b;
			dp[b]=1;
			for(i=b-1;i>=a;i--){
				if(i+arr[i]>b){
					dp[i]=1;
					index[i]=i;
				}
				else{
					dp[i]=dp[arr[i]+i]+1;
					index[i]=index[arr[i]+i];
				}
			}
		}
		else if(p==1){
			scanf("%d",&a);
			a--;
			b=0;
			while(a<n){
				i=a;
				b+=dp[a];
				if(a==index[a])
					a=a+arr[a];
				else
					a=index[a]+arr[index[a]];
			}
			if(index[i]<n)
				i=index[i];
			printf("%d %d\n",i+1,b);
		}
	}
}
