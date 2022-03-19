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
    int n;
    cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> a;
    priority_queue<ll,vector<ll>,greater<ll>> b;
    priority_queue<ll,vector<ll>,greater<ll>> c;
    ll x;
    rep(i,n){
        cin >> x;
        a.push(x);
    }
    rep(i,n){
        cin >> x;
        b.push(x);
    }
    rep(i,n){
        cin >> x;
        c.push(x);
    }
    ll suba,subb;
    ll ans = 0;
    while(a.size()){
        suba = a.top();
        a.pop();
        while(b.size() && b.top() <= suba){
            b.pop();
        }
        if(b.empty()){
            break;
        }
        subb = b.top();
        b.pop();
        while(c.size() && c.top() <= subb){
            c.pop();
        }
        if(c.empty()){
            break;
        }
        c.pop();
        ans++;
    }
    cout << ans << endl;
    return 0;
}
//priority_queueを使う問題
//まずAを決めて、そのA以下のBを無視(削除)する
//その後に最初のAより大きいBをBに決めてそのB以下のCを無視(削除)する
//そして最初のBより大きいCを決めたら1組完成したことになるのでansを+1する
//そして次のAを決めて...を繰り返す
//途中でBまたはCの要素がなくなってしまったら終わりにする
