import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			int n=sc.nextInt();
			boolean b=false;
			for(int i=0;i<n;i++){
				int tt=sc.nextInt();
				if(tt%2==0 && !b){
					System.out.println(1);
					System.out.println(i+1);
					b=true;
				}
			}
			if(!b){
				if(n==1)
					System.out.println(-1);
				else{
					System.out.println(2);
					System.out.println(1+" "+2);
				}
			}
		}
	}
}
	    	  	 	 					  		 	 			 	 	