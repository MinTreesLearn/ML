//package codeForcesRound625;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJourneyPlanning {

	public static void main(String[] args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int[] a=new int[n];
		
		StringTokenizer st=new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			a[i]=Integer.parseInt(st.nextToken());
		}
		long[] sums = new long[1000000];
		int off = 500000;
		for (int i = 0; i < n; i++)
		{
			int d = a[i]-i;
			sums[d+off] += a[i];
		}
		long max = 0;
		for (int i = 0; i < sums.length; i++)
			max = Math.max(max, sums[i]);
		System.out.println(max);
		
	}

}
