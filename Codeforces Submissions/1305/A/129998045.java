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
		for (int i = 0; i < tests; i++) {
			int n = Integer.parseInt(reader.readLine());
			int[] a = new int[n];
			int[] b = new int[n];
			String[] input = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(input[j]);
			}
			String[] input1 = reader.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				b[j] = Integer.parseInt(input1[j]);
			}
			Arrays.sort(a);
			Arrays.sort(b);
			for (int j = 0; j < n; j++) {
				writer.write(a[j] + " ");
			}
			writer.write("\n");
			for (int j = 0; j < n; j++) {
				writer.write(b[j] + " ");
			}
			writer.write("\n");
		}
	}
}
