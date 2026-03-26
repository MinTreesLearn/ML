import java.io.*;
import java.util.*;
import java.lang.*;
public class Codeforces{
   public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		 int test=input.nextInt();
		 while(test-->0)
		 {
		  int n=input.nextInt();
		  int m=input.nextInt();
		  int[] ar=new int[n];
		  int[] br=new int[m];
		  for(int i=0;i<n;i++)
		  {
		   ar[i]=input.nextInt();
		  }
		  for(int i=0;i<m;i++)
		  {
		   br[i]=input.nextInt();
		  }
		  Arrays.sort(br);
		  int val=br[0];
		  int start=br[0];
		  int end=br[0];
		  for(int i=1;i<m;i++)
		  {
		   if(val+1==br[i])
		   {
		     end=br[i];
		     val=br[i];
		   }
		   else
		   {
		   Arrays.sort(ar,start-1,end+1);
		   start=br[i];
		   end=br[i];
		   val=br[i];
		   }
		  }
		  Arrays.sort(ar,start-1,end+1);
		  System.out.println(isSorted(ar,n)?"YES":"NO"); 
		 }
    }
    public static boolean isSorted(int arr[], int n)
    {
        if (n == 0 || n == 1)
            return true;
        for (int i = 1; i < n; i++)
            if (arr[i - 1] > arr[i])
                return false;
        return true;
    }
}
