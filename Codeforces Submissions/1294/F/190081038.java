import java.util.*;
import java.lang.*;

public class Y
{
	public int[][][] abc;
	public int[][] up;
    public static void main(String[] args)
    {
        Y ob=new Y();
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		ArrayList<ArrayList<Integer>> AA=new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<N;i++)
		{
			AA.add(new ArrayList<Integer>());
		}
		for(int i=1;i<N;i++)
		{
			int U=sc.nextInt();
			int V=sc.nextInt();
			U=U-1;
			V=V-1;
			AA.get(U).add(V);
			AA.get(V).add(U);
		}
		ob.solve(AA);
    }
	void solve(ArrayList<ArrayList<Integer>> AA)
	{
		abc=new int[AA.size()][3][2];
		int d=fill(AA,0,-1);
		up=new int[AA.size()][2];
		up[0][0]=0;
		up[0][1]=0;
		int u=upfill(AA,0,-1);
		show(AA);
	}
	void show(ArrayList<ArrayList<Integer>> AA)
	{
		int m=0;
		int a=0;
		int b=0;
		int c=0;
		for(int i=0;i<AA.size();i++)
		{
			/*
			System.out.println();
			System.out.println("curr -> "+i);
			System.out.println("up.D -> "+up[i][0]+" , up.P -> "+up[i][1]);
			System.out.println("D0.D -> "+abc[i][0][0]+" , D0.P -> "+abc[i][0][1]);
			System.out.println("D1.D -> "+abc[i][1][0]+" , D1.P -> "+abc[i][1][1]);
			System.out.println("D2.D -> "+abc[i][2][0]+" , D2.P -> "+abc[i][2][1]);
			*/
			int upp=up[i][1];
			int d0p=abc[i][0][1];
			int d1p=abc[i][1][1];
			int d2p=abc[i][2][1];
			if(m<(abc[i][0][0]+abc[i][1][0]+up[i][0]) && (upp!=d0p && d0p!=d1p && d1p!=upp))
			{
				m=(abc[i][0][0]+abc[i][1][0]+up[i][0]);
				a=abc[i][0][1];
				b=abc[i][1][1];
				c=up[i][1];	
			}
			if(m<(abc[i][0][0]+abc[i][1][0]+abc[i][2][0]) && (d2p!=d0p && d0p!=d1p && d1p!=d2p))
			{
				m=(abc[i][0][0]+abc[i][1][0]+abc[i][2][0]);
				a=abc[i][0][1];
				b=abc[i][1][1];
				c=abc[i][2][1];	
			}
		}
		System.out.println(m);
		System.out.println((a+1)+" "+(b+1)+" "+(c+1));
	}
	int fill(ArrayList<ArrayList<Integer>> AA,int curr,int parent)
	{
		
		abc[curr][0][0]=abc[curr][1][0]=abc[curr][2][0]=0;
		abc[curr][0][1]=abc[curr][1][1]=abc[curr][2][1]=curr;
		if(AA.get(curr).size()==1 && AA.get(curr).get(0)==parent)
		{
			
			return 0;
		}
		PriorityQueue<Point> pq=new PriorityQueue<Point>(new PC());
		for(int i=0;i<AA.get(curr).size();i++)
		{
			int now=AA.get(curr).get(i);
			if(now==parent)
			{
				continue;
			}
			fill(AA,now,curr);
			if(pq.size()<3)
			{
				pq.add(new Point(abc[now][0][0],abc[now][0][1]));
			}
			else if(pq.size()==3 && pq.peek().D<abc[now][0][0])
			{
				pq.poll();
				pq.add(new Point(abc[now][0][0],abc[now][0][1]));
			}
		}
		
		int j=0;
		while(0<pq.size())
		{
			j=pq.size();
			j=j-1;
			Point P=pq.poll();
			abc[curr][j][0]=P.D+1;
			abc[curr][j][1]=P.P;
		}
		return abc[curr][0][0];
	}
	
	int upfill(ArrayList<ArrayList<Integer>> AA,int curr,int parent)
	{
		int[][] DD=new int[3][2];
		DD[0][0]=up[curr][0];
		DD[0][1]=up[curr][1];
		DD[1][0]=abc[curr][0][0];
		DD[1][1]=abc[curr][0][1];
		DD[2][0]=abc[curr][1][0];
		DD[2][1]=abc[curr][1][1];
		for(int i=0;i<AA.get(curr).size();i++)
		{
			int next=AA.get(curr).get(i);
			if(next==parent)
			{
				continue;
			}
			int MD=DD[0][0];
			int MP=DD[0][1];
			if(abc[next][0][1]!=DD[1][1] && MD<DD[1][0])
			{
				MD=DD[1][0];
				MP=DD[1][1];
			}
			if(abc[next][0][1]!=DD[2][1] && MD<DD[2][0])
			{
				MD=DD[2][0];
				MP=DD[2][1];
			}
			up[next][0]=MD+1;
			up[next][1]=MP;
			upfill(AA,next,curr);
		}
		return DD[0][0];
	}
	
	public class Point
	{
		int D;
		int P;
		Point(int d,int p)
		{
			D=d;
			P=p;
		}
	}
	public class PC implements Comparator<Point>
	{
		public int compare(Point P1,Point P2)
		{
			return P1.D-P2.D;
		}
	}
}