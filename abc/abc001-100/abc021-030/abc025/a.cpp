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
  int n;
  cin >> s >> n;
  vector<char> alph(all(s));
  sort(all(alph));
  int cnt = 1;
  rep(i, 0, 5) rep(j, 0, 5)
  {
    if (cnt == n)
    {
      cout << alph[i] << alph[j] << endl;
      return 0;
    }
    cnt++;
  }
}