import java.util.*;

public class CF1316_B{
       public static void main(String args[]){
              Scanner in=new Scanner(System.in);
              int t=in.nextInt();
              while(t-->0){
                     int n=in.nextInt();
                     String s=in.next();
                     String ans=s;
                     String temp="";
                     int k=1;
                     int count=1;
                     
                    for(int i=1;i<n;i++){
                        count++;
                       temp=s.substring(i);
                        if((n-count+1)%2==0){
                            temp+=s.substring(0,i);
                        }
                        else{
                            StringBuilder sb=new StringBuilder(s.substring(0,i));
                            temp+=sb.reverse().toString();
                        }
                            
                    
                     if(temp.compareTo(ans)<0){
                         ans=temp;
                         k=count;
                     }
                    }
                    System.out.println(ans);
                    System.out.println(k);
              }
       }
}