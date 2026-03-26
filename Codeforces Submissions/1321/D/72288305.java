import java.io.*;
import java.util.*;
public class D{
    static int lim=200050;
    static int n,m,a,b,k;
    static ArrayList<Integer>[] adj= new ArrayList[lim];
    static ArrayList<Integer>[] adjl= new ArrayList[lim];
    static int[] D= new int[lim],C=new int[lim];
    
    public static void main(String[] args) throws IOException{
        Reader in = new Reader();
        n=in.nextInt();m=in.nextInt();
        for(int i=1;i<=n;i++){adj[i]=new ArrayList<>();adjl[i]=new ArrayList<>();}
        for (int i = 0; i < m; i++) {
            a=in.nextInt();b=in.nextInt();
            adj[b].add(a);
            adjl[a].add(b);
        }
        k=in.nextInt();
        for (int i = 1; i <=k; i++) {C[i]=in.nextInt();}
        ArrayList<Integer> frontier= new ArrayList<>();
        frontier.add(C[k]);int l=1;
        while(!frontier.isEmpty()){
            ArrayList<Integer> next = new ArrayList<>(100);
            for (Integer i : frontier) {
                for (Integer j : adj[i]) {
                    if(D[j]==0){D[j]=l;next.add(j);}
                }
            }
            frontier=next; l++;
        }
        D[C[k]]=0;int cnt=0;int maybe=0;
        a=C[1];
        for (int i = 2; i <= k; i++) {
            b=C[i];
            if(D[b]>=D[a]){cnt++;}
            else{
                for (Integer j : adjl[a]) {
                    if(j==b){continue;}
                    if(D[j]==D[b]){maybe++;break;}
                }
            }
            a=b;
        }
        System.out.println(cnt+" "+(cnt+maybe));

        in.close();
    }

    static class Reader{
        final private int S = (1<<16);
        private int bp,br;
        private byte[] buff;
        private DataInputStream din;
        public Reader(){
            din = new DataInputStream(System.in);
            bp=br=0;buff= new byte[S];
        }
        private void fill() throws IOException{
            br = din.read(buff,bp=0,S);
            if(br==-1)buff[0]=-1;
        }
        private byte read() throws IOException{
            if(bp==br)fill();
            return buff[bp++];
        }
        public int nextInt() throws IOException{
            int ret=0;
            byte c=read();
            while(c<=' ')c=read();
            boolean neg = (c=='-');
            if(neg)c=read();
            do{ret= ret*10+c-'0';}while((c=read())>='0'&&c<='9');
            if(neg) return -ret;
            return ret;
        }
        public void close() throws IOException {
            if(din==null)return;
            din.close();
        }
    }
}