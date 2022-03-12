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
    ll a, b, x;
    cin >> a >> b >> x;
    //二分探索のカーソル,lは買える整数の最小値(買えない場合の0)
    //rは買える整数が制約の最大より1多い買えない整数
    //絶対に二分探索の両端をok,ngにするため
    ll l = 0, r = 1000000001;
    //ラムダ式で実装[]が基本で&をつけると関数のスコープ外の
    //変数にもアクセスと使用ができる
    //桁数を求める関数
    auto keta = [&](ll c){
        //桁数
        int res = 0;
        //桁がなくなるまでループ
        while(c){
            //10で割り、下一桁ずつ消す処理
            c /= 10;
            //下一桁消せるなら桁があったわけなので桁数+1
            ++res;
        }
        //桁数を返す
        return res;
    };
    //整数を買う必要金額を求める関数
    //f(n)=A×N+B×d(N)
    auto f = [&](ll c){
        return a*c + b*keta(c);
    };
    //二分探索処理
    //ok,ngカーソルが隣り合っている(買える買えないの境界線がわかる)
    //までループを処理
    while(r - l > 1){
        //カーソルの中間にcを移動
        ll c = (l + r) / 2;
        //f(c)がx以下なら買えるのでokカーソルをcに移動
        //そうでないなら買えないのでngカーソルをcに移動
        if(f(c) <= x){
            l = c;
        }else {
            r = c;
        }
    }
    cout << l << endl;
    return 0;
}
//二分探索で解く問題
//答えを求める関数f(n)=A×N+B×d(N)が単調増加することから
//二分探索法を用いるとtleしない全探索プログラムにできる 
