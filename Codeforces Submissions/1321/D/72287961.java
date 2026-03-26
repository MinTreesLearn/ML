import java.util.*;
public class D{
    static int lim=200050;
    static int n,m,a,b,k;
    static ArrayList<Integer>[] adj= new ArrayList[lim];
    static ArrayList<Integer>[] adjl= new ArrayList[lim];
    static int[] D= new int[lim],C=new int[lim];
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
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
}