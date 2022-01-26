#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, i;
  cin >> N >> A;
  int y = A;
  string op;
  // ここにプログラムを追記
  for ( i = 0; i < N; i++)
  {
      cin >> op >> B;
      if (op == "+"){
          y = y + B;
          cout << i + 1 << ":" << y << endl;
      } else if (op == "-"){
          y = y - B;
          cout << i + 1 << ":" << y << endl;
      } else if (op == "*"){
          y = y * B;
          cout << i + 1 << ":" << y << endl;
      } else if (op == "/"){
          if (B == 0){
              cout << "error" << endl;
              break;
          }else {
              y = y / B;
              cout << i + 1 << ":" << y << endl;
          } 
      }     
  }
}
