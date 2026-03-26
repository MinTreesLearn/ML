    import java.util.*;
    public class Solution{
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            int test_cases = sc.nextInt();
            outer : for(int h=0;h<test_cases;h++){
                long x = sc.nextLong();
                long y = sc.nextLong();
                long a = sc.nextLong();
                long b = sc.nextLong();
                if((y-x)%(a+b)!=0){
                    System.out.println(-1);
                }
                else{
                    System.out.println((int)(y-x)/(a+b));
                }
            }
        }
        public static int calculate_gcd(int x,int y){
            int gcd = 1;
            if(x%y==0){
                return y;
            }
            else if(y%x==0){
                return x;
            }
            else{
                for(int i=2;i<=x && i<=y;i++){
                    if(x%i==0 && y%i==0){
                        gcd = i;
                    }
                }
                return gcd;
            }
        }
        public static long calculate_factorial(long x){
            long ans = 1;
            for(int i=1;i<=x;i++){
                ans*=i;
            }
            return ans;
        }
        public static void swap(int a[], int b[], int index_a, int index_b){
            int temp = a[index_a];
            a[index_a] = b[index_b];
            b[index_b] = temp;
        }
        public static long find_maximum(long a[]){
            long max = Long.MIN_VALUE;
            for(int i=0;i<a.length;i++){
                max = Math.max(a[i], max);
            }
            return max;
        }
        public static long find_minimum(long a[]){
            long min = Long.MAX_VALUE;
            for(int i=0;i<a.length;i++){
                min = Math.min(a[i], min);
            }
            return min;
        }
    }  