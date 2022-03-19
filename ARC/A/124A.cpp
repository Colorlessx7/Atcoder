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
using mint = modint998244353;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> multi(n,k);
    rep(i,k){
        char c;
        int v;
        cin >> c >> v;
        v--;
        if(c == 'L'){
            for(int j = v; j >= 0; j--){
                if(j == v){
                    multi[j] = 1;
                    continue;
                }
                if(multi[j] == 1){
                    continue;
                }
                multi[j]--;
            }
        }else {
            for(int j = v; j < n; j++){
                if(j == v){
                    multi[j] = 1;
                    continue;
                }
                if(multi[j] == 1){
                    continue;
                }
                multi[j]--;
            }
        }
    }
    mint ans = 1;
    rep(i,n){
        ans *= multi[i];
    }
    cout << ans.val() << endl;
    return 0;
}
//場合の数を数え上げる問題
//c,vで指定されている箇所は数字1つしかありえない
//c==Lならvより左は選択できる数が1減る
//c==Rならvより右は選択できる数が1減る
//そうやって全てのiでカード一枚ごとのとりうる数を減らしていって
//最後に残ったカード一枚ごとのとりうる数を全てかけてmodをとる
