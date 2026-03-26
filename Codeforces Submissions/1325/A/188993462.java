    import java.util.Scanner;
    import java.util.Spliterator;

    public class Book {
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            int n =scan.nextInt();
            while(n-->0){
                int b = scan.nextInt();
                if(b%2==0) System.out.println(b/2 + " " + b/2);
                else System.out.println(1 + " " + (b-1));
            }
        }
    }