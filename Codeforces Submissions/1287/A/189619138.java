// Program Code
// Problem A:

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.io.*;
import java.util.*;
import java.math.*;




public class Solution {
	
	static int N = 1000000;
	static int M = 1000000007;
	static String res = "";
	
	public static void main(String[] args) throws Exception{
		fileConnect();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long ab = 0;

     	long t = Long.parseLong(st.nextToken());

     	

     	while(++ab <= t){
     		st = new StringTokenizer(br.readLine());
     		int n = Integer.parseInt(st.nextToken());
     		st = new StringTokenizer(br.readLine());
     		String str = st.nextToken();
     		char[] arr = str.toCharArray();

     		int max = 0;
     		int temp = 0;
     		int i=0; 
     		while(i<n){
     			if(arr[i] != 'A'){
     				i++;
     			}else break;
     		}

     		while(i<n){
     			int cnt = 0;
     			while(i < n && arr[i] == 'P'){
     				i++;
     				cnt++;
     			}
     			i++;
     			max = Math.max(max, cnt);
     		}
     		System.out.println(max);
     	} // end of while loop
		
		
	}

	static boolean check(int a, int b, int c, int d)
	{
		if(a < b && c < d && a < c && b < d) return true;
		else return false;
	}


	static int value(char c){
		if(c == 'X') return 1;
		else if(c == 'S') return 2;
		else if(c == 'M') return 3;
		else if(c == 'L') return 4;
		else return -1;
	}

	static boolean check(int[] arr, int[] brr){

		for(int i=0; i<26; i++){
			if(2*arr[i] != brr[i]) return false;
		}

		return true;
	}


	// gcd
	static long gcd(long a, long b){
		
		if(b == 0) return a;
	
		return gcd(b, a%b);
	}


	
	
	// read array
	 static int[] readArr(int N, BufferedReader br, StringTokenizer st) throws Exception
    {
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        return arr;
    }

     static long[] readArr2(int N, BufferedReader br, StringTokenizer st) throws Exception
    {
        long[] arr = new long[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i < N; i++)
            arr[i] = Long.parseLong(st.nextToken());
        return arr;
    }

    // print array
	static void printArr(int[] arr, int n){
		for(int i=0; i<n; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
    
	// FileInputOutput
	 static void fileConnect(){
		try {
			System.setIn(new FileInputStream("input.txt"));
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {

			System.err.println("Error");
		}
	}

	
	
	
}