import java.util.*;
public class YetAnotherTetrisProblem {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t--!=0){
            int n = in.nextInt();
            int[] a = new int[n];
            int even = 0;
            int odd = 0;
            for(int i=0;i<n;i++){
                a[i] = in.nextInt();
                if(a[i]%2==0)
                    even++;
                else
                    odd++;
            }
            if(even==0 || odd==0)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
