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
    int n;
    cin >> n;
    //stack 要素は書かれた数字・その個数
    stack<P> s;
    //現在の筒内のボールの総数をカウントする用
    int cnt = 0;
    rep(i,n){
        int a;
        cin >> a;
        //ボールが筒に入ったので+1
        cnt++;
        //stackが空の状態か、一つ前のボールに書かれた数字が違う場合
        if(s.empty() || s.top().first != a){
            //stackに書かれた数字a・(最初だから)1のpairをpush
            s.push({a,1});
        }else {
            //一つ前のボールと書かれた数字が同じなら
            //stackの最後に追加された要素のボールの個数を+1
            s.top().second++;
            //stackの最後に追加された要素のボールの個数が書かれた数字と
            //同じ数である場合それをpopでstackから取り除き
            //筒内のボールの個数から取り除いた個数a分引く
            if(s.top().second == a){
                s.pop();
                cnt -= a;
            }
        }
        //都度筒内のボールの個数を出力する
        cout << cnt << endl; 
    }
    return 0;
}
