#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int pw(int x,int y,int mod){
	if(x%mod==0)
		return 0;
	x%=mod;
	int ans=1;
	while(y){
		if(y&1)
			ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int tmp1 = a & 1;
	int tmp2 = pw(a,pw(b,c,4),5);
	for(int i = 0; i <= 9; i++){
		if(i%2 == tmp1 && i%5 == tmp2){
			cout << i << endl;
        }
    }        
	return 0;
}
