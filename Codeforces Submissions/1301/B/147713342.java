import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Solve{
    static int[] arr;
    static int T,N;
    
    public static void main(String[] args){
        FastScan fs = new FastScan();
        
        int[] arr = new int[100001];
        //adjs = new ArrayList<Integer>();
        
        T = fs.nextInt();
        while( T > 0 ){
            //adjs.clear();
            N = fs.nextInt();
            
            arr[0] = fs.nextInt();
            int max_diff = 0, max_adj = Integer.MIN_VALUE, min_adj = Integer.MAX_VALUE;
            for(int i=1;i<N;++i){
                arr[i] = fs.nextInt();
                if( arr[i] > -1 && arr[i-1] > -1 ){
                    max_diff = Math.max( max_diff, Math.abs(arr[i]-arr[i-1]) );
                }
                else if( arr[i] == -1 && arr[i-1] > -1 ){
                    max_adj = Math.max( max_adj, arr[i-1] );
                    min_adj = Math.min( min_adj, arr[i-1] );
                }
                else if( arr[i] > -1 && arr[i-1] == -1 ){
                    max_adj = Math.max( max_adj, arr[i] );
                    min_adj = Math.min( min_adj, arr[i] );
                }
            }
            
            int k = (max_adj + min_adj)/2;
            int m = Math.max( max_diff, Math.max(max_adj-k, k-min_adj) );
            
            System.out.println(m+" "+k);
            
            --T;
        }
    }
}
        
class FastScan{
    BufferedReader br;
    StringTokenizer stok;
    
    public FastScan(){ br = new BufferedReader( new InputStreamReader(System.in) ); }
    
    String next(){
        while( stok == null || !stok.hasMoreElements() ){
            try{
                stok = new StringTokenizer( br.readLine() );
            }catch(IOException e){
                e.printStackTrace();
            }
        }
        return stok.nextToken();
    }
    
    String nextLine(){
        String str = "";
        try{
            str = br.readLine();
        }catch(IOException e){
            e.printStackTrace();
        }
        return str;
    }
    
    int nextInt(){ return Integer.parseInt( this.next() ); }
    long nextLong(){ return Long.parseLong( this.next() ); }
    double nextDouble(){ return Double.parseDouble( this.next() ); }
}