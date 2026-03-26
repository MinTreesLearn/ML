import java.lang.*;
// import java.math.*;
import java.io.*;
import java.util.*;
public class Main{
    public static int mod=(int)(1e9) + 7;

    public static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter ot=new PrintWriter(System.out);

    public static int[] take_arr(int n){
        int a[]=new int[n];
        try {
            String s[]=br.readLine().trim().split(" ");
            for(int i=0;i<n;i++)
            a[i]=Integer.parseInt(s[i]);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return a;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		try{ 
            int t=Integer.parseInt(br.readLine().trim());
            int cno=1;
            
            while(t-->0){
                String s[]=br.readLine().trim().split(" ");
            
                int n=Integer.parseInt(s[0]);
                int m=Integer.parseInt(s[1]);
                // int k=Integer.parseInt(s[2]);
                int a[]=take_arr(n);
                // int b[]=take_arr(n);
                // char ch[]=br.readLine().trim().toCharArray();
                // long n=Long.parseLong(s[0]);
                solve(a,n,m);
            }
            ot.close();
            br.close();
        }catch(Exception e){
            e.printStackTrace();
            return;
        }
    }
    static void solve(int a[], int n, int m){  
        try{
            for(int i=1;i<n;i++){
                a[0]+=Math.min(a[i], m-a[0]);
            }
            ot.println(a[0]);
        } catch(Exception e){
            e.printStackTrace();
            return ;
        }
    }   
}