
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
typedef long long int llt;
typedef pair<llt,llt> pll;
typedef pair<char,char> pcc;
typedef pair<string,string> pss;
typedef pair<llt,char> plc;
#define endl "\n"
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define make0(a) memset(a,0,sizeof(a))
#define trv(v) for(llt i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<endl;
bool cmp(plc p1,plc p2){
	return p1.first>p2.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=n-1;i>0;i--){
		if(s[i]>=s[i-1])
			continue;
		int mid,low=0,high=s[i-1].size()-1,ans=-1;
		while(low<=high){
			mid=(low+high)/2;
			string temp=s[i-1].substr(0,mid+1);
			// cout<<i<<" "<<mid<<" "<<temp<<" "<<s[i]<<endl;
			if(temp<=s[i]){
				ans=mid;
				low=mid+1;
			}
			else
				high=mid-1;
		}
		cnt+=(s[i-1].size())-ans-1;
		s[i-1]=s[i-1].substr(0,ans+1);
	}
	// cout<<cnt<<endl;
	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
}
