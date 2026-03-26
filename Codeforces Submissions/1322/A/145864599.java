import java.util.*;
public class UnusualCompetitions {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String s=sc.next();
		char crr[]=s.toCharArray();
		int o=0,c=0,pos=-1,ans=0;
		for(int i=0;i<n;i++) {
			if(crr[i]=='(') {
				o++;
			}
			else {
				c++;
			}
		}
		if(o!=c) {
			System.out.println(-1);
			return;
		}
		o=0;
		c=0;
		for(int i=0;i<n;i++) {
//			System.out.println(o+" "+c);
			if(crr[i]=='(' && c>0) {
				for(int j=i;j<n;j++) {
//					System.out.println(o+" "+c);
					if(crr[j]=='(') {
						o++;
					}
					else {
						c++;
					}
//					System.out.println(o+" "+c);
					if(o==c) {
//						System.out.println(o+" "+c);
//						System.out.println(pos+" "+j);
						ans+=(j-pos)+1;
						i=j;
						pos=-1;
						c=0;
						o=0;
						break;
					}
				}
			}
			else if(crr[i]=='(') {
				o++;
			}
			else if(crr[i]==')' && o>0){
				o--;
			}
			else {
				c++;
				if(pos==-1) {
					pos=i;
				}
			}
		}
		System.out.println(ans);
	}

}
