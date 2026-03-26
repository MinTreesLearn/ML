import java.util.*;

public class MyClass {
    
    // public static boolean chek(String str){
    //     char c = str.charAt(0);
    //     for(int i=1;i<4;i++){
    //         for(int j=i;j<4;j++){
    //             if(c==str.charAt(j)){
    //                 return false;
    //             }
    //         }
    //         c = str.charAt(i); 
    //     }
    //     return true;
    // }
    
    public static void main(String args[]) {
      Scanner s = new Scanner(System.in);
      int n = s.nextInt();
      s.nextLine();
    //   int h = s.nextInt();
    //   int t = s.nextInt();
      
    //   String str1 = s.nextLine();
    //   String str2 = s.nextLine();
    //   int sum = 0;
      
      for(int i=0;i<n;i++){
          int n1 = s.nextInt();
          s.nextLine();
          int odd = 0;
          int even = 0;
          int count = 0;
          for(int j=0;j<n1;j++){
              int n2 = s.nextInt();
              count++;
              if(n2%2==0){
                  even++;
              }else{
                  odd++;
              }
          }
          
          if(count == even){
              System.out.println("YES");
          }else if(count ==odd){
              System.out.println("YES");
          }else{
              System.out.println("NO");
          }   
      }
    }
}