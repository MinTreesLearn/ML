import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        for(int c=0;c<t;c++)
        {
            int n=in.nextInt();
            in.nextLine();
            String str=in.nextLine();
            int size=0;
            int result=0;
            boolean hasA=false;
            for(int i=0;i<n;i++)
            {
             if(str.charAt(i)=='A'&&!hasA)
             {
                 hasA=true;
             }
             else if(str.charAt(i)=='A')
             {
                 if(size>=result)
                     result=size;
                 size=0;
             }
             else if(hasA)
                 size++;
            }
            if(size>result)
                result=size;
            System.out.println(result);
        }
    }
}
