#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(3);//分布　各桁それぞれ3で割った時の余り0,1,2の個数
    rep(i,n){
      c[(s[i] - '0') % 3]++;//集計　一桁ずつ文字を整数に変換して3で割ったあまりを計算し0,1,2の対応する部分の個数を増やす
    } 
    int x = 0;
    rep(i,3){
        x += c[i]*i;//全体の余りの和の集計
    } 
    int ans = INF;//答えの変数　あらかじめintに収まるでかい値を入れる
    rep(i1,3){
        rep(i2,3) {
            if (c[1] < i1){//11で1を2個消すような処理を弾く
                continue;
            } 
            if (c[2] < i2){//22で2を2個消すような処理を弾く
                continue;
            } 
            if (i1 + i2 == n){//消す個数が桁数と一致するような処理を弾く
                continue;
            } 
            int nx = x;
            nx -= i1 * 1;
            nx -= i2 * 2;
            if (nx % 3 == 0){//３で割り切れるなら処理
                ans = min(ans, i1 + i2);
            } 
        }
    } 
    if (ans == INF){//不可能な場合の処理
        ans = -1;
    } 
    cout << ans << endl;
    return 0;
}
