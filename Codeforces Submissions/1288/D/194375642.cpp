#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) { 
    for (int j = 0; j < m; ++j) { 
      scanf("%d", &a[i][j]);
    }
  }
  const int mxsub = 1 << m;
  auto exhaust = [&] (int trym) -> array<int, 2> { 
    vector<int> mask(n);
    vector<int> id(mxsub, -1);
    for (int i = 0; i < n; ++i) { 
      for (int j = 0; j < m; ++j) { 
        mask[i] |= trym <= a[i][j] ? (1 << j) : 0;
      }
      id[mask[i]] = i + 1;
    }
    for (int mask0 = 0; mask0 < mxsub; ++mask0) { 
      for (int mask1 = 0; mask1 < mxsub; ++mask1) { 
        if ((mask0 | mask1) == mxsub - 1) { 
          if (~id[mask0] and ~id[mask1]) { 
            return {id[mask0], id[mask1]};
          }
        }
      }
    }
    return {-1, -1};
  };
  int lans = -1, rans = -1;
  int lo = 0, hi = (int) 1e9;
  while (lo <= hi) { 
    int mid = lo + ((hi - lo) >> 1);
    auto y = exhaust(mid);
    if (y != array<int, 2> {-1, -1}) { 
      lans = y[0];
      rans = y[1];
      lo = mid + 1;
    } else { 
      hi = mid - 1;
    }
  }
  printf("%d %d\n", lans, rans);
  return 0;
}

/* To be honest, saw the tag for hint. 
 * Tag of "Binary Search" helped a lot coming out with the solution. 
 * Nonetheless, hoping for the AC. Hopefully this is a correct solution. */

	   		 			  		   				   	   	 	