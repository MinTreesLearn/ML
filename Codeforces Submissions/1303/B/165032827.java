
import static java.lang.Math.*;

import java.awt.Point;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Exercise {	
	static Scanner sc = new Scanner(System.in);
	//B. Composite Coloring

	
	public static void solve() {
		long l = sc.nextInt();
		long g = sc.nextInt();
		long b = sc.nextInt();
		
		if(g >= l) {
			System.out.println(l);
		} else {
			long tt = (long) ceil(l/2.0);
			long res = tt % g;
			long div = tt / g ;
			
			long result = (div * g) + ((div - 1) * b);
			
			if(res > 0) result += res + b;
			
			if(result < l) System.out.println(l);
			else System.out.println(result);
		}
	}

	public static void main(String args[]) {
		
		
		int test = sc.nextInt();
		
		while(test-- != 0) solve();
	}

}
