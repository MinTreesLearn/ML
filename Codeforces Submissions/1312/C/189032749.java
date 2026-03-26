import java.util.HashSet;
import java.util.Scanner;

public class AddingPowers {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        outerloop:
        for (int i = 0; i < t; i++) {
            int n=in.nextInt();
            int k=in.nextInt();
            HashSet<Long> hs=new HashSet<>();
            long ar[]=new long[n];
            for (int j = 0; j < n; j++) {
                ar[j]= in.nextLong();
            }
            for (int j = 0; j < n; j++) {
                long x=ar[j];
                long c=0;
                while (x>0){
                    if(x%k==0){
                        c++;
                        x=x/k;
                    }
                    else if(x%k==1){
                        x--;
                        if(hs.contains(c)){
                            System.out.println("NO");
                            continue outerloop;
                        }
                        else{
                            hs.add(c);
                        }
                    }
                    else{
                        System.out.println("NO");
                        continue outerloop;
                    }
                }

            }
            System.out.println("YES");
        }
    }
}
