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
string f(ll n){
    //ベースケース 
    if(n == 0){
        return "";
    }
    n--;
    return f(n / 26) + string(1,'a' + n % 26);
}
int main(){
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
//26進数もどきを再帰関数で解くパターン
//進数を考えると普通は0スタートだが、問題が1スタートなので都度-1する
//再起関数処理時はf(n/26)に到達したらstring(1,'a'+n%26)の項を一旦処理せず
//再帰先に向かうので500がsfだとすると500/26を3回繰り返すと0になるため
//3回再帰してベースケースで""を返し、再帰元で""+s=sとなり
//さらに再帰元で""+s+f=sfとなり処理を終了する
