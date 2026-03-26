import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        int r = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            if(s.charAt(i) == 'R')
                r++;
            else
                l++;
        }
        System.out.println(r + l + 1);
    }
}
/*
* BAN
* */