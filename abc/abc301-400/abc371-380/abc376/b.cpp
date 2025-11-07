#include <iostream>
using namespace std;

int move_count(int n, int from, int to, int other)
{
  if (from > to)
    swap(from, to);
  if (from < other && other < to)
    return n - (to - from);
  else
    return to - from;
}

int main()
{
  int n, q;
  cin >> n >> q;
  int ans = 0, l = 1, r = 2;
  for (int i = 0; i < q; i++)
  {
    char h;
    int t;
    cin >> h >> t;
    if (h == 'R')
    {
      ans += move_count(n, r, t, l);
      r = t;
    }
    if (h == 'L')
    {
      ans += move_count(n, l, t, r);
      l = t;
    }
  }
  cout << ans << endl;
}
