import java.util.*;
import java.io.*;

public class F {
  public static void main(String[] args) throws IOException {
    FastScanner fs = new FastScanner();
    PrintWriter out = new PrintWriter(System.out);
    int n, m, p; n = fs.nextInt(); m = fs.nextInt(); p = fs.nextInt();
    List<Pair> atk, def; atk = new ArrayList<>(); def = new ArrayList<>();
    for(int i = 0; i < n; i++){
      int a, b; a = fs.nextInt(); b = fs.nextInt();
      atk.add(new Pair(a, b));
    }
    for(int i = 0; i < m; i++){
      int a, b; a = fs.nextInt(); b = fs.nextInt();
      def.add(new Pair(a, b));
    }
    Collections.sort(def);
    int[] minForDefense = new int[def.size()];
    int mn = (int)1e9;
    for(int i = def.size() - 1; i >= 0; i--){
      mn = Math.min(mn, def.get(i).s);
      minForDefense[i] = mn;
    }
    long[] profit = new long[(int)(1e6 + 1)];
    int l = 0; int r = 1;
    while(r < profit.length){
      while(l < def.size() && def.get(l).f < r){
        l++;
      }
      if(l >= def.size()){
        profit[r] = (long)(-1e10);
      } else {
        profit[r] = (long)(-minForDefense[l]);
      }
      r++;
    }
    //out.println("---");
    List<Dragon> dragons = new ArrayList<>();
    for(int i = 0; i < p; i++){
      int a, b, c; a = fs.nextInt(); b = fs.nextInt(); c = fs.nextInt();
      dragons.add(new Dragon(a, b, c));
    }
    Collections.sort(dragons);
    SegmentTree st = new SegmentTree(0, profit.length - 1, profit);
    //do precomp
    long[] precomp = new long[dragons.size()];
    for(int i = 0; i < dragons.size(); i++){
      int pos = dragons.get(i).b;
      long amt = dragons.get(i).c;
      st.rangeUpdate(pos + 1, profit.length - 1, amt); //every purchase at this defense level and above gets amt benefit
      precomp[i] = st.maxRangeQuery(1, profit.length - 1);
      //out.println(i + " " + pos + " " + amt + " " + precomp[i]);
    }
    //out.println("---");
    int mnAtkCost = (int)1e9;
    for(int i = 0; i < atk.size(); i++){
      mnAtkCost = Math.min(mnAtkCost, atk.get(i).s);
    }
    long ans = -(mn + mnAtkCost);
    for(int i = 0; i < atk.size(); i++){
      //try this atk
      long cost = atk.get(i).s;
      int amt = atk.get(i).f;
      l = 0;
      r = dragons.size() - 1;
      int at = -1;
      while(l <= r){
        int mid = (l + r)/2;
        if(dragons.get(mid).a < amt){
          at = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      //out.println(i + " " + cost + " " + amt);
      if(at != -1){
        ans = Math.max(ans, precomp[at] - cost);
      }
    }
    out.println(ans);
    out.close();
  }
}
class Pair implements Comparable<Pair> {
  int f, s;
  Pair(int a, int b){
    this.f = a; this.s = b;
  }
  @Override
  public int compareTo(Pair o){
    if(o.f < this.f){
      return 1;
    } else if (o.f > this.f){
      return -1;
    } else {
      if(o.s < this.s){
        return 1;
      } else if (o.s > this.s){
        return -1;
      } else {
        return 0;
      }
    }
  }
}
class Dragon implements Comparable<Dragon> {
  int a, b, c;
  Dragon(int a, int b, int c){
    this.a = a;
    this.b = b;
    this.c = c;
  }
  @Override
  public int compareTo(Dragon o){
    if(o.a < this.a){
      return 1;
    } else if (o.a > this.a){
      return -1;
    } else {
      return 0;
    }
  }
}
class SegmentTree {
  private SegmentTree lTree, rTree;
  private int lIdx, rIdx;
  private long max, sum;
  private long lazy;

  public SegmentTree(int l, int r, long arr[]){
    lIdx = l;
    rIdx = r;
    lazy = 0;
    if(l == r){
      max = arr[l];
      sum = arr[l];
    } else {
      lTree = new SegmentTree(l, (r + l)/2, arr);
      rTree = new SegmentTree((r + l)/2 + 1, r, arr);
      max = Math.max(lTree.getMax(), rTree.getMax());
      sum = lTree.getSum() + rTree.getSum();
    }
  }

  public long getMax(){
    return max;
  }

  public long getSum(){
    return sum;
  }

  public long maxRangeQuery(int l, int r){
    if(lazy > 0){
      max += lazy;
      //System.out.println("UPDATED MY MAX TO " + max + " " + lazy + " " + lIdx + " " + rIdx);
      if(lTree != null){
        lTree.lazyPush(lazy);
      }
      if(rTree != null){
        rTree.lazyPush(lazy);
      }
      lazy = 0;
    }
    if(l > rIdx || r < lIdx){
      return Long.MIN_VALUE;
    }
    if(l <= lIdx && r >= rIdx){
      //System.out.println("CAPTURED RANGE " + lIdx + " " + rIdx + " " + min);
      return max;
    }
    return Math.max(lTree.maxRangeQuery(l, r), rTree.maxRangeQuery(l, r));
  }

  public long sumRangeQuery(int l, int r){
    if(lazy > 0){
      sum = (lazy * (rIdx - lIdx + 1));
      if(lTree != null){
        lTree.lazyPush(lazy);
      }
      if(rTree != null){
        rTree.lazyPush(lazy);
      }
      lazy = 0;
    }
    if(l > rIdx || r < lIdx){
      return 0;
    }
    if(l <= lIdx && r >= rIdx){
      return sum;
    }
    return lTree.sumRangeQuery(l, r) + rTree.sumRangeQuery(l, r);
  }

  public void lazyPush(long val){
    lazy += val;
  }

  public void rangeUpdate(int l, int r, long inc){
    if(lazy > 0){
      max += lazy;
      if(lTree != null){
        lTree.lazyPush(lazy);
      }
      if(rTree != null){
        rTree.lazyPush(lazy);
      }
      lazy = 0;
    }
    if(l > rIdx || r < lIdx){
      return;
    }
    if(l <= lIdx && r >= rIdx){
      //System.out.println("updated on " + lIdx + " " + rIdx);
      sum += inc * (rIdx - lIdx + 1);
      max += inc;
      if(lTree != null){
        lTree.lazyPush(inc);
      }
      if(rTree != null){
        rTree.lazyPush(inc);
      }
    } else {
      lTree.rangeUpdate(l, r, inc);
      rTree.rangeUpdate(l, r, inc);
      max = Math.max(lTree.getMax(), rTree.getMax());
      sum = lTree.getSum() + rTree.getSum();
    }
  }

  public void pointUpdate(int pos, long elem){
    if(lIdx != rIdx){
      if(pos <= (rIdx + lIdx)/2){
        lTree.pointUpdate(pos, elem);
      } else {
        rTree.pointUpdate(pos, elem);
      }
      max = Math.max(lTree.getMax(), rTree.getMax());
      sum = lTree.getSum() + rTree.getSum();
    } else {
      max = elem;
      sum = elem;
    }
  }

}

//FastScanner fetched from: https://gist.github.com/codekansas/998da051fba0005111d43b0d11246478
class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    
    public FastScanner() throws FileNotFoundException {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    
    int nextInt() {
        return Integer.parseInt(next());
    }
    
    long nextLong() {
        return Long.parseLong(next());
    }
}
