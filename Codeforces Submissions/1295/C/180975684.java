import java.util.*;
import java.io.*;

public class C1295 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int T = scn.nextInt();
        while (T-- > 0) {
            char[] s = scn.next().toCharArray();
            char[] t = scn.next().toCharArray();

            HashSet<Character> set = new HashSet<>();

            for (char c : s) {
                set.add(c);
            }

            boolean flag = true;
            for (char c : t) {
                if (!set.contains(c)) {

                    flag = false;
                    break;
                }
            }

            if (flag) {

                TreeSet<Integer>[] index = new TreeSet[26]; // stores the index of each character

                for (int i = 0; i < 26; i++) {

                    index[i] = new TreeSet<>();
                }

                for(int i=0;i<s.length;i++){
                    index[s[i]-'a'].add(i);
                }

                int ans = 1;
                int pos = -1;
                for(char c : t){
                    Integer i = index[c-'a'].ceiling(pos+1); // just higher

                    if(i!=null){
                        pos = i;
                    }else{
                        ans++;
                        pos = index[c-'a'].ceiling(0);
                    }
                }

                System.out.println(ans);

            } else {
                System.out.println("-1");
            }
        }
    }
}
