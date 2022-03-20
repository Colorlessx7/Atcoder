#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
//約数列挙
void divisor(ll n, vector<ll>& div) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i * i != n) div.push_back(n / i);
        }
    }
    sort(all(div));
    return;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> div;
    divisor(n,div);
    int x = div.size();
    ll ans = 0;
    rep(i,x){
        if(n / div[i] % 2 != 0){
            ans++;
        }
    }
    ans *= 2;
    cout << ans << endl;
    return 0;
}
//nの約数を全列挙して、nから各約数を割ったものの偶奇を判断し、
//それが奇数ならカウントしていく
//最後にそのカウントしたものを*2する

//例の12だと
//約数は1,2,3,4,6,12の6つあり、
//12/1=12,12/2=6,12/3=4,12/4=3,12/6=2,12/12=1で
//nから各約数を割ったものが奇数のものが2つある
//偶数だとn/div[i]-1,n/div[i],n/div[i]+1という感じで等差数列のn/div[i]の左右
//で+-を使った辻褄合わせができないから奇数だけ取り出す
//*2するのは12と-11~12が対応し、3~5と-2~5が対応することがわかるため
