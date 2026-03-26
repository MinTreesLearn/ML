import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.lang.reflect.Array;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;
import java.math.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.*;
import java.util.Collections;
import java.util.Date;
import java.util.Random;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Date;
public class div {
    static PrintWriter output = new PrintWriter(System.out);
	public static void main(String[] args)  throws java.lang.Exception {
        OutputWriter out = new OutputWriter(System.out);
		div.FastReader sc =new FastReader();
	int t=sc.nextInt(); 
	for(int e =0;e<t;e++) {
int n =sc.nextInt(); int m =sc.nextInt();
String s =sc.next();int arr[]= new int [n];
for(int ee=0;ee<m;ee++) {
	int p=sc.nextInt();arr[p-1]++;
}
int arr1[]= new int [26];
for (int i = n - 1; i > 0; --i) {
	arr[i - 1] += arr[i];
}

for (int i = 0; i < n; ++i) {
	arr1[s.charAt(i) - 'a'] += arr[i];
	++arr1[s.charAt(i) - 'a'];
}

for(int ee=0;ee<25;ee++)out.print(arr1[ee]+" ");
out.println(arr1[25]);
	}
		out.close();
	}
		static class FastReader {
	        BufferedReader br;
	        StringTokenizer st;
	 
	        public FastReader()
	        {
	            br = new BufferedReader(
	                new InputStreamReader(System.in));
	        }
	 
	        String next()
	        {
	            while (st == null || !st.hasMoreElements()) {
	                try {
	                    st = new StringTokenizer(br.readLine());
	                }
	                catch (IOException e) {
	                    e.printStackTrace();
	                }
	            }
	            return st.nextToken();
	        }
	 
	        int nextInt() { return Integer.parseInt(next()); }
	 
	        long nextLong() { return Long.parseLong(next()); }
	 
	        double nextDouble()
	        {
	            return Double.parseDouble(next());
	        }
	        
	        float nextFloat()
	        {
	            return Float.parseFloat(next());
	        }
	 
	        String nextLine()
	        {
	            String str = "";
	            try {
	                str = br.readLine();
	            }
	            catch (IOException e) {
	                e.printStackTrace();
	            }
	            return str;
	        }
	        
	        int[] readArray(int n) {
				int[] a=new int[n];
				for (int i=0; i<n; i++) a[i]=nextInt();
				return a;
			}
			
			long[] readArrayLong(int n) {
				long[] a=new long[n];
				for (int i=0; i<n; i++) a[i]=nextLong();
				return a;
			}
			
	    }
//////////////////////////////////////////////////////////////////////////////////////////
		public static class OutputWriter {
            private final PrintWriter writer;

            public OutputWriter(OutputStream outputStream) {
                writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
            }

            public OutputWriter(Writer writer) {
                this.writer = new PrintWriter(writer);
            }

            public void print(char[] array) {
                writer.print(array);
            }

            public void print(Object... objects) {
                for (int i = 0; i < objects.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(objects[i]);
                }
            }

            public void print(int[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void print(double[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void print(long[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void println(int[] array) {
                print(array);
                writer.println();
            }

            public void println(double[] array) {
                print(array);
                writer.println();
            }

            public void println(long[] array) {
                print(array);
                writer.println();
            }

            public void println() {
                writer.println();
            }

            public void println(Object... objects) {
                print(objects);
                writer.println();
            }

            public void print(char i) {
                writer.print(i);
            }

            public void println(char i) {
                writer.println(i);
            }

            public void println(char[] array) {
                writer.println(array);
            }

            public void printf(String format, Object... objects) {
                writer.printf(format, objects);
            }

            public void close() {
                writer.close();
            }

            public void flush() {
                writer.flush();
            }

            public void print(long i) {
                writer.print(i);
            }

            public void println(long i) {
                writer.println(i);
            }

            public void print(int i) {
                writer.print(i);
            }

            public void println(int i) {
                writer.println(i);
            }
            public void separateLines(int[] array) {
                for (int i : array) {
                    println(i);
                }
            }
        }
/*
Arrays.sort(arr, Comparator.comparingDouble(o -> o[0]));
       					q.replace(i, i+1, "4");
		StringBuilder q = new StringBuilder(s);
List arr1 = new ArrayList();
		String.format("%.2f",arr[ee][0])
		Hashtable s = new Hashtable();
*/

	} 