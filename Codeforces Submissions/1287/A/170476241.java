//ღ(¯`◕‿◕´¯) ♫ ♪ ♫ YuSuF ♫ ♪ ♫ (¯`◕‿◕´¯)ღ

import java.util.*;

public class Angry_Students {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            char ar[] = in.next().toCharArray();
            int counter = 0;
            while (true) {
                boolean hasAP = false;
                for (int i = 0; i < n - 1; i++) {
                    if (ar[i] == 'A' && ar[i + 1] == 'P') {
                        hasAP = true;
                        ar[i + 1] = 'A';
                        i++;
                    }
                }
                if (!hasAP) {
                    break;
                } else {
                    counter++;
                }
            }
            System.out.println(counter);
        }
    }

}

         	 						   	  	    	