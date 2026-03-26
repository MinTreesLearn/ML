import java.util.*;

public class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int countL=0;
        int countR=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='L'){
                countL++;
            }
            else{
                countR++;
            }
        }
        System.out.println(countL+countR+1);
    }

}