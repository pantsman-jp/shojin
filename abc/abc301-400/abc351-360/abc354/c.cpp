#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

struct Card
{
  int a;
  int c;
  int index;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Card> cards(n);
  rep(i, 0, n)
  {
    int a, c;
    cin >> a >> c;
    cards[i] = {a, c, i};
  }
  sort(all(cards), [&](auto &x, auto &y)
       { return x.c < y.c; });
  vector<int> ans;
  int v = 0;
  rep(i, 0, n) if (cards[i].a > v) v = cards[i].a, ans.push_back(cards[i].index);
  sort(all(ans));
  cout << ans.size() << endl;
  rep(i, 0, ans.size()) cout << ans[i] + 1 << ' ';
  cout << endl;
}