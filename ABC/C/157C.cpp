#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, m;
    cin >> n >> m;
    //s,cに関するpair配列
    vector<P> p(m);
    rep(i,m){
        cin >> p[i].first >> p[i].second;
    }
    //0~999まで候補を全通り全探索する
    rep(x,1000){
        //0が1桁であることを処理するためにketaは1スタート
        //whileまでは0が1桁であることを処理するためにやっている
        int keta = 1;
        //nx:計算用の仮の変数
        int nx = x/10;
        //xの各桁の数字を保存する配列
        vector<int> d(1,x%10);
        //0になるまで割ることでnxの各桁を取り出す
        while(nx){
            keta++;
            d.push_back(nx%10);
            nx /= 10;
        }
        //nxと入力nの桁数が違うなら以降の処理をスルー
        if(keta != n){
            continue;
        }
        bool ok = 1;
        //nxの各桁の数字を取り出して配列に格納する段階で逆に
        //なっているためreverse
        reverse(all(d));
        rep(i,m){
            //入力での指定とxの各桁に違いがあればフラグを立てる
            if(d[p[i].first-1] != p[i].second){
                ok = 0;
            }
        }
        //小さいものから全探索しているので最初に条件を
        //満たしたものがそのまま答えになる
        if(ok){
            cout << x << endl;
            return 0;
        }
    }
    //条件を満たすものが存在しなかったら-1
    cout << -1 << endl;
    return 0;
}
//0~999までの1000通りなので全探索
//
