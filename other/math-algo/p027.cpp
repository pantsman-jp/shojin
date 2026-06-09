#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int n, a[200009], c[200009];

void merge_sort(int l, int r)
{
  if (r - l == 1)
    return;
  int m = (l + r) / 2;
  merge_sort(l, m), merge_sort(m, r);
  int c1 = l, c2 = m, cnt = 0;
  while (c1 != m or c2 != r)
  {
    if (c1 == m)
      c[cnt] = a[c2], c2++;
    else if (c2 == r)
      c[cnt] = a[c1], c1++;
    else if (a[c1] <= a[c2])
      c[cnt] = a[c1], c1++;
    else
      c[cnt] = a[c2], c2++;
    cnt++;
  }
  rep(i, cnt) { a[l + i] = c[i]; }
}

int main()
{
  cin >> n;
  rep(i, n) cin >> a[i];
  merge_sort(0, n);
  rep(i, n) cout << a[i] << ' ';
  cout << endl;
}
