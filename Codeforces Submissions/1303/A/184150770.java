import java.io.*;
import java.util.*;
public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t-->0){
            String s=br.readLine();
            int z=0,o=0;
            for(int i=0;i<s.length();i++)
                if(s.charAt(i)=='0')z++;
                else
                o++;
            int i=0,f=0;
            if(o==0)f=1;
            while(i<s.length() && s.charAt(i)=='0'){
                i++;
                z--;
            }
            i=s.length()-1;
            while(i>=0 && s.charAt(i)=='0'){
                i--;
                z--;
            }
            if(f==1)
            z=0;
            System.out.println(z);
        }
    }
}