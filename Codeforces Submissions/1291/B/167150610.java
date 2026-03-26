import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class ArraySharpening {

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
        int[] nums=new int[n];
        String[] temp=br.readLine().split(" ");
        for(int i=0;i<n;i++){
            nums[i]=Integer.parseInt(temp[i]);
        }
        boolean[] canIncreaseLeft=new boolean[n];
        canIncreaseLeft[0]=true;
        for(int i=1;i<n;i++){
            if(canIncreaseLeft[i-1]==false){
                canIncreaseLeft[i]=false;
                continue;
            }
            if(nums[i]>=i){
                canIncreaseLeft[i]=true;
            }
            else{
                canIncreaseLeft[i]=false;
            }
        }
        boolean[] canDecreaseRight=new boolean[n];
        canDecreaseRight[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(canDecreaseRight[i+1]==false){
                canDecreaseRight[i]=false;
                continue;
            }
            if(nums[i]>=n-1-i){
                canDecreaseRight[i]=true;
            }
            else{
                canDecreaseRight[i]=false;
            }
        }
        if(canDecreaseRight[0]||canIncreaseLeft[n-1]){
            pr.println("Yes");
            return;
        }
        for(int i=1;i<n-1;i++){
            if(canIncreaseLeft[i]&&canDecreaseRight[i]){
                pr.println("Yes");
                return;
            }
        }
        pr.println("No");
    }
}
