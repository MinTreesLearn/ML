import java.util.Scanner;
public class AlgoAssignment {


    
    public static void main(String[] args) {
        Scanner in= new Scanner(System.in);

        int t=in.nextInt();
        for(int i=0;i<t;i++){
            String st=in.next();
            st = "R" + st + "R";
            int prev=0;
            int max=0;
            for(int j=0;j<st.length();j++){
                if(st.charAt(j)=='R'){
                    max=Math.max(max, j-prev-1);
                    prev=j;
                }
            }
            System.out.println(max+1);
        }
        
    }
}
