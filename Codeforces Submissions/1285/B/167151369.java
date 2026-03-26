import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class JustEatIt {


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr=new PrintWriter(System.out);
        int t=Integer.parseInt(br.readLine());
        while(t!=0){
            solve(br,pr);
            t--;
        }
        pr.flush();
        pr.close();
    }

    public static void solve(BufferedReader br,PrintWriter pr) throws IOException{
        int n=Integer.parseInt(br.readLine());
        long[] preSum=new long[n+1];
        String[] temp=br.readLine().split(" ");
        for(int i=0;i<n;i++){
            int num=Integer.parseInt(temp[i]);
            preSum[i+1]=preSum[i]+num;
        }
        long yasser=preSum[n];
        long minLeft=0;
        long maxAdel=0;
        for(int i=1;i<n;i++){
            maxAdel=Math.max(maxAdel,preSum[i]-minLeft);
            minLeft=Math.min(minLeft,preSum[i]);
        }
        for(int i=n-1;i>=1;i--){
            maxAdel=Math.max(maxAdel,preSum[n]-preSum[i]);
        }
        pr.println(yasser>maxAdel?"YES":"NO");
    }
}
