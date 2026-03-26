import java.util.Scanner;

public class Displaythenumber {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		for(int j=0;j<t;j++) {
		int n=s.nextInt();
        if(n%2==0) {
        	n/=2;
        	for(int i=0;i<n;i++){
        		System.out.print("1");
        	}
        	System.out.println();
        }
        else if(n%2!=0) {
        	n=n-3;
        	n/=2;
        	System.out.print("7");
        	for(int i=0;i<n;i++){
        		System.out.print("1");
        	}
        	System.out.println();
        	
        			
        }
	}
	}
}
