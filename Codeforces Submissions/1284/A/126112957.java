import java.util.Scanner;

/**
 *
 * @author eslam
 */
public class NewYearAndNaming {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        String sn[] =new String[n];
        String sm[] =new String[m];
        for (int i = 0; i < sn.length; i++) {
            sn[i] = input.next();
        }
        for (int i = 0; i < sm.length; i++) {
            sm[i] = input.next();
        }
        int q = input.nextInt();
        for (int i = 0; i < q; i++) {
            int x = input.nextInt();
            String w = "";
            if(x%n==0){
                w = w+sn[n-1];
            }else{
                w = w +sn[(x%n)-1];
            }
            if(x%m==0){
                w = w+sm[m-1];
            }else{
                w = w +sm[(x%m)-1];
            }
            System.out.println(w);
        }
    }
    
}
