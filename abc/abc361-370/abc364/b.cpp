#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int h, w, si, sj;
  cin >> h >> w >> si >> sj;
  si--;
  sj--;
  vector<string> grid(h);
  for (int i = 0; i < h; i++)
    cin >> grid[i];
  string x;
  cin >> x;
  for (char d : x)
  {
    if (d == 'L' && -1 < sj - 1 && grid[si][sj - 1] == '.')
      sj--;
    if (d == 'R' && sj + 1 < w && grid[si][sj + 1] == '.')
      sj++;
    if (d == 'U' && -1 < si - 1 && grid[si - 1][sj] == '.')
      si--;
    if (d == 'D' && si + 1 < h && grid[si + 1][sj] == '.')
      si++;
  }
  cout << ++si << ' ' << ++sj << endl;
}
