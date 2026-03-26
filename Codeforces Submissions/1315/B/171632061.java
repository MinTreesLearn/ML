import java.util.*;
public class B1315 {
    
    public static boolean check(String s, long a , long b,int idx,long p){

        long cost = 0;
        for(int i=idx;i<s.length()-1;i++){
            char ch = s.charAt(i);
            while(i<s.length() && s.charAt(i)==ch) i++;

            i--;
            cost +=(ch=='A' ? a : b);
        }

        return cost<=p;
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int t = scn.nextInt();

        while(t-->0){
            long a  =scn.nextInt();
            long b = scn.nextInt();
            long p  =scn.nextInt();

            String s = scn.next();

            int si = 0;
            int ei = s.length()-1;
            int res = s.length();
            while(si<=ei){

                int mid = (si+ei)/2;

                // char ch = s.charAt(mid);
                boolean flag = check(s, a, b, mid, p);
                if(flag){
                    ei = mid-1;
                    res = Math.min(res,mid);
                }else{
                   si = mid+1;
                }
            }

            System.out.println(res+1);
        }
    }
}
