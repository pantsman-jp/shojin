#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> count(n);
  rep(i, n)
  {
    string s;
    cin >> s;
    int win = 0;
    for (char c : s)
      if (c == 'o')
        win++;
    count[i] = win;
  }
  vector<int> ans(n);
  rep(i, n) ans[i] = i;
  sort(ans.begin(), ans.end(), [&](int a, int b)
       {
         if (count[a] != count[b])
           return count[a] > count[b];
         return a < b; });
  rep(i, n) { cout << ans[i] + 1 << ' '; }
  cout << endl;
}
