#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int num = stoi(s.substr(3));
  if (0 < num and num < 350 and num != 316)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
