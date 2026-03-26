import java.util.*;
public class waytoolong {
		
		public static void main(String args[]) {
			Scanner s=new Scanner(System.in);
			int t=s.nextInt();
			for(int i=0;i<t;i++) {
				int c=0;
				String sa=s.next();
				for(int j=sa.indexOf('1');j<sa.lastIndexOf('1');j++) {
					if(sa.charAt(j)=='0') {
						c++;
					}
					
				}
				System.out.println(c);
					
}
}
}