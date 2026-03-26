import java.util.*;
import java.lang.*;

public class X
{
	public static void main(String[] args)
	{
		X ob=new X();
		Scanner sc=new Scanner(System.in);
		long N=sc.nextInt();
		long[] M=new long[(int)N];
		for(long i=0;i<N;i++)
			M[(int)i]=sc.nextLong();
		ob.solve(M);
	}
	void solve(long[] M)
	{
		long[] lsmall;
		lsmall=left(M);
		long[] rsmall;
		rsmall=right(M);
		long[] L=new long[lsmall.length];
		L[0]=M[0];
		for(long i=1;i<L.length;i++)
		{
			if(lsmall[(int)i]==-1)
				L[(int)i]=(i+1)*M[(int)i];
			else
				L[(int)i]=L[(int)lsmall[(int)i]]+(i-lsmall[(int)i])*M[(int)i];
		}
		long[] R=new long[lsmall.length];
		R[R.length-1]=M[M.length-1];
		for(long i=R.length-2;0<=i;i--)
		{
			if(rsmall[(int)i]==R.length)
				R[(int)i]=(R.length-i)*M[(int)i];
			else
				R[(int)i]=R[(int)rsmall[(int)i]]+(rsmall[(int)i]-i)*M[(int)i];
		}
		
		long MX=0l;
		long peak=0l;
		for(long i=0;i<M.length;i++)
		{
			if(MX<(L[(int)i]+R[(int)i]-M[(int)i]))
			{
				MX=L[(int)i]+R[(int)i]-M[(int)i];
				peak=i;
			}
		}
		long[] A=new long[M.length];
		long mn=M[(int)peak];
		for(long i=peak+1;i<A.length;i++)
		{
			mn=Math.min(mn,M[(int)i]);
			A[(int)i]=mn;
		}
		mn=M[(int)peak];
		for(long i=peak-1;0<=i;i--)
		{
			mn=Math.min(mn,M[(int)i]);
			A[(int)i]=mn;
		}
		A[(int)peak]=M[(int)peak];
		for(int i=0;i<A.length;i++)
			System.out.print(A[(int)i]+" ");
	}
	long[] left(long[] A)
	{
		Stack<Integer> s=new Stack<Integer>();
		long[] L=new long[A.length];
		for(int i=0;i<L.length;i++)
		{
			while(0<s.size() && A[i]<=A[s.peek()])
				s.pop();
			if(s.size()==0)
				L[(int)i]=-1;
			else
				L[(int)i]=s.peek();
			s.push(i);
		}
		
		return L;
	}
	long[] right(long[] A)
	{
		Stack<Integer> s=new Stack<Integer>();
		long[] R=new long[A.length];
		for(int i=R.length-1;0<=i;i--)
		{
			while(0<s.size() && A[i]<=A[s.peek()])
				s.pop();
			if(s.size()==0)
				R[(int)i]=R.length;
			else
				R[(int)i]=s.peek();
			s.push(i);
		}
		
		return R;
	}
}