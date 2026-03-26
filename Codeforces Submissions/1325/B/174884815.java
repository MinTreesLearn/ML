import java.util.*;
public class hello{
    public static void main(String []args){
        Scanner inp =new Scanner(System.in);
        int t=inp.nextInt();
        while(t-->0){
            int n=inp.nextInt();
            int []arr=new int[n];
            for(int i=0;i<n;i++){
                arr[i]=inp.nextInt();

            }
            Arrays.sort(arr);
            int uni=1;
            for(int i=0;i<n-1;i++){
                if(arr[i]!=arr[i+1]) uni++;
            }
            System.out.println(uni);
        }
    }
}