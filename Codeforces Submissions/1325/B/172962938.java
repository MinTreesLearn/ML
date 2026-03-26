import java.util.*;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testcases = sc.nextInt();
        while(testcases-->0){
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int i=0;i<n;++i){
                a[i] = sc.nextInt();
            }
            HashSet<Integer> b = new HashSet<>();
            for(int x:a){
                b.add(x);
            }
            System.out.println(b.size());
        }
    }



}