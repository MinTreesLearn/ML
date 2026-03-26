import java.util.*;
import java.io.*;

public class Main{
    
    static int n, m;
    static int[]t;
    static int[][] a;
    static int x, y;
    
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws Exception{
        in.nextToken();
        return (int)in.nval;
    }

    
    static boolean check(int v){
        Arrays.fill(t, 0);
        for(int i=1; i<=n; i++){
            int c = 0;
            for(int j=0; j<m; j++)
                c += a[i][j]>=v?1<<j:0;
            if(t[c]==0) t[c] = i;
        }
        
        for(int i=0; i<(1<<m); i++)
            if(t[i]>0)
                for(int j=i; j<(1<<m); j++)
                    if(t[j]>0&&(i|j)==(1<<m)-1){
                        x = t[i]; y  = t[j];
                        return true;
                    } 
                    
        return false;
    }
    
    public static void main(String[] args)throws Exception{
        n = nextInt(); m = nextInt();
        if(n==1){
            System.out.println(1+" "+1);
            return;
        }
        a = new int[n+1][m];
        t = new int[(1<<m)];
        for(int i=1; i<=n; i++)
            for(int j=0; j<m; j++)
                a[i][j] = nextInt();
        
        int l, r;
        l = 0; r = 1000000000;
        
        while(l<r){
            
            int mid = l + r + 1 >> 1;
            
            if(check(mid)) l = mid;
            
            else r = mid - 1;
            
        }
        check(l);
        System.out.println(x+" "+y);
    }
}