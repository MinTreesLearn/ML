import java.util.*;
import java.io.*;

public class Animals{
    static int lim=80000;
    static int n,m,k,temp,max;
    static int[][] M = new int[55][lim];
    static int[][] DP = new int[55][40050];
    static Deque<tuple> mono = new LinkedList<>();
    public static void insert(tuple e){
        while(!mono.isEmpty()&& e.v>mono.peekLast().v){mono.removeLast();}
        mono.addLast(e);
    }
    public static void drop(int i){
        if(mono.peekFirst().i==i){mono.removeFirst();}
    }
    public static int sum(int l,int p,int q){
        return M[l][q]-M[l][p-1];
    }
    public static int lpun(int l, int x){
        return DP[l-1][x]-M[l][x+k-1];
    }
    public static int rpun(int l, int x){
        return DP[l-1][x]+M[l][x-1];
    }
    public static void main(String[] args) throws IOException{
        Reader in = new Reader();
        n = in.nextInt();m = in.nextInt();k = in.nextInt();
        
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <=m; j++) {
                M[i][j]=in.nextInt()+M[i][j-1];
            }
        }
        for (int i = 1; i <= m-k+1; i++) {
            DP[1][i]=sum(1,i,i+k-1)+sum(2,i,i+k-1);
        }
        tuple tem;
        for (int i = 2; i <= n; i++) {
            //left
            max=0;mono.clear();
            for (int j = 1; j <= m-k+1; j++) {
                if(j>k){drop(j-k);max = Math.max(max,DP[i-1][j-k]);}
                insert(new tuple(j, lpun(i,j)));
                tem = mono.peekFirst();
                DP[i][j] = Math.max(DP[i-1][tem.i]+sum(i,tem.i+k,j+k-1), max+sum(i,j,j+k-1));
            }
            //right
            max=0;mono.clear();
            for (int j = m-k+1; j >= 1; j--) {
                if(j+k<= m-k+1){drop(j+k);max = Math.max(max,DP[i-1][j+k]);}
                insert(new tuple(j, rpun(i,j)));
                tem = mono.peekFirst();
                DP[i][j] = Math.max(DP[i][j],Math.max(DP[i-1][tem.i]+sum(i,j,tem.i-1), max+sum(i,j,j+k-1)));
            }
            for(int j=1;j<=m+k-1;j++){DP[i][j]+=sum(i+1,j,j+k-1);} 
        }
        int ans=0;
        for (int i = 1; i <= m-k+1; i++) {
            ans = Math.max(DP[n][i],ans);
        }
        System.out.println(ans);


        
        in.close();
    }

    static class Reader { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        }
    }
}

class tuple{
    int i,v;
    public tuple(int a,int b){
        this.i=a;this.v=b;
    }
}
