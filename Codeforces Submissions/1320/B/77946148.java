import java.io.IOException;
import java.io.InputStream;
import java.util.*;
public class sol {
    static long mod=(long)Math.pow(10,9)+7;
    static StringBuilder sb = new StringBuilder();
    static ArrayList<Integer> adj[];
    static boolean vis[];
    static int a[], dist[];
    static void bfs(int s) {
        Queue<Integer> q = new LinkedList<>();
        dist[s]=0;
        vis[s]=true;
        q.add(s);
        while(q.size()>0) {
            int v=q.poll();
            for(Integer i : adj[v]) { 
                dist[i]=Math.min(dist[i],dist[v]+1);
                if(!vis[i]) {
                    vis[i]=true;
                    q.add(i);
                }
            }
        }
    }
    public static void main(String args[])throws Exception {
        FastReader in = new FastReader(System.in); 
        int t=1,i,j;
        start:while(t-->0) { 
            int n = in.nextInt(),m=in.nextInt();
            dist =new int[n];
            Arrays.fill(dist,Integer.MAX_VALUE);
            adj = new ArrayList[n];
            vis = new boolean[n];
            for(i=0;i<n;i++)
                adj[i]=new ArrayList<>();
            int x[]=new int[m];
            int y[]=new int[m];
            int cnt[]=new int[n];
            for(i=0;i<m;i++) {
                x[i]=in.nextInt()-1;
                y[i]=in.nextInt()-1;
                adj[y[i]].add(x[i]);
            }
            int k=in.nextInt();
            a = new int[k];
            for(i=0;i<k;i++)
                a[i]=in.nextInt()-1;
            bfs(a[k-1]);
            for(i=0;i<m;i++) {
                if(dist[y[i]]+1==dist[x[i]])
                    cnt[x[i]]++;
            }
            //for(i=0;i<n;i++)
                //System.out.println(dist[i]+" "+cnt[i]);
            int min=0,max=0;
            for(i=0;i<k-1;i++) {
                if(dist[a[i+1]]+1>dist[a[i]]) {
                    min++;
                    max++;
                }
                else if(cnt[a[i]]>1)
                    max++;
            }
            System.out.println(min+" "+max);
        }
        //System.out.print(sb);
    }
    static long power(long a, long b) {
        if(b == 0)
            return 1L;
        long val = power(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else 
            return val * val % mod * a % mod;
    }
    static void prt(int a[]) {
        for(int i=0;i<=a.length;i++)
            System.out.print(a[i]+" ");
        System.out.println();
    }
    static void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1; 
        int n2 = r - m; 
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
        int i = 0, j = 0; 
        int k = l; 
        while (i < n1 && j < n2) { 
            if (L[i] <= R[j]) { 
                arr[k] = L[i]; 
                i++; 
            } 
            else { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < n1) { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
        while (j < n2) { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    }  
    static void sort(int arr[], int l, int r) { 
        if (l < r) {
            int m = (l+r)/2; 
            sort(arr, l, m); 
            sort(arr , m+1, r); 
            merge(arr, l, m, r); 
        } 
    } 
    static int gcd(int a, int b) { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  
    }
    static class Pair { 
        int a; 
        int b;  
        Pair(int x, int y) { 
            a = x; 
            b = y; 
        } 
    }
}
class FastReader {
    byte[] buf = new byte[2048];
    int index, total;
    InputStream in;
    FastReader(InputStream is) {
        in = is;
    }
    int scan() throws IOException {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0) {
                return -1;
            }
        }
        return buf[index++];
    }
    String next() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan()) {
            sb.append((char) c);
        }
        return sb.toString();
    }
    String nextLine() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c != 10 && c != 13; c = scan()) {
            sb.append((char) c);
        }
        return sb.toString();
    }
    char nextChar() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        return (char) c;
    }
    int nextInt() throws IOException {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }
    long nextLong() throws IOException {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }
}