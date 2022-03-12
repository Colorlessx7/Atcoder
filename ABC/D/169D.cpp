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
    ll n;
    cin >> n;
    //素因数分解した時の(被乗数,指数部)
    vector<pair<ll,int>> fs;
    //素因数分解処理,1は割っても変わらないので2から
    //試し割り法で2からsqrt(N)までループを回す
    for(ll i = 2; i*i <= n; i++){
        //x:ある数iで何回割り切れるか格納(素因数分解時の指数部)
        int x = 0;
        //nをある数iで割り切れるなら割る
        while(n%i == 0){
            n /= i;
            //割り切れたので指数+1
            ++x;
        }
        //割り切れなくなったら素因数分解の結果としてfsに格納
        fs.emplace_back(i,x);
    }
    //最終的にnが1にならなかった場合はsqrt(N)以上の素数が分解されていないことになるので
    //n^1をfsに格納
    if(n != 1){
        fs.emplace_back(n,1);
    }
    //操作できる最大回数
    int ans = 0;
    //範囲for文,素因数分解された全ての要素に対して処理
    for(auto p : fs){
        //x:素因数分解の指数部
        int x = p.second;
        //最小から貪欲,i^1から割る処理
        int b = 1;
        //割り切れる(指数部xがb以上)ならループを続行
        while(b <= x){
            //割る処理
            x -= b; 
            //同じもので割れないので+1
            b++;
            //割れた回数分答えを足す
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
//素因数分解して貪欲に解く問題
//
