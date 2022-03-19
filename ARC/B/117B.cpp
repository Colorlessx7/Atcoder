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
using mint = modint1000000007;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n){
        cin >> a[i];
    }
    //差分を取るために0も必要
    a[n] = 0;
    //順番関係ないので考えやすくするためにsort
    sort(all(a));
    //ヤング図形に直した時のビルの高さの差分を格納する配列
    vector<int> multi;
    rep(i,n){
        //差分計算
        ll x = a[i+1] - a[i];
        //差分は操作で0~xまでできるので+1
        x++;
        multi.push_back(x);
    }
    n = multi.size();
    mint ans = 1;
    //各差分の+1を全てかける
    rep(i,n){
        ans *= multi[i];
    }
    cout << ans.val() << endl;
    return 0;
}
//小さいところから考えたり、差分を考えると計算で解ける問題
//a配列が(0),1,2,2,4,5,5だとすると差分列は0,1,0,2,1,0となる
//操作によってビルの4段目の高さを変えると
//a配列が(0),1,2,2,3,4,4となり、対応する差分列は0,1,0,1,1,0となる
//これにより差分列の数字を一つ変えた処理ということができる(かつ差分列それぞれ独立)
//各段差には操作を続けることで差分列の値はそれぞれ0~元の差分列の値まで変化させることができる
//よって操作数は差分列のそれぞれの要素に+1したものを全てかけると答えになる
//今回の例だと1*2*1*3*2*1=12で12通りとなる
//この数字は値が大きくなる可能性があるのでmodintを使用する
