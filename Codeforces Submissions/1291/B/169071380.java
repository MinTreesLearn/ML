import java.util.Scanner;

public class ArraySharpening {
    private static String solve(int n, long[] arr){
        int leftIndex=-1,rightIndex=-1;
        for(int i=0;i<n;i++){
            if(arr[i]<i){
                leftIndex = i-1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]<n-i-1){
                rightIndex=i+1;
                break;
            }
        }
//        System.out.println(leftIndex +" "+rightIndex);
        if(leftIndex==-1 || rightIndex==-1 || (leftIndex>=rightIndex))
            return "Yes";
        return "No";
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t>0){
            int n = scanner.nextInt();
            long[] arr = new long[n];
            for(int i=0;i<n;i++){
                arr[i] = scanner.nextLong();
            }
            System.out.println(solve(n,arr));
            t--;
        }
    }
}