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
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    string t;
    while(x){
        if(x % 2 == 0){
            t += '0';
        }else {
            t += '1';
        }
        x /= 2;
    }
    //2進数文字列に変換する過程で桁が逆になるためreverse
    reverse(all(t));
    rep(i,n){
        //U:根に戻る(最後のbitの消去),L:葉の左に移動(末尾にbit0を追加)
        //R:葉の右に移動(末尾にbit1を追加)
        if(s[i] == 'U'){
            t.pop_back();
        }else if(s[i] == 'L'){
            t += '0';
        }else {
            t += '1';
        }
    }
    //10進数に直す過程で下の桁から見たいのでreverse
    reverse(all(t));
    ll ans = 0;
    n = t.size();
    //2進数の桁の10進数に対応させた時の倍率(1,2,4,8...)
    ll multi = 1;
    rep(i,n){
        //bitが立っているならば答えに桁に対応する数字を足す
        if(t[i] == '1'){
            ans += multi;
        }
        //桁に対応する数字の倍率を2倍して次の桁に備える
        multi *= 2;
    }
    cout << ans << endl;
    return 0;
}
//Binary Treeが1,10,11,100,101,110,111と2進数になっていることを利用して
//与えられたxを二進数の文字列に直して操作をしてから最後に10進数の数字に直す問題
