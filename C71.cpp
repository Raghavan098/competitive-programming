#include<iostream>
#include<vector>
#include <cmath>
#include <limits>
using namespace std;
int arr[100001];
int n;


int main(){

	vector<int> a(100001,0);
	a[2]=1;
	a[3]=0;
	for(int i=6;i<=100000;i+=2)
		a[i]=1;
	for(int i=3;i<=100000;i++){
		if(!a[i]){
			for(int j=i+i;j<=100000;j+=i)
				a[j]=1;
		}
	}


	cin>>n;

	vector<int> prime_factors;
	int temp=n;

	for(int j=3;j<100000 ;j++){
		if(temp%j==0 && !a[j])
			prime_factors.push_back(j);
	}


	for(int i=0;i<n;i++)
		cin>>arr[i];

	int flag=0;
	for(int i=0;i<prime_factors.size() && !flag;i++){
		for(int j=0;j<n/prime_factors[i]&& !flag;j++){
			int k;
			for(k=0;k<prime_factors[i];k++){
				if(!arr[j+k*(n/prime_factors[i])])
					break;
			}
			if(k==prime_factors[i]){
				flag=1;
				break;
			}
		}
	}

	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}
