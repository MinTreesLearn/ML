import java.util.Scanner;

public class EvenButNotEven {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for ( int p = 0; p < t; p++){
            int n = in.nextInt();
            StringBuilder s = new StringBuilder(in.next());
            int count = 0;
            for ( int i = 0; i < n; i++){
                if (s.charAt(i) % 2 != 0){
                    count++;
                }
            }
            if ( count == 0 || count == 1){
                System.out.println("-1");
            }
            if(count % 2 == 0 && count!=0){
                while(s.charAt(s.length()-1) % 2 == 0){
                    s.replace(s.length()-1,s.length(),"");
                }
                System.out.println(s);
            }
            else if (count != 1 && count % 2 != 0){
                while(s.charAt(s.length()-1) % 2 == 0){
                    s.replace(s.length()-1,s.length(),"");
                }
                s.replace(s.length()-1,s.length(),"");
                while(s.charAt(s.length()-1) % 2 == 0){
                    s.replace(s.length()-1,s.length(),"");
                }
                if(s.length() == 0){
                    System.out.println("-1");
                }
                else{
                    System.out.println(s);
                }
            }
        }
    }
}