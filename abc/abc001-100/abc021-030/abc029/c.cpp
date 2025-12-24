#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

void solve(int n, string s)
{
  if (n == s.size())
  {
    cout << s << endl;
    return;
  }
  solve(n, s + "a");
  solve(n, s + "b");
  solve(n, s + "c");
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  solve(n, "");
}