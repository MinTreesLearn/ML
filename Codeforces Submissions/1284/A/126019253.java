import java.util.Scanner;
     
public class cf1284A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); //num String n
        int m = sc.nextInt(); //num String m
        String[] s = new String[n];
        String[] t = new String[m];

        for(int i=0; i<n; i++) {
            s[i] = sc.next();
        }
        for(int i=0; i<m; i++) {
            t[i] = sc.next();
        }

        int q = sc.nextInt(); //numQueries

        while(q-- > 0) {
            int year = sc.nextInt();
            System.out.println(s[(year-1) % n] + t[(year-1) % m]);
        }
        sc.close();
    }
}