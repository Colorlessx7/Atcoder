#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> c(n);
    rep(i,n){
        c[i] = a[i] - i - 1;
    }
    rep(qi,q){
        ll k;
        cin >> k;
        //rを二分探索 Cの中でk以上の要素のうち最初のものを返す
        int r = lower_bound(all(c),k) - c.begin();
        ll ans;
        //r = 0:最初のAより前にある
        if(r == 0){
            ans = k;
        }else {
            //rが0じゃないのでr-1が配列外参照を起こさない
            ans = a[r-1] + (k - c[r-1]);
        }
        cout << ans << endl;
    }
    return 0;
}
//二分探索法で解く問題
//A = {3,5,6,7}とするとその中間は{1,2,4,8~}で、Ai以下の数字の個数をC配列にとると
//C = {2,3,3,3}となる Cは短調増加なので二分探索ができる
//仮にk=2ならr=0となりans=2となる
//k=3ならr=1となり答えはA[0]の3に(k-c[r-1])で(3-2)の1がたされてans=4となる
//k=10ならrはc配列の終わりの一つ先を示し、ans=7+(10-3)=14となる 
