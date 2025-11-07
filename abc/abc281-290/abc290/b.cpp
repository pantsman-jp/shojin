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
  int n, k;
  string s;
  cin >> n >> k >> s;
  rep(i, 0, n)
  {
    if (s[i] == 'o' and k > 0)
    {
      cout << 'o';
      k--;
    }
    else
      cout << 'x';
  }
  cout << endl;
}