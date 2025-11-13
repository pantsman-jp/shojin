#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string n;
  cin >> n;
  rep(i, 0, 3)
  {
    if (n[i] == '1')
      cout << '9';
    else if (n[i] == '9')
      cout << '1';
  }
  cout << endl;
}