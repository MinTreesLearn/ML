/*
Codeforces
Problem 1286A
*/

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;

public class Garland {
	
	public static void main(String[] args) throws IOException {
		FastIO in = new FastIO(System.in);
		
		int n = in.nextInt();
		
		int[] par = new int[2];
		par[0] = (n)/2;
		par[1] = (n+1)/2;
		
		int[] p = new int[n];
		for(int i=0;i<n;i++) {
			p[i] = in.nextInt();
			if(p[i]!=0) {
				if(p[i]%2==0) par[0]--;
				else par[1]--;
			}
		}
		
		ArrayList<Integer>[] list = new ArrayList[2];
		for(int i=0;i<2;i++ ) list[i] = new ArrayList<Integer>();
		
		ArrayList<Integer>[] sList = new ArrayList[2];
		for(int i=0;i<2;i++) sList[i] = new ArrayList<Integer>();
		
		int cnt = 0;
		
		for(int i=0;i<n;i++) {
			if(p[i] == 0) {
				int j = i;
				while(i<n-1 && p[i+1]==0) i++;
				int l = (j>0)?p[j-1]:-1;
				int r = (i<n-1)?p[i+1]:-1;
				
				if(l!=-1 && r!=-1) {
					if(l%2==r%2) {
						list[l%2].add(i-j+1);
					}
					else cnt++;
				}
				else if(l==-1) {
					sList[(r+2)%2].add(i-j+1);
				}
				else if(r==-1) {
					sList[(l+2)%2].add(i-j+1);
				}
			}
		}
		
		Collections.sort(list[0]);
		Collections.sort(list[1]);
		
		for(int i=0;i<2;i++) {
			int sum = 0;
			int c = 0;
			for(int j=0;j<list[i].size();j++) {
				if(sum + list[i].get(j)>par[i]) {
					break;
				}
				sum += list[i].get(j);
				c++;
			}
			par[i] -= sum;
			cnt += 2*(list[i].size()-c);
		}
		Collections.sort(sList[0]);
		Collections.sort(sList[1]);
		for(int i=0;i<2;i++) {
			int sum = 0;
			int c = 0;
			for(int j=0;j<sList[i].size();j++) {
				if(sum + sList[i].get(j)>par[i]) {
					break;
				}
				sum += sList[i].get(j);
				c++;
			}
			cnt += sList[i].size()-c;
		}
		for(int i=0;i<n-1;i++) {
			if(p[i]!=0 && p[i+1]!=0) {
				if(p[i]%2!=p[i+1]%2) cnt++;
			}
		}
		System.out.println(cnt);
		
		
		in.close();
	}
	
	public static class FastIO {
		private InputStream dis;
		private byte[] buffer = new byte[1 << 17];
		private int pointer = 0;
	
		public FastIO(String fileName) throws IOException {
			dis = new FileInputStream(fileName);
		}
	
		public FastIO(InputStream is) throws IOException {
			dis = is;
		}
	
		public int nextInt() throws IOException {
			int ret = 0;
			byte b;
			
			do {
				b = nextByte();
			} while (b <= ' ');
			
			boolean negative = false;
			if (b == '-') {
				negative = true;
				b = nextByte();
			}
			
			while (b >= '0' && b <= '9') {
				ret = 10 * ret + b - '0';
				b = nextByte();
			}
	
			return (negative) ? -ret : ret;
		}
	
		public long nextLong() throws IOException {
			long ret = 0;
			byte b;
			
			do {
				b = nextByte();
			} while (b <= ' ');
			
			boolean negative = false;
			if (b == '-') {
				negative = true;
				b = nextByte();
			}
			
			while (b >= '0' && b <= '9') {
				ret = 10 * ret + b - '0';
				b = nextByte();
			}
			
			return (negative) ? -ret : ret;
		}
	
		public byte nextByte() throws IOException {
			if (pointer == buffer.length) {
				dis.read(buffer, 0, buffer.length);
				pointer = 0;
			}
			return buffer[pointer++];
		}
	
		public String next() throws IOException {
			StringBuffer ret = new StringBuffer();
			byte b;
			
			do {
				b = nextByte();
			} while (b <= ' ');
			
			while (b > ' ') {
				ret.appendCodePoint(b);
				b = nextByte();
			}
	
			return ret.toString();
		}
	
		public void close() throws IOException {
			dis.close();
		}
	}
}