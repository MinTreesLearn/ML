import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class RestoringPermutation {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        int count=0;
        while(count<t){
            solve(br);
            count++;
        }
    }

    public static void solve(BufferedReader br) throws IOException{
        int n=Integer.parseInt(br.readLine());
        String[] temp=br.readLine().trim().split(" ");
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=Integer.parseInt(temp[i]);
        }
        int[] res=new int[n*2];
        Arrays.fill(res,-1);
        TreeSet<Integer> available=new TreeSet<>();
        for(int i=1;i<=n*2;i++){
            available.add(i);
        }
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(available.contains(num)==false){
                System.out.println(-1);
                return;
            }
            res[i*2]=num;
            available.remove(num);
        }
        for(int i=0;i<res.length;i+=2){
            int min=res[i];
            var bigger=available.ceiling(min);
            if(bigger==null){
                System.out.println(-1);
                return;
            }
            res[i+1]=bigger;
            available.remove(bigger);
        }
        output(res);
    }

    public static void output(int[] res){
        for(int i:res){
            System.out.print(i);
            System.out.print(' ');
        }
        System.out.print('\n');
    }
}
