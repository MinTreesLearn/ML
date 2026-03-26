import java.util.Scanner;
 
public class IntTree {
    public static void main(String[] args) {
 
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while(t-->0){
            int n=s.nextInt();
            int x=s.nextInt();
            int y=s.nextInt();
            int min=Math.max(1,Math.min(n,x+y-n+1));
            int max=Math.min(n,x+y-1);
            System.out.println(min+" "+max);
        }
 
    }
}