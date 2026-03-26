import java.util.*;
public class waytoolong {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		for(int i=0;i<t;i++) {
			String a=s.next();
			String b=s.next();
			String c=s.next();
			int f=0;
			for(int j=0;j<a.length();j++) {
				if(c.charAt(j)!=b.charAt(j)&&c.charAt(j)!=a.charAt(j)) {
					f=1;
					break;
				}
				
			}
			if(f==1) {
				System.out.println("no");
			}
			else {
				System.out.println("yes");
			}
		}
	}
}