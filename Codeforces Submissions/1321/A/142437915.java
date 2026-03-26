import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] r=new int[n];
		for(int i=0;i<n;i++)
		r[i]=sc.nextInt();
		int[] b=new int[n];
		for(int i=0;i<n;i++)
		b[i]=sc.nextInt();
		int pa=0,pb=0,diff=0,lh=0;int flag=0;
		for(int i=0;i<n;i++)
		{
		    if(r[i]==1)
		    pa++;
		    if(b[i]==1)
		    pb++;
		    if(r[i]==1&&b[i]==0)
		    lh++;
		    if(r[i]!=b[i])
		    flag=1;
		}
		if(lh==0||pa==0||flag==0)
		{
		    System.out.println("-1");return;
		}
		if(pa>pb){System.out.println("1");return;}
		if(pa==pb){System.out.println("2");return;}
		diff=Math.abs(pa-pb);
		int c=((diff+1)/lh)+1;
		if((diff+1)%lh>0)
		System.out.println(c+1);
		else
		System.out.println(c);
		
	}
}
