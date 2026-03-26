import java.util.*;
public class Main
{
public static void main(String[] args) {
Scanner sc=new Scanner(System.in);
int t=sc.nextInt();
for(int p=0;p<t;p++)
{
int n=sc.nextInt();
int z=0;
int[] arr=new int[n];
int even_1=-1,odd_1=-1,odd_2=-1;
for(int i=0;i<n;i++)
{
arr[i]=sc.nextInt();
if(arr[i]%2==0)
{
even_1=i;
}
else{
if(odd_1==-1)
{
odd_1=i;
}
else{
odd_2=i;
}
}
}
if(odd_2==-1&&even_1==-1)
{
System.out.println("-1");
continue;
}
else if(even_1!=-1)
{
System.out.println("1");
System.out.println(even_1+1);
}
else 
{
System.out.println("2");
System.out.print(odd_1+1+" ");
System.out.print(odd_2+1);
System.out.println(" ");

}
}
}
}
 