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
  int n;
  cin >> n;
  map<string, int> cnt;
  cnt["For"] = cnt["Against"] = 0;
  rep(i, 0, n)
  {
    string s;
    cin >> s;
    cnt[s]++;
  }
  if (cnt["For"] > cnt["Against"])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}