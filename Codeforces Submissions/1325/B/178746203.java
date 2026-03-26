import java.util.*;

public class Main {

    public static void main(String[] args) {
        new Main();
    }

    public Main() {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int caze = 0; caze < cases; caze++) {
            int n = scanner.nextInt();
            Set<Integer> unique = new HashSet<>();
            for (int i = 0; i < n; i++) {
                unique.add(scanner.nextInt());
            }
            System.out.println(unique.size());
        }
    }

}

		  			 	 	  				 	 	 	 	 		 		