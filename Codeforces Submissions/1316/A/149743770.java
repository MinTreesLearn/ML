import java.util.Scanner;
public class codeforces1316A
{ 
	public static void main(String[] args) 
	{ 
        Scanner s=new Scanner(System.in);
        StringBuilder sb=new StringBuilder();
        int t=s.nextInt(),i,n,m,sum;
        while(t-->0)
        {
            n=s.nextInt();
            m=s.nextInt();
            sum=0;
            int[] a = new int[n];
            for(i=0;i<n;i++)
            {
                a[i]=s.nextInt();
                sum=sum+a[i];
            }
            sb.append(Math.min(m,sum)+"\n");
        }
        System.out.print(sb);
    }
}