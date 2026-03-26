import java.io.*;
import java.util.*;

public class Recommendations {
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[][] categories = new int[N][2];
		String[] temp = br.readLine().split(" ");
		for (int i = 0; i < N; i++)
			categories[i][0] = Integer.parseInt(temp[i]); // 0 is number of articles
		temp = br.readLine().split(" ");
		for (int i = 0; i < N; i++)
			categories[i][1] = Integer.parseInt(temp[i]); // 1 is cost
		Comparator<int[]> c = new Comparator<int[]>()
		{
			public int compare(int[] o1, int[] o2)
			{
				return o1[0]-o2[0];
			}
		};
		Arrays.sort(categories, c);
		Comparator<Integer> c2 = new Comparator<Integer>()
		{
			public int compare(Integer o1, Integer o2)
			{
				return o2-o1;
			}
		};		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(c2);
		int current = categories[0][0]; long sum = 0; long ans = 0; int i = 0;
		while (i < N)
		{
			while (i < N && categories[i][0] == current)
			{
				pq.add(categories[i][1]);
				sum += categories[i][1]; i++;
			}
			if (!pq.isEmpty())
			{
				sum -= pq.remove();
				current++;
				ans += sum;
			}
			else
				current = categories[i][0];
			//System.out.println(pq);
			//System.out.println(sum);
		}
		while (!pq.isEmpty())
		{
			sum -= pq.remove();
			ans += sum;		
		}
		System.out.println(ans);
	}
}
