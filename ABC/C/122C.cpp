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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans;
    vector<int> rs(n+1);
    //累積和の最初を0初期化
    rs[0] = 0;
    rep(i,n){
        //配列外参照回避のため最初のみ特例措置
        if(i == 0){
            rs[i+1] = 0;
            continue;
        }
        //Cが見えた時,その前がAだったらCに対応する累積和の部分を+1更新
        if(s[i] == 'C'){
            if(s[i-1] == 'A'){
                rs[i+1] = rs[i] + 1;
                continue;
            }
        }
        //AC関係ない位置は一つ前を引き継ぐ
        rs[i+1] = rs[i];
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        ans = rs[r] - rs[l];
        cout << ans << endl;
    }
    return 0;
}
//累積和的クエリ対処問題
// babbbaaacacのような文字列である範囲にaが何回出てくるかは
//001111234455という最初から今の範囲にaが何回出てきたかの累積和を持つと
//範囲l,rが指定されたときに累積和配列をrsとすると
//rs[r]-rs[l]でその範囲内のaの個数を早く求めることができる
//これをACという２文字で同じことをやる
//今回はACが登場する時のCの場所で個数の更新を行なっている
//
