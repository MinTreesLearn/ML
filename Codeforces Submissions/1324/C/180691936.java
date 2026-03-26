import java.util.*;

public class frogJumps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tt=0;tt<t;tt++) {
            String s = "R" + sc.next() + "R";
            int maxDist = 1;
            int currDist = 0;
            for (int i = 0 ; i < s.length() ; i++) {
                if (s.charAt(i) == 'R') {
                    maxDist = Math.max(maxDist, currDist);
                    currDist = 1;
                } else {
                    currDist++;
                }
                
            }
            System.out.println(maxDist);
        }
    }    
}
