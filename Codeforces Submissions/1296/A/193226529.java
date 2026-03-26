import java.util.Scanner;

public class ArrayWithOddSum {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        while(t-- > 0){
            int n = s.nextInt();
            int arr[] = new int[n];
            int count = 0;
            int sum = 0;
            for(int i = 0; i < n; i++){
                arr[i] = s.nextInt();
                sum += arr[i];
                if(arr[i] % 2 != 0){
                    count++;
                }
            }
            if(sum % 2 != 0){
                System.out.println("YES");
            }
            else{
                if(count != 0 && (n - count) != 0){
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
            }
        }
    }
}
