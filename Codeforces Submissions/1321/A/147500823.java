import java.util.*;
import static java.lang.Math.*;
import static java.lang.Character.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int i, n = in.nextInt(),arr1[]=new int[n],arr2[]=new int[n],x=0,y=0;
        for( i =0;i<n;i++){
            arr1[i]=in.nextInt();
        }
        for( i =0;i<n;i++){
            arr2[i]=in.nextInt();
        }
        for(i=0;i<n;i++)
        {
            if(arr1[i]==1 && arr2[i]==0)
                x++;
            else if(arr1[i]==0 && arr2[i]==1)
                y++;
        }
        if(x==0)
            System.out.println(-1);
        else
            System.out.println((int) ceil((y+1.0)/x));
    }
}