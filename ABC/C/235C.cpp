#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, q;
    cin >> n >> q;
    //mapで配列を使うこともできる
    map<int,vector<int>> mp;
    rep(i,n){
        int a;
        cin >> a;
        //aが112312だとするとmapに
        //1:1,2,5 2:3,6 3:4と格納される
        mp[a].push_back(i+1);
    }
    rep(qi,q){
        int x, k;
        cin >> x >> k;
        //見るべき配列を参照の形で取り出す
        //参照にしないとコピーが起き、計算量が増える
        vector<int>& p = mp[x];
        //サイズがk未満ならk回目のxは存在しない
        if(p.size() < k){
            cout << -1 << endl;
        }else {
            //配列のk番目(0~k-1なのでk-1)を出力
            cout << p[k - 1] << endl;
        }
    }
    return 0;
}
