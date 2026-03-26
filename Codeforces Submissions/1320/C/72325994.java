import java.util.*;
import java.io.*;

public class Y{
    final static int M=(1<<20);
    static long[] t1=new long[M*2+5]; 
    static long[] t2=new long[M*2+5]; 
    static long[] ca=new long[M], cb=new long[M];
    static long ans;
    static int n,m,p,x,i,j;
    static long y;
    
    public static void upd(int i){
        t1[i]=t1[i<<1]+t1[i<<1|1];
        t2[i]=Math.max(t2[i<<1],t1[i<<1]+t2[i<<1|1]);
    }
    public static void add(int i,int v){
        for(t1[i+=M]+=v;(i>>=1)>0;upd(i));
    }
    public static void main(String[] args) throws IOException{
        Reader in = new Reader();
        long Z= 1; Z<<=60;
        for(i=0;i<M;++i)ca[i]=cb[i]=Z;ans=-Z;
        n=in.nextInt();m=in.nextInt();p=in.nextInt();
        mons[] a = new mons[p+1];a[0]=new mons(0, 0, 0);
        for(i=1;i<=n;++i){x=in.nextInt();y=in.nextLong();ca[x]=Math.min(ca[x],y);}
        for(i=1;i<=m;++i){x=in.nextInt();y=in.nextLong();cb[x]=Math.min(cb[x],y);}
        
        for(i=0;i<M;++i)t2[i+M]=-cb[i];for(i=M-1;i!=0;--i)upd(i);
        for(i=1;i<=p;++i){a[i]= new mons(in.nextInt(),in.nextInt(),in.nextInt());}
        Arrays.sort(a);
        
        for(i=0,j=1;i<M;++i){
            for(;j<=p && a[j].x<i;++j)add(a[j].y,a[j].z);
            ans=Math.max(ans,t2[1]-ca[i]);
        }
        
        System.out.println(ans);

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
        public long nextLong() throws IOException{
            long ret=0;
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
class mons implements Comparable<mons>{
    int x,y,z;
    public mons(int x,int y, int z){
        this.x=x;this.y=y;this.z=z;
    }
    @Override
    public int compareTo(mons o) {
        if(x>o.x){return 1;}
        if(x<o.x){return -1;}
        return 0;
    }
}