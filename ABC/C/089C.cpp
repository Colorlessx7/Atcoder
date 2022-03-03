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
    ll n;
    cin >> n;
    //M,A,R,C,Hが先頭の人がそれぞれ何人いるか
    vector<ll> m(5,0);
    //文字列の先頭判定とMARCHのカウント
    rep(i,n){
        string s;
        cin >> s;
        if(s[0]=='M'){
            m[0]++;
        }else if(s[0]=='A'){
            m[1]++;
        }else if(s[0]=='R'){
            m[2]++;
        }else if(s[0]=='C'){
            m[3]++;
        }else if(s[0]=='H'){
            m[4]++;
        }
    }
    ll ans = 0;
    //重複がないように全ての組み合わせの合計を求める
    //配列サイズ5の3重ループなので問題ない
    rep(i,5){
        for(int j = i + 1; j < 5; j++){
            for(int k = j + 1; k < 5; k++){
                ans += m[i] * m[j] * m[k];
            }
        }
    }
    cout << ans << endl;
   return 0;
}
//単純に実装する問題
//
