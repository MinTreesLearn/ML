import java.util.Scanner;

public class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(), n;
        int a[] = new int[100];
        boolean c;
        while(t -- > 0){
            c = true;
            n = sc.nextInt();
            for(int i = 0; i < n; i ++) a[i] = sc.nextInt();
            if(n == 1) System.out.println("YES");
            else{
                if(a[0] % 2 == 0){
                    for(int i = 1; i < n; i ++){
                        if(a[i] % 2 != 0){
                            c = false;
                            break;
                        }
                    }
                }
                else{
                    for(int i = 1; i < n; i ++){
                        if(a[i] % 2 == 0){
                            c = false;
                            break;
                        }
                    }
                }
                System.out.println(c ? "YES" : "NO");
            }
        }
        sc.close();
    }
}