import java.util.*;

public class CF1291_A{

     public static void main(String []args){
        Scanner cs = new Scanner(System.in);
        int t = cs.nextInt();
        int n;
        String str;
        String answer;
        boolean b;
        
        while(t-->0){
            b = true;
            answer = "";
            n = cs.nextInt();
            str = cs.next();
            
            for(int j =0; j < n; j++){
                if(Character.getNumericValue(str.charAt(j)) % 2 != 0){
                    answer += str.charAt(j);
                }
                if(answer.length() == 2){
                    System.out.println(answer);
                    b = false;
                    break;
                }
            }
            if(b){
                System.out.println(-1);
            }
        }
     }
}