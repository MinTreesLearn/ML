import java.io.* ;
import java.util.* ;


 
public class App {
    public static void main (String[] args) throws java.lang.Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        //reader = new BufferedReader(new FileReader(new File("C:\\Users\\Anjali\\Desktop\\projects\\HelloWorld\\src\\input.txt")));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        //writer = new BufferedWriter(new FileWriter(new File("C:\\Users\\Anjali\\Desktop\\projects\\HelloWorld\\src\\output.txt")));
		//int tests = Integer.parseInt(reader.readLine());
        int tests = 1;
		//StringBuilder sb = new StringBuilder(tests);
		while (tests-- > 0){
		    solve(reader, writer);
            writer.write("\n");
		}
		reader.close();
        writer.flush();
        writer.close();
    }

 
    static void solve(BufferedReader reader, BufferedWriter writer) throws  IOException {
		int tests = Integer.parseInt(reader.readLine());
		for (int j = 0; j < tests; j++) {
			String[] input = reader.readLine().split(" ");
			int n = Integer.parseInt(input[0]);
			int d = Integer.parseInt(input[1]);
			int[] a = new int[n + 1];
			String[] input1 = reader.readLine().split(" ");
			for (int i = 0; i < n; i++) {
				a[i + 1] = Integer.parseInt(input1[i]);
			}
			for (int i = 0; i < d; i++) {
				for (int k = 2; k <= n; k++) {
					if (a[k] > 0) {
						a[k]--;
						a[k - 1]++;
						break;
					}
				}
			}
			writer.write(a[1]+ "\n");
		}	
	}
}
