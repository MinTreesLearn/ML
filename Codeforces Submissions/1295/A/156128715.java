import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Submit {

	public static void main(String[] args) throws IOException {
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		try (InputReader ir = new InputReader()) {
			int t = ir.nextInt();
			while (t-- > 0) {
				int n = ir.nextInt();
				if (n % 2 == 1) {
					n -= 3;
					writer.append("7");
				}
				while (n > 0) {
					n -= 2;
					writer.append("1");
				}
				writer.append(System.lineSeparator());
				writer.flush();
			}
		}
	}
}

class InputReader implements AutoCloseable {

	private BufferedReader bufferedReader;
	private StringTokenizer tokenizer;

	public InputReader() {
		bufferedReader = new BufferedReader(new InputStreamReader(System.in));
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreElements()) {
			try {
				tokenizer = new StringTokenizer(bufferedReader.readLine());
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		return tokenizer.nextToken();
	}

	public char nextChar() {
		char character = ' ';
		try {
			character = (char) bufferedReader.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return character;
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public String nextLine() {
		String line = "";
		try {
			line = bufferedReader.readLine();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
		return line;
	}

	@Override
	public void close() {
		try {
			this.bufferedReader.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
}
