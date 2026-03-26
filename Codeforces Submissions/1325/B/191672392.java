
import java.util.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int n=scn.nextInt();

        for(int i=0;i<n;i++)
        {
            int len=scn.nextInt();

            int [] arr=new int[len];

            for(int j=0;j<len;j++)
            {
                arr[j]=scn.nextInt();
            }
            answer(len, arr);
        }



    }

    public static void answer(int n, int[] arr) {

        HashSet<Integer> set=new HashSet<>();

        for(int i=0;i<n;i++)
        {
            set.add(arr[i]);
        }

        System.out.println(set.size());


    }

}