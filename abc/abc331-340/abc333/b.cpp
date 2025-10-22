#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  char s1, s2, t1, t2;
  cin >> s1 >> s2 >> t1 >> t2;
  map<char, int> dist;
  rep(i, 5) { dist["ABCDE"[i]] = i; }
  int s = abs(dist[s1] - dist[s2]), t = abs(dist[t1] - dist[t2]);
  if (min(s, 5 - s) == min(t, 5 - t))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
