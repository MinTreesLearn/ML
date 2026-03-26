import java.io.*;
import java.util.*;

public class new1{
	static FastReader s = new FastReader();

	public static void main(String[] args)  throws IOException{

		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = s.nextInt();
		for(int z = 0; z < t; z++) {
			int n = s.nextInt() - 1;
			String str = s.next();
			ArrayList<Integer> aList = new ArrayList<Integer>();
			int count = 1;
			for(int i = 1; i < n; i++) {
				if(str.charAt(i) == str.charAt(i - 1)) count++;
				else {
					if(str.charAt(i - 1) == '>') count = -1 * count;
					aList.add(count);
					count = 1;
					//i++;
				}
			}

			if(str.charAt(n - 1) == '>') count = count * -1;
			aList.add(count);
			if(count < 0) aList.add(0);
			
			
			
			ArrayList<Integer> ans = new ArrayList<Integer>();
			ans.add(0);
			//System.out.println(aList.toString());
			int curr = 0;
			int ind = 0;
			if(aList.get(ind) >= 0) {
				for(int i = 1; i <= aList.get(ind); i++) {
					ans.add(i);
				}
				ind++;
			}
			while(ind < aList.size()) {
				for(int i = curr -aList.get(ind + 1) - 1; i >= curr - aList.get(ind + 1) + aList.get(ind); i--) {
					ans.add(i);
				}
				for(int i = curr - aList.get(ind + 1); i < curr; i++) {
					ans.add(i);
				}
				curr = curr - aList.get(ind + 1) + aList.get(ind);
				ind = ind + 2;
			}
			
			
			//////////////////////////////////////////////////////////////////
			curr = 0; ind = 0;
			ArrayList<Integer> ans2=  new ArrayList<Integer>();
			ans2.add(0);
			if(aList.get(aList.size() - 1) == 0) aList.remove(aList.size() - 1);
			else aList.add(0);
			if(aList.get(ind) <= 0) {
				for(int i = -1; i >= aList.get(ind); i--) {
					ans2.add(i);
				}
				ind++;
			}
			//System.out.println(aList.toString());
			while(ind < aList.size()) {
				for(int i = curr - aList.get(ind + 1) + 1; i < curr - aList.get(ind + 1) + aList.get(ind) + 1; i++) {
					ans2.add(i);
				}
				for(int i = curr - aList.get(ind + 1); i > curr; i--) {
					ans2.add(i);
				}
				curr = curr - aList.get(ind + 1) + aList.get(ind);
				ind = ind + 2;
			}
			
			
			int min1 = 10000000; int min2 = min1;
			for(int i = 0; i <  ans.size(); i++) {
				min1 = Math.min(min1, ans.get(i));
				min2 = Math.min(min2, ans2.get(i));
			}
			for(int i = 0; i < ans.size(); i++) {
				ans.set(i, ans.get(i) - min1 + 1);
				ans2.set(i, ans2.get(i) - min2 + 1);
			}
			for(int i = 0; i <= n; i++) output.write(ans.get(i) + " ");
			output.write("\n");
			for(int i = 0; i <= n; i++) output.write(ans2.get(i) + " ");
			output.write("\n");
		}
		
		output.flush();
			
	  }
}


 
class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
}}