import java.util.*;
public class class398 {
public static void main(String arg[])
{
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int a=sc.nextInt();
	int b=sc.nextInt();
	int k=sc.nextInt();
	int i;
	int sum=a+b;
	PriorityQueue<Integer> pq=new PriorityQueue<>();
	for(i=0;i<n;i++)
	{
	int x=sc.nextInt();
	if(x%sum==0)
	{
	int c=(int)Math.ceil((double)sum/a);
	c--;
	pq.add(c);
	}
	else
	{
	int rem=x%sum;
	int c=(int)Math.ceil((double)rem/a);
	c--;
	pq.add(c);
	}
	}
	int ans=0;
	while(pq.size()>0)
	{
		int val=pq.poll();
		if(k-val>=0)
		{
			ans++;
			k-=val;
		}
		else
			break;
	}
	System.out.println(ans);
	
}
}
