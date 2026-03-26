import java.util.*;
public class FightwithMonsters {
	public static void main(String args[])
	{
		int i,j,t,n;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		long ap=sc.nextInt();
		long bp=sc.nextInt();
		long k=sc.nextInt();
		int a[]=new int[n];
		
		long z=ap+bp; 
		PriorityQueue<Long> fina=new PriorityQueue<>();
		int count=0;
		for(i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
			long mod=a[i]%z;
			if(mod==0)
			{
				fina.add(bp);
			}
			else if(mod<=ap)
			{
				count++;
			}
			else
			{
				fina.add(mod-ap);
			}
		}
		while(fina.size()>0)
		{
			
			long pq=fina.remove();
			pq=(int)Math.ceil((double)pq/ap);
			k=k-pq;
			if(k<0)
			{
				break;
			}
			count++;
		}
		System.out.println(count);

		
	}
}
