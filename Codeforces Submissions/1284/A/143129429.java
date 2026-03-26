import java.util.Scanner;

public class New_Year_Naming{

	public static void main(String[] args)
	{
		Scanner Sc = new Scanner(System.in);
		
		int N_Strings = Sc.nextInt();
		int M_Strings = Sc.nextInt();
		String[] List1 = new String[N_Strings];
		String[] List2 = new String[M_Strings];
		
		for(int i=0; i<N_Strings; i++)
			List1[i] = Sc.next();
		for(int i=0; i<M_Strings; i++)
			List2[i] = Sc.next();
		
		int Queries = Sc.nextInt();
		while(Queries-- != 0)
		{
			int year = Sc.nextInt();
			String a = List1[(year-1)%List1.length];
			String b = List2[(year-1)%List2.length];
			
			System.out.println(a+b);
		}
		Sc.close();
	}

}