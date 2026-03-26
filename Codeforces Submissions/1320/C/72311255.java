import java.util.*;
import java.io.*;

public class Y{
    final static int M=(1<<20);
    static long[] t1=new long[M*2+5]; 
    static long[] t2=new long[M*2+5]; 
    static long[] ca=new long[M], cb=new long[M];
    static long ans;
    static int n,m,p,x,y,i,j;
    
    public static void upd(int i){
        t1[i]=t1[i<<1]+t1[i<<1|1];
        t2[i]=Math.max(t2[i<<1],t1[i<<1]+t2[i<<1|1]);
    }
    public static void add(int i,int v){
        for(t1[i+=M]+=v;(i>>=1)>0;upd(i));
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long Z= 1; Z<<=60;
        for(i=0;i<M;++i)ca[i]=cb[i]=Z;ans=-Z;
        n=in.nextInt();m=in.nextInt();p=in.nextInt();
        mons[] a = new mons[p+1];a[0]=new mons(0, 0, 0);
        for(i=1;i<=n;++i){x=in.nextInt();y=in.nextInt();ca[x]=Math.min(ca[x],y);}
        for(i=1;i<=m;++i){x=in.nextInt();y=in.nextInt();cb[x]=Math.min(cb[x],y);}
        
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