import java.util.*;
 
public class Ap {
 
	public static void main(String[] args) {
 
		Scanner s = new Scanner(System.in);
 
		int n = s.nextInt();
		String str = s.next();
		
		int sum=0;
		int pos=0;
		int co=0;
		for(int i=0;i<n;i++) {
			if(str.charAt(i)=='(') {
				sum++;
			}
			else {
				sum--;
			}
			
			if(sum<0) {
				co++;
			}
			
			if(pos<0 && sum==0) {
				co++;
			}
			pos=sum;
		}
		if(sum!=0) System.out.println(-1);
		else {
			System.out.println(co);
			
		}
	}
 
}