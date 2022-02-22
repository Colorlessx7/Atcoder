//setのイテレータ移動はadvanceを使うことなどでできる
//参考資料:https://atcoder.jp/contests/apg4b/tasks/APG4b_ai?lang=ja

//ABC234でTLEする愚直解(Pが同じものがある場合間に合ってもWAかも？）

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
    int n, k;
    cin >> n >> k;
    k--;
    set<int> st;
    rep(i,n){
        int p;
        cin >> p;
        st.insert(p);
        if(i >= k){
            auto itr = st.rbegin();
            advance(itr,k);
            cout << (*itr) << endl;
        }
    }
    return 0;
}
