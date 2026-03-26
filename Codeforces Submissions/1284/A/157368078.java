import java.util.*;
public class Solution{
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int m=in.nextInt();
        in.nextLine();
        String s1=in.nextLine();
        String s2=in.nextLine();
        String[] str1=s1.split(" ");
        String[] str2=s2.split(" ");
        int q=in.nextInt();
        for(int c=0;c<q;c++)
        {
            int x=in.nextInt();
            x=x-1;
            int i= x%n;
            int j=x%m;
            System.out.println(str1[i]+str2[j]);
        }
    }
}