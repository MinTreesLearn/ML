import java.util.Scanner;
public class JavaApplication67 {
        public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
        int n=sc.nextInt();
      int a=0,b=0;
      if(n%2==0){
          a=n/2;
          b=n/2;
      }
      else{
       a=n-1;
       b=1;
      }       

     System.out.println(a+" "+b);
} 
    }
}
    

       

    
    

