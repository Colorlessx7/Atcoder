#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
vector<int> compress(vector<int> a){
    int n = a.size();
    map<int,int> mp;
    //番号を考えずにmapの場所取りを行う
    rep(i,n){
        mp[a[i]] = 0;
    }
    //id:圧縮後の行(列)番号 
    int id = 1;
    //mapの登場する行(列)番号の小さい順に番号を1ずつ増加させながら付与
    //計算量削減の為参照型に
    //後置インクリメントで1,2,3,4というふうに代入
    for(auto& p : mp){
        p.second = id++;
    }
    //上書き部分
    rep(i,n){
        a[i] = mp[a[i]];
    }
    return a;
}
int main(){
    int h, w, n;
    cin >> h >> w >> n;
    //a,bは独立なので配列でとる
    vector<int> a(n),b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    //圧縮用関数に突っ込む
    a = compress(a);
    b = compress(b);
    rep(i,n){
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
//座標圧縮問題 
//実装方法は数字のある行番号、列番号をmapに格納して小さい順に番号を振っていく方法(わかりやすい)
//数字のある行番号、列番号をリストアップして小さい順にsortして
//lower_boundで何番目に小さいか判定する方法がある(0(logN))(早い)(ライブラリ化はこっち)


