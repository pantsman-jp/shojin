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
  string s;
  cin >> s;
  vector<bool> alph(26, false);
  rep(i, 0, 26) if (find(all(s), (char)(i + 'a')) != s.end()) alph[i] = true;
  rep(i, 0, 26)
  {
    if (!alph[i])
    {
      cout << (char)(i + 'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}