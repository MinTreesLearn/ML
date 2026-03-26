import java.util.Scanner;

public class hello 
{
    public static void main(String [] args) 
    {
       
       Scanner sc = new Scanner(System.in);
       int n1 = sc.nextInt();
       
for(int i=0;i<n1;i++){

	int n = sc.nextInt();
	boolean odd = false;
	boolean even = false;
	int sum = 0;  
	for(int m=0;m<n;m++){
	int t = sc.nextInt();
	sum += t;
	if(t%2 == 0){
	even = true;
	}else{
	odd = true;
	} 		

	}

	if(sum%2 != 0){
	System.out.println("YES");
}else{
	if(odd == true && even == true){
	System.out.println("YES");
}else{
	System.out.println("NO");
}
}

}
    	
    }
    
    
    
}
