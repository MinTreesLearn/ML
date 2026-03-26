import java.util.Arrays;
import java.util.Scanner;

public class Restaurant {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int cases = input.nextInt();
        while(cases-- > 0)
        {
            int arr[] = new int[3];
            arr[0] = input.nextInt();
		    arr[1] = input.nextInt();
		    arr[2] = input.nextInt();
		    Arrays.sort(arr);
		    int a = arr[0];
		    int b = arr[1];
		    int c = arr[2];
		    int count = 0;
		    if(a != 0){
		        count++;
		        a--;
		    }
		    if(b != 0){
		        count++;
		        b--;
		    }
		    if(c != 0){
		        count++;
		        c--;
		    }
		    if(c != 0 && b != 0){
		        count++;
		        c--;
		        b--;
		    }
		    if(c != 0 && a != 0){
		        count++;
		        c--;
		        a--;
		    }
		    if(b != 0 && a != 0){
		        count++;
		        a--;
		        b--;
		    }
         
            if(a > 0 && b > 0 && c > 0)
            {
                a--; b--; c--; count++;
            }
            System.out.println(count);
        }
        input.close();
    }
}
