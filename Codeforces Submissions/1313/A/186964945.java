import java.util.*;
public class FastFood {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        int t=scanner.nextInt();
        for(int i = 0; i<t; i++){
            int arr[]=new int[3];
            arr[0]=scanner.nextInt();
            arr[1]=scanner.nextInt();
            arr[2]=scanner.nextInt();
            Arrays.sort(arr);
            if(arr[0]>=4){
                System.out.println("7");
            }
            else if(arr[0]==3){
                System.out.println("6");
            }
            else if(arr[0]==2){
                if(arr[1]>=3){
                    System.out.println("5");
                }
                else{
                    if(arr[2]>=3){
                        System.out.println("5");
                    }
                    else {
                        System.out.println("4");
                    }
                }
            }
            else if(arr[0]==1){
                if(arr[1]==1){
                    System.out.println("3");
                }

                else{
                    System.out.println("4");
                }

            }
            else if(arr[0]==0){
                if(arr[1]==1){
                    System.out.println("2");
                }
                else if(arr[1]==0&&arr[2]>0){
                    System.out.println("1");
                }
                else if(arr[1]==0&&arr[2]==0){
                    System.out.println("0");
                }
                else{
                    System.out.println("3");
                }

            }

        }
    }
}
