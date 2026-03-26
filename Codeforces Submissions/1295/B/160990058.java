import java.io.*;
 import java.util.*;
 import java.math.*;
    public class Main{
        public static void main(String[]args)throws IOException{
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            int T=Integer.parseInt(br.readLine());
            while(T>0){
                StringTokenizer st=new StringTokenizer(br.readLine());
                int n=Integer.parseInt(st.nextToken());
                int x=Integer.parseInt(st.nextToken());
                String s=br.readLine();
                int b[]=new int[n];
                int zero=0,one=0;
                for(int i=0;i<n;i++){
                    if(s.charAt(i)=='1'){
                        one++;
                    }
                    else{
                        zero++;
                    }
                    b[i]=zero-one;
                }
                if(b[n-1]==0){
                    boolean ok=false;
                    for(int i=0;i<n;i++){
                        if(b[i]==x){
                            ok=true;
                            break;
                        }
                    }
                    if(ok){
                        System.out.println(-1);
                    }
                    else{
                        System.out.println(0);
                    }
                }
                else if(b[n-1]>0){
                    int cnt=0;
                    if(x==0){
                        cnt=1;
                    }
                    for(int i=0;i<n;i++){
                        if(b[i]<=x && (x-b[i])%(b[n-1])==0){
                            cnt++;
                        }
                    }
                    System.out.println(cnt);
                }
                else{
                    int cnt=0;
                    if(x==0){
                        cnt=1;
                    }
                    for(int i=0;i<n;i++){
                        if(b[i]>=x && (b[i]-x)%(Math.abs(b[n-1]))==0){
                            cnt++;
                        }
                    }
                    System.out.println(cnt);
                }
                T--;
            }



























































        }
    }
