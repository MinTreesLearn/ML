import java.io.*;
import java.util.*;
 
public class battle_azathoth {
    public static void main(String[] args) throws IOException {
    	
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(in.readLine());
        
        int n = Integer.parseInt(st.nextToken()); int m = Integer.parseInt(st.nextToken()); int p = Integer.parseInt(st.nextToken());
        
        int[] ys = new int[(int)(1e6)+5];
        
        Arrays.fill(ys, Integer.MIN_VALUE);
        
        int max = 0;
        
        for(int i = 0; i<n; i++) {
            st = new StringTokenizer(in.readLine());
            int pos = Integer.parseInt(st.nextToken());
            ys[pos] = Math.max(ys[pos], -Integer.parseInt(st.nextToken()));
            max = Math.max(max, pos);
        }
        
        segtree tree = new segtree(ys, 0, ys.length-1);
        
        int[][] xs = new int[m][2];
        
        for(int i = 0; i<m; i++){
            st = new StringTokenizer(in.readLine());
            xs[i] = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        }
        
        Arrays.sort(xs, (int[] a, int[] b) -> a[0] - b[0]);
        
        int[][] coords = new int[p][3];
        
        for(int i = 0; i<p; i++){
            st = new StringTokenizer(in.readLine());
            coords[i][1] = Integer.parseInt(st.nextToken());
            coords[i][0] = Integer.parseInt(st.nextToken());
            coords[i][2] = Integer.parseInt(st.nextToken());
        }        
        
        Arrays.sort(coords, (int[] a, int[] b) -> a[0] - b[0]);
        
        int idx = 0;
        int ret = Integer.MIN_VALUE;
        
        for(int i = 0; i<m; i++){
            while(idx < p && coords[idx][0] < xs[i][0]){
                if(max > coords[idx][1]){
                    tree.update(coords[idx][1]+1, ys.length-1, coords[idx][2]);
                }
                idx++;
            }
            ret = Math.max(ret, tree.get(0, ys.length-1) - xs[i][1]);
        }
        
        System.out.println(ret);
    }
    
    static class segtree {
 
    	public int none = Integer.MIN_VALUE;
    	public int updnone = 0;
        
    	public int gL;
    	public int gR;
    	public int mid;
    	public segtree left;
    	public segtree right;
    	public int val;
    	public int lazy = updnone;
        
    	segtree(int[] nums, int l, int r) {
            gL = l;
            gR = r;
            mid = (l + r) / 2;
            if (l == r) {
                val = nums[l];
                return;
            }
            left = new segtree(nums, l, mid);
            right = new segtree(nums, mid + 1, r);
            val = comb(left.val, right.val);
        }
        
        public int get(int l, int r) {
            if (l > gR || r < gL) {
                return none;
            }
            push();
            if (gL == l && gR == r) {
                return val;
            }
            return comb(
                    left.get(l, Math.min(r, mid)),
                    right.get(Math.max(l, mid + 1), r)
            );
        }
        
        public int update(int l, int r, int v) {
            push();
            if (l > gR || r < gL) {
                return val;
            }
            
            if (gL == l && gR == r) {
                compose(this, v);
                push();
            } else {
                val = comb(
                        left.update(l, Math.min(r, mid), v),
                        right.update(Math.max(l, mid + 1), r, v)
                );
            }
            return val;
        }
        
        public int comb(int a, int b) {
            return Math.max(a, b);
        }
 
        public void push() {            
            if (gL != gR) {
                compose(left, lazy);
                compose(right, lazy);
            }
            val += lazy; 
            lazy = updnone;
        }
        
        public void compose(segtree t, long v) {
            t.lazy += v;
        }
        
        public String toString() {
            return gL + " " + gR + " " + val + " " + lazy;
        }
    }
}