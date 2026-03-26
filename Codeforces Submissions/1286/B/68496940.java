import java.util.Scanner;
import java.util.HashSet;
import java.util.ArrayList;

public class Main {

  static int[] c;
  static HashSet<Integer>[] graph;
  static int[] res;
  static ArrayList<Integer> v;
  static int[] allSubNodes;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    c = new int[n + 1];
    int root = 0;

    v = new ArrayList<>();

    graph = new HashSet[n + 1];
    for (int i = 1; i <= n; ++i)
      graph[i] = new HashSet<Integer>();
    allSubNodes = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
      v.add(i);

      int pi = sc.nextInt();
      int ci = sc.nextInt();

      if (pi == 0)
        root = i;
      else
        graph[pi].add(i);
      c[i] = ci;
    }

    getAllSubNodes(root);

    for (int i = 1; i <= n; ++i) {
      if (allSubNodes[i] < c[i]) {
        System.out.println("NO");
        System.exit(0);
      }
    }

    System.out.println("YES");

    res = new int[n + 1];

    dfs(root);

    for (int i = 1; i <= n; ++i)
      System.out.print(res[i] + " ");
    System.out.println();
  }

  public static void getAllSubNodes(int node) {
    if (graph[node].size() == 0) {
      allSubNodes[node] = 0;
      return;
    }

    for (int subNode : graph[node]) {
      getAllSubNodes(subNode);
      allSubNodes[node] += allSubNodes[subNode] + 1;
    }
  }

  public static void dfs(int node) {
    res[node] = v.remove(c[node]);
    for (int subNode : graph[node])
      dfs(subNode);
  }
}