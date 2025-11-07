#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ans = 0;
  string model = string(k, 'O');
  for (int i = 0; i < n - k + 1; ++i)
  {
    if (s.substr(i, k) == model)
    {
      ans++;
      for (int j = i; j < i + k; j++)
        s[j] = 'X';
    }
  }
  cout << ans << endl;
}
