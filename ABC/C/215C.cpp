#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    string s;
    int k;
    cin >> s >> k;
    //辞書順なので事前にソートしておく
    sort(s.begin(),s.end());
    //next_permutationをk-1回回す
    //sortした時点のsが辞書の1回目でk-1回回せばその時点のsがk番目になる
    rep(i,k - 1){
        //順列生成するときの元の要素にダブりがあっても正常に作動する
        next_permutation(s.begin(),s.end());
    }
    cout << s << endl;
    return 0;
}
