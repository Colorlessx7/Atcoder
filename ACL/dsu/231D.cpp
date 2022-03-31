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
    int n, m;
    cin >> n >> m;
    //dsu(ACL)
    dsu d(n);
    //次数格納用配列
    vector<int> deg(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        //サイクルがあるか判定
        //dsuのsameはグラフの頂点a,bがすでに同じグループかを判定
        //すでに同じグループならパスがサイクルになってしまうため
        //Noを出力し終了
        if(d.same(a,b)){
            cout << "No" << endl;
            return 0;
        }
        //同じグループではなかったのでa,bを辺で繋ぎ
        //同じグループにする
        d.merge(a,b);
        //辺が追加されたのでa,bそれぞれの次数を追加
        deg[a]++;
        deg[b]++;
    }
    //次数が3以上のものが存在するか判定
    rep(i,n){
        //次数が3以上のものが存在するならNoを出力して終了
        if(deg[i] > 2){
            cout << "No" << endl;
            return 0;
        }
    }
    //ここまで異常がないならYes
    cout << "Yes" << endl;
    return 0;
}
