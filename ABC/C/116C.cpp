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
    int n;
    cin >> n;
    vector<int> h(n+2);
    h[0] = 0;
    h[n+1] = 0;
    rep2(i,n){
        cin >> h[i];
    }
    //山が何個あるか確認するフラグ
    bool f = 0;
    //全体の処理を続けるかどうかのフラグ
    bool end = 1;
    //山の数をカウント
    int cnt = 0;
    //山の最小値をセットする変数,minをとるため最大にしておく
    int x = INT_MAX;
    //最終的な答え
    int ans = 0;
    while(end){
        //初期化要素
        f = 0;
        x = INT_MAX;
        //山が何個あるか調査するループ
        //(0で分断された数字の集団が何個あるか)
        rep(i,n+2){
            //これまで0だったのが変わったらフラグfを反転して山の数を+1
            if(!f && h[i] != 0){
                f = 1;
                cnt++;
            }
            //これまで0ではなかったのが0になったらフラグfを反転
            if(f && h[i] == 0){
                f = 0;
            }
        }
        //山が存在しない(全処理終了である)のでループを終了させる
        if(cnt == 0){
            end = 0;
        }
        //数字が0でない部分の最小値を求める
        rep(i,n+2){
            if(h[i] != 0){
                x = min(x,h[i]);
            }
        }
        //それぞれの山(cntの数存在する)に対してxずつ下げるので
        //x * cntを答えにたす
        ans += x * cnt;
        rep(i,n+2){
            //山の高さを下げる処理
            if(h[i] != 0){
                h[i] -= x;
            }
        }
        //初期化要素
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}
//逆から考えると山を上から叩いて平らにする問題と同義である
//
