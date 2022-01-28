#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string S, T;
    cin >> S >> T;
    rep(i,S.size()){
        if(S.at(i) != T.at(i)){
            if(S.at(i) == '@'){
                if(T.at(i)!='@'&&T.at(i)!='a'&&T.at(i)!='t'&&T.at(i)!='c'&&T.at(i)!='o'&&T.at(i)!='d'&&T.at(i)!='e'&&T.at(i)!='r'){
                    cout << "You will lose" << endl;
                    return 0;
                }
            }else if(T.at(i) == '@'){
                if(S.at(i)!='@'&&S.at(i)!='a'&&S.at(i)!='t'&&S.at(i)!='c'&&S.at(i)!='o'&&S.at(i)!='d'&&S.at(i)!='e'&&S.at(i)!='r'){
                    cout << "You will lose" << endl;
                    return 0;
                }
            }else {
                cout << "You will lose" << endl;
                return 0;
            }                
        }
    }
    cout << "You can win" << endl;
    return 0;
}
