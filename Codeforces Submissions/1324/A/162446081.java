import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class YetAnotherTetrisProblem {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for ( int p = 0; p < t; p++){
            int n = in.nextInt();
            int count = 0;
            ArrayList <Integer> list = new ArrayList<>(1);
            for (int i = 0; i < n; i++){
                list.add(in.nextInt());
            }
           int min = Collections.min(list);
            for ( int i = 0; i < n; i++){
                list.set(i,list.get(i) - min);
                if(list.get(i) % 2 == 0){
                    count++;
                }
                else{
                    System.out.println("NO");
                    break;
                }
            }
            if ( count == n){
                System.out.println("YES");
            }
        }
    }
}