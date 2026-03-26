import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int x=0;x<t;x++){
		    int n=Integer.parseInt(br.readLine());
		    StringTokenizer st=new StringTokenizer(br.readLine());
		    int a[]=new int[n];
		    for(int i=0;i<n;i++){
		        a[i]=Integer.parseInt(st.nextToken());

		    }
		    st=new StringTokenizer(br.readLine());
		    int b[]=new int[n];
		    for(int i=0;i<n;i++){
		        b[i]=Integer.parseInt(st.nextToken());
		    }
		    Arrays.sort(a);
		    Arrays.sort(b);
		    for(int i=0;i<n;i++){
		        System.out.print(a[i]+" ");
		    }
		    System.out.println();
		    for(int i=0;i<n;i++){
		        System.out.print(b[i]+" ");
		    }
		    System.out.println();
		}
	}
}
