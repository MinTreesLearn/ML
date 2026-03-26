import java.util.*;
public class JavaApplication51 {
static Scanner z = new Scanner(System.in);
    public static void main(String[] args) {
       int d=z.nextInt();
      
       
       while(d-->0){
            int s=z.nextInt();
           String c=z.next();
    StringBuffer k = new StringBuffer(c);
    int count=0;
   while(true){
    boolean h=false;
    String l=k.toString();
    StringBuffer r=new StringBuffer("") ;
        for (int i = 1; i < s; i++) {
            if(k.charAt(i-1)=='A'&&k.charAt(i)=='P'){
                k.setCharAt(i, 'A');
                h=true;
             i++;
            }           
        }
         r=k;
        if(h){
           count++; 
        }
      if(l.equals(r.toString())){
          break;
      }
    }
       System.out.println(count);
        }
       }
    }

  		   		 		 		 	 		 		 		  	