//二分探索法
//単純な線形探索ではO(n)の時間がかかる
//二分探索を行えばO(logn)の時間で済む
//std::lower_bound() がやりたいことは、結局は
//a[配列]>=keyという条件を満たす最小のindexを見つけたい
//と言い表すことができる。


#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    //昇順に並べて二分探索法の前準備
    sort(a.begin(),a.end());
    rep(qi,q){
        int x;
        cin >> x;
        //lower_bound(二分探索法)はa配列の中のx以上の値のうち最も前にある場所のイテレータを返す
        //そのままだとイテレータのままなので先頭のイテレータと引き算すると
        //値が前から何番目かがわかる
        int i = lower_bound(a.begin(),a.end(),x) - a.begin();
        //n=5で3がx以上の最初のイテレータだった場合
        //x以上の人数は全体nからx以上の最初のイテレータiを引くと求まる
        int ans = n - i;
        cout << ans << endl;
    }
    return 0;
}
//二分探索法を実装する問題 O(QlogN)で解ける
