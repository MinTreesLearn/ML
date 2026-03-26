import java.util.*;

public class C1307 {
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String s = scn.next();

        long[] dp1 = new long[26]; // for 1 length
        long[][] dp2 = new long[26][26]; // for 2 length

        for(int i=0;i<s.length();i++){
            int asc = s.charAt(i)-'a';

            for(int j=0;j<26;j++){
                dp2[j][asc]+=dp1[j]; // no of times j+asc will occur
            }

            dp1[asc]++;
        }

        long max = 0;
        for(int i=0;i<26;i++){
            max = Math.max(max,dp1[i]);
            for(int j=0;j<26;j++){
                max = Math.max(max,dp2[i][j]);
            }
        }

        System.out.println(max);

    }
}