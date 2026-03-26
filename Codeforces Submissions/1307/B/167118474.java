import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CowAndFriend {

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
        String[] temp=br.readLine().split(" ");
        int n=Integer.parseInt(temp[0]);
        int x=Integer.parseInt(temp[1]);
        temp=br.readLine().split(" ");
        int[] nums=new int[n];
        int max=0;
        for(int i=0;i<n;i++){
            nums[i]=Integer.parseInt(temp[i]);
            if(nums[i]==x){
                pr.println(1);
                return;
            }
            max=Math.max(nums[i],max);
        }
        if(max>x){
            pr.println(2);
            return;
        }
        int res=(x%max==0?x/max:x/max+1);
        pr.println(res);


    }
}
