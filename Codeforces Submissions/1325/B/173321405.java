import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
public class JavaApplication70 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
      HashSet<Integer>copy=new HashSet<Integer>();
       HashSet<Integer>copy1=new HashSet<Integer>();

        int n=sc.nextInt();
         for(int i=0;i<n/2;i++){
           copy.add(sc.nextInt());
                   }
         for(int i=n/2;i<n;i++){
            copy1.add(sc.nextInt());
         }
         copy.addAll(copy1);
               System.out.println(copy.size());
           
       }
    }
}     
    


                                                                                                                                                                              
