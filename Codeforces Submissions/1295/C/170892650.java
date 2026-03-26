import java.util.*;
import java.util.stream.Collectors;
public class ObtainTheString {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		outer:
		while(t-->0) {
			String s=sc.next();
			Set<Character> foo= s.chars().mapToObj(e->(char)e).collect(Collectors.toSet());
			String ss=sc.next();
			if(s.equals(ss)) {
				System.out.println(1);
				continue outer;
			}
			for(int i=0;i<ss.length();i++) {
				if(!foo.contains(ss.charAt(i))) {
					System.out.println(-1);
					continue outer;
				}
			}
			int n=s.length();
			int arr[][]=new int[n][26];
			for(int i=n-1;i>0;i--) {
				arr[i-1][s.charAt(i)-'a']=i;
				for(int j=0;j<26;j++) {
					if(arr[i-1][j]==0) {
						arr[i-1][j]=arr[i][j];
					}
				}
			}
			if(n>1) {
				for(int j=1;j<26;j++) {
					if(arr[0][j]==0) {
						arr[0][j]=arr[1][j];
					}
				}
			}
			else {
				System.out.println(ss.length());
				continue outer;
			}
			int k=0,count=0,i=0;
			if(s.charAt(0)==ss.charAt(0)) {
				i++;
			}
			for(;i<ss.length();i++) {
				if(arr[k][ss.charAt(i)-'a']!=0) {
					k=arr[k][ss.charAt(i)-'a'];
				}
				else if(s.charAt(0)==ss.charAt(i)) {
					k=0;
					count++;
				}
				else {
//					System.out.println(ss.charAt(i));
					k=0;
					count++;
					i--;
				}
			}
//			System.out.println(Arrays.deepToString(arr));
			System.out.println(count+1);
		}
	}

}
