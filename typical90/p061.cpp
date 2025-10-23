#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

vector<int> deck;

void solve()
{
  int t, x;
  cin >> t >> x;
  if (t == 1)
    deck.insert(deck.begin(), x);
  if (t == 2)
    deck.push_back(x);
  if (t == 3)
    cout << deck[x - 1] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  rep(qi, 0, q) solve();
}
