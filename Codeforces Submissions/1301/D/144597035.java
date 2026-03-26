
import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		String ans = "";
		if(k>(4*n*m - 2*n - 2*m))
			System.out.println("NO");
		else if (m==1&n==1)
			System.out.println("NO");
		else {
			if (n == 1 && m > 1) {
				if(k<=m-1)
					System.out.println("YES\n1\n" + k + " R");
				else 
					System.out.println("YES\n2\n" + (m-1) + " R\n" + (k-m+1) + " L");
			}
			else if (m == 1 && n > 1) {
				if(k<=n-1)
					System.out.println("YES\n1\n" + k + " D");
				else 
					System.out.println("YES\n2\n" + (n-1) + " D\n" + (k-n+1) + " U");
			}
			else {
				int step = k/(1+4*(m-1))*3;
				if(k <= (n-1)*(1+4*(m-1))) {
					int j = k%(1+4*(m-1));
					if (j<=m-1 && j>0) {
						ans = j +" R";
						step++;
					}
					else if (j>0) {
						if((j-m+1)/3==0) {
							if((j-m+1)%3 == 1) {
								ans = (m-1) + " R\n1 D";
								step+=2;
							}
							else {
								ans = (m-1) + " R\n1 D\n1 U";
								step+=3;
							}
						}
						else {
							int i = (j-m+1)%3;
							if (i == 1) {
								ans = (m-1) + " R\n" + (j-m+1)/3 + " DUL\n1 D";
								step+=3;
							}
							else if(i==2){
								ans = (m-1) + " R\n" + (j-m+1)/3 + " DUL\n1 D\n1 U";
								step+=4;
							}
							else if (i==0) {
								ans = (m-1) + " R\n" + (j-m+1)/3 + " DUL";
								step += 2;
							}
						}
					}
					System.out.println("YES" + "\n" + step);
					for(int i = 0 ; i<k/(1+4*(m-1)) ; i++) {
						System.out.println((m-1) + " R\n" + (m-1) + " DUL\n1 D");
					}
					System.out.println(ans);
				}
				else {
					step = k/(1+4*(m-1))*3;
					k = k - (n-1)*(1+4*(m-1));
					if(k<=(m-1)) {
						System.out.println("YES" + "\n" + (step+1));
						for(int i = 0 ; i<(n-1) ; i++) {
							System.out.println((m-1) + " R\n" + (m-1) + " DUL\n1 D");
						}
						System.out.println(k +" R");
					}
					else if (k<=2*(m-1)) {
						System.out.println("YES" + "\n" + (step+2));
						for(int i = 0 ; i<(n-1) ; i++) {
							System.out.println((m-1) + " R\n" + (m-1) + " DUL\n1 D");
						}
						System.out.println((m-1) +" R\n" +(k-m+1)+" L");
					}
					else {
						System.out.println("YES" + "\n" + (step+3));
						for(int i = 0 ; i<(n-1) ; i++) {
							System.out.println((m-1) + " R\n" + (m-1) + " DUL\n1 D");
						}
						System.out.println((m-1) +" R\n" +(m-1)+" L\n" + (k-2*(m-1)) + " U");
					}
						
				}
			}
			
		}
		
	}
}

					  		 			  			 	  	  		 		