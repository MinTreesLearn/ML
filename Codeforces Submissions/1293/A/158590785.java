import java.io.*;
import java.util.*;
import java.lang.*;

public class Codeforces{
   public static void main(String[] args)
    {
		Scanner input= new Scanner(System.in);
		int test=input.nextInt();
		while(test-->0)
		{
		 int n=input.nextInt(),s=input.nextInt(),k=input.nextInt();
		 List<Integer> a=new ArrayList<>();
			while(k--!=0)
			{ a.add(input.nextInt());
			}
			int d=0;
			for(int i=0;i<n;i++) {
				int x=s-i;
				int y=s+i;
				if(x>0 && !a.contains(x)) {
					d=i;
					break;
				}
				if(y<n+1 && !a.contains(y)) {
					d=i;
					break;
				}
			}
			System.out.println(d);
		}    
   } 
}

