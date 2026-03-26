import java.util.Scanner;
public class FrogJumps {
    public static void main(String args[]){
        Scanner sr=new Scanner(System.in);
        int t=sr.nextInt();
        for (int i=0;i<t;i++){
            System.out.println(findMaxJump(sr.next(), 0, 0,0));
        }
    }
    public static int findMaxJump(String lrs, int maxJump, int currentJump, int i){
        if(i>=lrs.length()){
            return maxJump+1;
        }
        if(lrs.charAt(i)=='L'){
            currentJump++;
        }
        else {
            currentJump=0;
        }
        if(currentJump>maxJump){
            maxJump=currentJump;
        }
        return findMaxJump(lrs,maxJump,currentJump,i+1);
    }
}