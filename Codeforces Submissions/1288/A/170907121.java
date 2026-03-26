import java.util.Scanner;

public class FirstChallenge 
{
    public static void main(String [ ] args)
    {
        Scanner in = new Scanner(System.in);
        int number = in.nextInt();
        for(int t=0;t<number;t++){
            int n=in.nextInt();//time to do it 3
            int d=in.nextInt();//time it takes to do 4
            boolean isPossible=false;
            if(n==d){
                isPossible=true;
            }
            for(int i=0;i<=n;i++){
                int temp=0;
                double value=(double)d/(double)(i+1);
                int gone=d/(i+1);
                if(value!=gone){
                    gone++;
                }
                temp=i+gone;
                if(temp<=n){
                    isPossible=true;
                    break;
                }
            }
            if(isPossible){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
        
        
    }

}
