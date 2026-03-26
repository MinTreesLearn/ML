import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class Solution{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int kde = 0; kde < t; kde++){
            int n = sc.nextInt();
            int x = sc.nextInt();

            int[] nums = new int[n];

            for(int i = 0; i < n; i++){
                nums[i] = sc.nextInt();
            }
            Arrays.sort(nums);

            
            List<Integer> list = new ArrayList<>();
            for(int a : nums){
                list.add(a);
            }

            if(list.contains(x)){
                System.out.println(1);
                continue;

            }
             else if(x < nums[n-1]) 
            {
                System.out.println(2);
                continue;
            }
            
                int count = x / nums[n-1];

                if(x % nums[n-1] != 0) count ++;
                System.out.println(count);
            
        }

    }

}
