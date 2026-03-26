import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int z = 0; z < t; z++){
            String s = in.next();
            int ans = 0;
            boolean start = false;
            int length = 0;
            for(int i = 0; i < s.length(); i++){
                char curr = s.charAt(i);
                if(start){
                    if(curr == '0') length++;
                    else{
                        ans += length;
                        length = 0;
                    }
                }
                if(curr == '1') start = true;
            }
            System.out.println(ans);
        }
    }
}
/*
* BAN
* */