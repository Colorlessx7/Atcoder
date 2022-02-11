#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0; 
    //どこで区切るか,n=6だと0:6から6:0まで試す
    for(int i = 0; i <= n; i++){
        //区切った場所ごとのXとYのどちらにも含まれている文字の種類数
        int tmp = 0;
        //asciiでa-zが連番なのでforでchar型で回せる
        for(char c = 'a'; c <= 'z'; c++){
            //founds:Xにアルファベット(cに格納されたもの)が存在するか
            //foundt:Yにアルファベット(cに格納されたもの)が存在するか
            bool founds = false, foundt = false;
            //文字列X:文字列sの0文字目からi-1文字目まで
            for(int j = 0; j < i; j++){
                //cに格納されたアルファベットが文字列Xにあるならtrueに
                if(s[j] == c){
                    founds = true;
                }
            }
            //文字列Y:文字列sのi文字目からn-1文字目まで
            for(int j = i; j < n; j++){
                //cに格納されたアルファベットが文字列Yにあるならtrueに
                if(s[j] == c){
                    foundt = true;
                }
            }
            //区切って別れた文字列XとYにアルファベット1文字ごとに
            //そのアルファベットが存在するかの判定
            if(founds && foundt){
                tmp++;
            }
        }
        //最大をとる
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
