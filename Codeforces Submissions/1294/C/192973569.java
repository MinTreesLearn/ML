import java.io.*;

public class Main {
    public static void productTriplet(int num) {
        int a, b;
        int c = 0;
        for (a = 2; a * a * a <= num; a++) {
            if(num % a == 0) {
                break;
            }
        }
        int rem = num / a;
        for (b = a + 1; b * b <= rem; b++) {
            if(rem % b == 0) {
                c = rem / b;
                if(b >= c) {
                    c = 0;
                }
                break;
            }
        }
        if(a * b * c == num) {
            out.println("YES");
            out.println(a + " " + b + " " + c);
        }
        else
            out.println("NO");
    }

    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        int q = Integer.parseInt(read.readLine());
        while(q-- > 0) {
            int num = Integer.parseInt(read.readLine());
            productTriplet(num);
        }
        out.close();
    }
}