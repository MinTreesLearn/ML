import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        var Robo = new byte[n];
        var Bionic = new byte [n];
        var index =  new byte[n];
        for (int i = 0;i < n;i++) Robo[i] = scan.nextByte();
        for (int i = 0;i < n;i++) Bionic[i] = scan.nextByte();
        int p = 1;

        while(true){
            Index(p, n , Robo, index);
            if(Arrays.toString(Robo).equals(Arrays.toString(Bionic)) || p == 200 ) {
                System.out.println(-1);
                return;
            }
            else if(Sum(p,n,Robo,index) <= Sum(p,n,Bionic,index)){
                p++;
                continue;
            }
            break;
        }
        System.out.println(p);
    }
    public static int Sum(int p,int n,byte[] arr,byte [] index){
        int sum = 0;
        for (int i = 0;i < n;i++) sum += (index[i] * arr[i]);
        return sum;
    }

    public static void Index(int p,int n , byte [] arr, byte [] index){
        for (int i = 0;i < n;i++){
            if (arr[i] == 0) index[i] = 1;
            else index[i] = (byte)p;
        }
    }
}