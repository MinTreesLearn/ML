import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.rmi.Remote;
// import java.util.Scanner;
import java.util.*;

import javax.management.Query;

public class second {
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(
					new InputStreamReader(System.in));
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

		int nextInt() {
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
				if (st.hasMoreTokens()) {
					str = st.nextToken("\n");
				} else {
					str = br.readLine();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	public static void main(String[] args) {
		FastReader s = new FastReader();
		// int test_cases=s.nextInt();
		// outer:while(test_cases-->0){
			
		// }
		int numString=s.nextInt();
		int size=s.nextInt();
		String [] strings=new String[numString];
		String [] reverseStrings=new String[numString];
		for(int i=0;i<numString ;i++){
			strings[i]=s.next();
			StringBuffer sb=new StringBuffer("");
			sb.append(strings[i]);
			reverseStrings[i]=sb.reverse().toString();
		}
		String first="",last="",temp="";
		for (int i = 0; i < numString; i++) {
			for (int j = i; j <numString; j++) {
				if(strings[j].equals(reverseStrings[i])){
					if(i==j){
						temp=strings[i];
					}
					else{
						first+=strings[i];
						last=reverseStrings[i]+last;
					}
				}
			}
		}
		first=first+temp+last;
		System.out.println(first.length());
		System.out.println(first);
	}
}
