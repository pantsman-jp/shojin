#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_bingo(vector<vector<bool>> card)
{
  rep(i, 0, 3) if (card[i][0] and card[i][1] and card[i][2]) return true;
  rep(j, 0, 3) if (card[0][j] and card[1][j] and card[2][j]) return true;
  if (card[0][0] and card[1][1] and card[2][2])
    return true;
  if (card[0][2] and card[1][1] and card[2][0])
    return true;
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<bool>> card(3, vector<bool>(3));
  rep(i, 0, 3) rep(j, 0, 3) cin >> a[i][j];
  int n;
  cin >> n;
  rep(_, 0, n)
  {
    int b;
    cin >> b;
    rep(i, 0, 3) rep(j, 0, 3) if (a[i][j] == b) card[i][j] = true;
    if (is_bingo(card))
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}