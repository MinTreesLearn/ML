import java.util.*;
import java.io.*;


public class dp {
    static BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        st=new StringTokenizer(br.readLine());
        long[] a=new long[n+1];
        long[] ansl=new long[n+2];
        long[] ansr=new long[n+2];
        int[] l=new int[n+2];
        int[] r=new int[n+2];
        long ans=0; int p=0;
        for(int i=1;i<=n;i++)a[i]=Long.parseLong(st.nextToken());
        for(int i=1;i<=n;i++){
            int j=i-1;
            while((j>0)&&(a[j]>a[i])){
                j=l[j];
            }
            l[i]=j;
            ansl[i]=ansl[j]+(i-j)*a[i];
        }
        for(int i=n;i>=1;i--){
            int j=i+1;
            while((j<=n)&&(a[j]>a[i])){
                j=r[j];
            }
            r[i]=j;
            ansr[i]=ansr[j]+(j-i)*a[i];
            if(ansl[i]+ansr[i]-a[i]>ans){
                ans=ansl[i]+ansr[i]-a[i];
                p=i;
            }
        }
        for(int i=p-1;i>=1;i--){
            a[i]=Math.min(a[i],a[i+1]);
        }
        for(int i=p+1;i<=n;i++){
            a[i]=Math.min(a[i],a[i-1]);
        }
        for(int i=1;i<=n;i++){
            bw.write(String.valueOf(a[i]+" "));
        }

        bw.flush();
        bw.close();
    }
}
