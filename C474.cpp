#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt mod = 1000000007;
int arr[4][4];
int getx(int i,int rot){
	int X=arr[i][0],Y=arr[i][1],temp;
	for(int j=0;j<rot;j++)
		{
		temp=X;
		X=(arr[i][3]-Y+arr[i][2]);
		Y=(temp-arr[i][2]+arr[i][3]);
		}

	return X;
}
int gety(int i,int rot){
  int X=arr[i][0],Y=arr[i][1],temp;
	for(int j=0;j<rot;j++)
		{
		temp=X;
		X=(arr[i][3]-Y+arr[i][2]);
		Y=(temp-arr[i][2]+arr[i][3]);
		}

	return Y;
}
bool solve(int a1,int a2,int a3,int a4){
  int newarr[4][2];
  int rot[4];
  rot[0] = a1;
  rot[1] = a2;
  rot[2] = a3;
  rot[3] = a4;
  for(int i=0;i<4;i++){
		// cout<<"old "<<arr[i][0]<<" "<<arr[i][1]<<endl;
    newarr[i][0] = getx(i,rot[i]);
    newarr[i][1] = gety(i,rot[i]);
    // cout<<newarr[i][0]<<" "<<newarr[i][0]<<endl;
  }
  int temp;
  vector<llt> v;

  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      v.push_back(llt(newarr[i][0]-newarr[j][0])*llt(newarr[i][0]-newarr[j][0])+llt(newarr[i][1]-newarr[j][1])*llt(newarr[i][1]-newarr[j][1]));
    }
  }
  sort(v.begin(),v.end());

  // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<" "<<v[5]<<" "<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<endl;
  if(v[0]==v[1] and v[1]==v[2] and v[2]==v[3] and v[4]==v[5] and v[0]!=0 and v[4]!=0){
    return true;
  }
  return false;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        cin>>arr[j][k];
      }
    }
		// for(int i=0;i<4;i++){
		// 	cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
		// }
    int cnt=0;
    int cnre[4];
    int mincnt = 10000000;
    for(int a1=0;a1<4;a1++){
      for(int a2=0;a2<4;a2++){
        for(int a3=0;a3<4;a3++){
          for(int a4=0;a4<4;a4++){
            if(solve(a1,a2,a3,a4)==true){
              // cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
              cnt = 0;
              cnre[0] = a1;
              cnre[1] = a2;
              cnre[2] = a3;
              cnre[3] = a4;
              for(int b = 0;b<4;b++){
                if(cnre[b] == 1){
                  cnt+=1;
                }
                else if(cnre[b]==2){
                  cnt+=2;
                }
                else if(cnre[b]==3){
                  cnt+=3;
                }
              }
              if(cnt<mincnt){
                mincnt = cnt;
              }
            }
          }
        }
      }
    }
		if(mincnt==10000000){
			cout<<-1<<endl;
		}
		else
    	cout<<mincnt<<endl;
  }
  return 0;
}
