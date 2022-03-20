#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
bool solve(string s){
    //sが1桁の場合8ならtrue,それ以外ならfalse
    if(s.size() == 1){
        return s == "8";
    }
    //sが2桁の場合組み合わせはabとbaの2パターンのみなので
    //元の数字とswapした数字をそれぞれ8の倍数か判定
    if(s.size() == 2){
        //stoiでstringをintに
        if(stoi(s) % 8 == 0){
            return true;
        }
        swap(s[0],s[1]);
        if(stoi(s) % 8 == 0){
            return true;
        }
        return false;
    }
    //sの桁が3桁以上の場合の処理
    vector<int> cnt(10);
    for(char c : s){
        //sを構成している数字の分布をとる
        cnt[c - '0']++;
    }
    //0~999の8の倍数だけを試す
    for(ll i = 0; i < 1000; i += 8){
        int x = i;
        vector<int> nc(10);
        rep(j,3){
            //8の倍数の3桁作成に必要な数字3つの分布をとる
            //x%10で下一桁が取れて、x/=10で次の桁に移動できる
            nc[x%10]++;
            x /= 10;
        }
        bool ok = true;
        rep(j,10){
            //sを構成している数字だけで8の倍数iが作れるか判定
            //(数字が足りず作れないのでfalse)
            if(nc[j] > cnt[j]){
                ok = false;
            }
        }
        //8の倍数を作れる組み合わせが見つかったならtrueで返す
        if(ok){
            return true;
        }
    }
    //何も見つからなかったのでfalseを返す
    return false;
}
int main(){
    string s;
    cin >> s;
    if(solve(s))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
//10進数の整数はabcd=a*1000+b*100+c*10+dとして考えられる
//10=2*5,100=4*25,1000=8*125とすると
//その数字が2の倍数か考えるなら下1桁のみを
//その数字が4の倍数か考えるなら下2桁のみを
//その数字が8の倍数か考えるなら下3桁のみを見れば判定できる
//この方法は倍数かどうか判定したい数字の素因数が2,5の場合に使うことができる(3も可?)
//ただし与えられたsが2桁以下の場合はこの方法で判定できないので場合分けする必要がある
