//どんな「番地」にも書き込める、無限配列のようなデータ構造
/*　a[x]	マップの x という番地にアクセスする。
配列と同じように、代入・演算ができる。
x は整数型でなくても、文字列型でも vector 型でも何でもあり。
a.clear()	マップ a を初期化
最初は値がすべて 0（文字列の場合は空文字列）で初期化されている
Nを今までmap型変数にアクセスした数とするとき、マップのある特定の番地へのアクセスにかかる計算量は O(logN)程度
変数の定義　map<番地の型, 記録する型>*/

//ABC155Cから　

#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    map<string, int> mp;//mapというstl keyがstring valueがint
    rep(i,n){
        string s;
        cin >> s;
        //入力された文字列がmapに存在するならvalueを+1　
        /*C++ではmapに存在しないものを入力した場合自動的に文字列のkeyが作られ、
        0で初期化され、この場合インクリメントの処理がなされる*/
        mp[s]++;
    }
    int mx = 0;//頻度の最大値
    for(auto p : mp){//autoの型:pairのstringとint mapの型より
        mx = max(mx, p.second);//頻度の最大値がここでもとまる
    }
    for(auto p : mp){//上のforもだが範囲for文
        if(p.second != mx){
            continue;//頻度が最大でない文字列をスルー
        }
        cout << p.first << endl;//頻度が最大である文字列を出力
    }
    return 0;
}
