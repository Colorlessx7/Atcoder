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
int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 1; i <= 2 * n; i++){
        if(2 <= i - k && i - k <= 2 * n){
            //x:i
            ans += min(i - 1, 2 * n + 1 - i) * min((i - k) - 1, 2 * n + 1 - (i - k));
        }
    }
    cout << ans << endl;
    return 0;
}
//考察解
//f(N,K)を2つの整数の組(a,b)であって、1≤a,b≤Nかつa+b=Kを満たすものの個数とすると
//f(N,K)=min(K−1,2N+1−K)となる(K=2,3,…,2N)
//元の問題においてKの条件は(a+b)−(c+d)=Kとなるのでまずx=a+bを固定する
//すると条件はa+b=xかつc+d=x−Kと書ける
//よって答えはf(N,x)×f(N,x−K)となる。したがってx=2,..,2Nに対しての
//f(N,x)×f(N,x−K)を足し合わせたものが答えとなる
