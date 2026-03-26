import java.util.*;
import java.io.*;

public class Main 
{
	
	public static void main(String[] args) throws IOException 
	{ 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer s = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(s.nextToken());
		Pair ar[]=new Pair[n];
		for(int i=0;i<n;i++)
			ar[i]=new Pair(0,0);
		s = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			ar[i].fi=Integer.parseInt(s.nextToken());
		}
			
		s = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++)
			ar[i].si=Integer.parseInt(s.nextToken());
		
		Arrays.sort(ar,(a,b)->(a.fi==b.fi)?b.si-a.si:a.fi-b.fi);
		PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());
		long sum=0;
		long ans=0;
		int prev=-1;
		for(int i=0;i<n;i++) {
			while(!pq.isEmpty() && ar[i].fi>prev) {
				sum-=pq.poll();
				ans+=sum;
				prev++;
			}
			sum+=ar[i].si;
			pq.add(ar[i].si);
			prev=ar[i].fi;
		}
		
		while(!pq.isEmpty()) {
			sum-=pq.poll();
			ans+=sum;
		}
		pw.println(ans);
		pw.close();
		

	}
}
class Pair{
	int fi;
	int si;
	Pair(int fi,int si){
		this.fi=fi;
		this.si=si;
	}
	
}