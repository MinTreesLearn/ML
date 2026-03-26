
import java.io.BufferedInputStream;
import java.util.*;
import java.util.concurrent.*;


public class Main {
    static Scanner in=new Scanner(System.in);
    static int maxn= (int) (2e5+5);
    static ArrayList<Integer>[] e =new ArrayList[maxn],ee=new ArrayList[maxn];
    static int[] path=new int[maxn];
    public static void main(String[] args) {
        int n=in.nextInt(),m=in.nextInt();
        for(int i=1;i<=n;i++){
            e[i]=new ArrayList<>();
            ee[i]=new ArrayList<>();
        }
        for(int i=0,u,v;i<m;i++){
            u=in.nextInt(); v=in.nextInt();
            e[v].add(u);
            ee[u].add(v);
        }
        int k =in.nextInt();
        for(int i=1;i<=k;i++) path[i]=in.nextInt();
        int q[]=new int[maxn],dis[]=new int[maxn],vis[]=new int[maxn];
        Arrays.fill(dis,100000000);
        int l=1,r=1;
        q[1]=path[k];
        dis[path[k]]=0;
        while(l<=r){
            int x=q[l];
            for(int i=0;i<e[x].size();i++){
                int y=e[x].get(i);
                if(1==vis[y]) continue;
                vis[y]=1;
                if(dis[y]>dis[x]+1){
                    dis[y]=dis[x]+1;
                    q[++r]=y;
                }
            }
            l++;
        }
        int ans1=0,ans2=0;
        for(int i=1;i<k;i++){
            if(dis[path[i]]!=dis[path[i+1]]+1){
                ans1++;
                ans2++;
            }else{
                int x=path[i],y=path[i+1];
                for(int j=0;j<ee[x].size();j++){
                    int v=ee[x].get(j);
                    if(v!=y&&dis[v]==dis[x]-1){
                        ans2++;
                        break;
                    }
                }
            }
        }
        System.out.println(ans1+" "+ans2);
    }
}

