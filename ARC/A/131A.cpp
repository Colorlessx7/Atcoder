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
    ll a, b;
    cin >> a >> b;
    ll ans = 500000000 * b + a;
    cout << ans << endl;
    return 0;
}
//考察問題 以下を満たすxを求める問題
//x を十進法で書いたときに、連続する部分文字列として A が現れる
//2x を十進法で書いたときに、連続する部分文字列として B が現れる
//これはx = 500000000 * b + aで求められる
//この時、X の下 8 桁が A となり、1 つ目の条件（A が現れる）を満たす。
//A≤99999999より、2Xの下9桁が2A、それより上の桁がBとなり、2つ目の条件（Bが現れる）を満たす。
