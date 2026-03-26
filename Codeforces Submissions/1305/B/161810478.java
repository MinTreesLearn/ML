import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class SimpleStrings {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        solve(br);
    }

    public static void solve(BufferedReader br) throws IOException{
        String s=br.readLine();
        int n=s.length();
        int[] countRight=new int[n];
        countRight[n-1]=(s.charAt(n-1)==')'?1:0);
        for(int i=n-2;i>=0;i--){
            countRight[i]=countRight[i+1]+(s.charAt(i)==')'?1:0);
        }
        int maxLeft=0;
        int countLeft=0;
        for(int i=0;i<n;i++){
            char c=s.charAt(i);
            if(c=='('){
                countLeft++;
                if(i+1<n&&countRight[i+1]>=countLeft){
                    maxLeft=Math.max(maxLeft,countLeft);
                }
                else{
                    break;
                }
            }
        }
        if(maxLeft==0){
            System.out.println(0);
            return;
        }
        List<Integer> res=new ArrayList<>();
        int count0=maxLeft;
        int count1=maxLeft;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('&&count0>0){
                count0--;
                res.add(i+1);
            }
            if(count0==0){
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s.charAt(i)==')'&&count1>0){
                count1--;
                res.add(i+1);
            }
            if(count1==0){
                break;
            }
        }
        Collections.sort(res);
        System.out.println(1);
        System.out.println(res.size());
        for(int num:res){
            System.out.print(num);
            System.out.print(' ');
        }
    }


}
