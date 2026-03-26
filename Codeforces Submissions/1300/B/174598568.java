import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0){
		    t--;
		   int n=sc.nextInt();
		  int[] arr=new int[2*n];
		  for(int i=0;i<2*n;i++){
		      arr[i]=sc.nextInt();
		  }
		  Arrays.sort(arr);
		  
		   System.out.println(arr[n]-arr[n-1]);
		   
		}
   }
}
