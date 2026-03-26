import java.util.Scanner;
public class MAin
{
	public static void main(String[] args) 
	{ 
	    Scanner s = new Scanner(System.in);
        StringBuilder sb=new StringBuilder();
        int n,t=s.nextInt(),i;
        while(t-->0)
        {
            n=s.nextInt();
            if(n%2==0)
            {
                for(i=0;i<(n/2);i++)
                sb.append(1);
            }
            else
            {
                sb.append(7);
                for(i=0;i<(n-3)/2;i++)
                sb.append(1);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}