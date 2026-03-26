import java.util.*;
import java.lang.*;

public class X
{
	public static void main(String[] args)
	{
		X ob=new X();
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int K=sc.nextInt();
		int[] KK=new int[K];
		for(int i=0;i<K;i++)
		{
			KK[i]=sc.nextInt();
		}
		ArrayList<ArrayList<Integer>> LL=new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<=N;i++)
		{
			LL.add(new ArrayList<Integer>());
		}
		int U;
		int V;
		for(int i=0;i<M;i++)
		{
			U=sc.nextInt();
			V=sc.nextInt();
			LL.get(U).add(V);
			LL.get(V).add(U);
		}
		System.out.println(ob.solve(N,KK,LL));
		
	}
	int solve(int N,int[] K,ArrayList<ArrayList<Integer>> LL)
	{
		
		int[] SS=new int[N+1];
		int[] DD=new int[N+1];
		HashSet<Integer> hs=new HashSet<Integer>();
		Queue<Integer> q=new LinkedList<>();
		hs.add(1);
		q.add(1);
		SS[1]=0;
		int curr=0;
		while(0<q.size())
		{
			curr=q.poll();
			for(int i=0;i<LL.get(curr).size();i++)
			{
				if(!hs.contains(LL.get(curr).get(i)))
				{
					hs.add(LL.get(curr).get(i));
					q.add(LL.get(curr).get(i));
					SS[LL.get(curr).get(i)]=SS[curr]+1;
				}
			}
		}
		hs.clear();
		hs.add(N);
		q.add(N);
		DD[N]=0;
		while(0<q.size())
		{
			curr=q.poll();
			for(int i=0;i<LL.get(curr).size();i++)
			{
				if(!hs.contains(LL.get(curr).get(i)))
				{
					hs.add(LL.get(curr).get(i));
					q.add(LL.get(curr).get(i));
					DD[LL.get(curr).get(i)]=DD[curr]+1;
				}
			}
		}
		hs.clear();
		for(int i=0;i<K.length;i++)
		{
			hs.add(K[i]);
		}
		int[][] P=new int[K.length][2];
		PriorityQueue<Point> pq=new PriorityQueue<Point>(new PC());
		for(int i=1;i<=N;i++)
		{
			//System.out.println("SS["+i+"] = " +SS[i]+", DD["+i+"] = "+DD[i]);
			if(hs.contains(i))
			{
				pq.add(new Point(SS[i],DD[i]));
				
			}
		}
		Point Pt=null;
		for(int i=0;i<P.length;i++)
		{
			Pt=pq.poll();
			P[i][0]=Pt.SS;
			P[i][1]=Pt.DD;
		}
		int ms=P[0][1];
		int mp=0;
		for(int i=1;i<P.length;i++)
		{
			mp=Math.max(mp,P[i][0]+ms+1);
			ms=Math.max(ms,P[i][1]);
		}
		return Math.min(DD[1],mp);
	}
	
	class Point
	{
		int SS;
		int DD;
		Point(int ss,int dd)
		{
			SS=ss;
			DD=dd;
		}			
	}
	
	class PC implements Comparator<Point>
	{
		public int compare(Point P1,Point P2)
		{
			int p1=P1.DD-P1.SS;
			int p2=P2.DD-P1.SS;
			return p1-p2;
		}
	}
}