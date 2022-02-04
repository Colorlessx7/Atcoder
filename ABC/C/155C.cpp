#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    map<string, int> mp;//mapというstl keyかstring valueがint
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
