#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ll q;
  cin >> q;
  vector<pair<int, int>> state;
  state.push_back({0, 0});
  rep(_, q)
  {
    int num;
    cin >> num;
    if (num == 1)
    {
      char c;
      cin >> c;
      auto [cnt, minc] = state.back();
      if (c == '(')
        cnt++;
      else
        cnt--;
      minc = min(minc, cnt);
      state.push_back({cnt, minc});
    }
    else
      state.pop_back();
    auto [cnt, minc] = state.back();
    if (cnt == 0 and minc >= 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
