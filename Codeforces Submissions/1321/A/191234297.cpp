#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &vec[i].first);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &vec[i].second);
  }

  int score_a = 0, score_b = 0;
  for (const auto &[a, b] : vec) {
    score_a += a && !b;
    score_b += !a && b;
  }

  if (score_a == 0) {
    printf("-1\n");
    exit(0);
  }
  printf("%d\n", score_b / score_a + 1);
}
