#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int k;

int op(int a,int b){
    return a+b;
}

int e(){
    return 0;
}

bool f(int x){
    cout << "f:" << x << endl;
    if(x < k) return true;
    else return false;
}

int main(){
    int q;
    cin >> q;
    int n = 128;
    segtree<int,op,e> seg(n);
    rep(qi,q){
        int t;
        cin >> t >> k;
        if(t == 1){
            seg.set(k,seg.get(k)+1);
        } else {
            int y = seg.max_right<f>(0);
            cout << y << endl;
            seg.set(y,seg.get(y)-1);
        }
    }
}
