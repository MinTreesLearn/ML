
import java.util.*;
import java.util.Scanner;

public class CollectingCoins {
    static java.util.Scanner reader=new Scanner(System.in);

    public static void main(String[] args) {
        int t=reader.nextInt();
        for (int i=0;i<t;i++){
            List<Integer> list=new ArrayList<>();
            int a=reader.nextInt();
            int b=reader.nextInt();
            int c=reader.nextInt();
            int n=reader.nextInt();
            list.add(a);
            list.add(b);
            list.add(c);
            Collections.sort(list);
            int max=Collections.max(list);
            int rem=0;
            int coins=0;
            for (int x=0;x<list.size()-1;x++){
                rem+=max-list.get(x);

            }
            if (rem>n){
                System.out.println("NO");
            }
            else {
                if ((n-rem)%3==0){
                    System.out.println("YES");
                }
                else {
                    System.out.println("NO");
                }

            }


        }

    }
}
