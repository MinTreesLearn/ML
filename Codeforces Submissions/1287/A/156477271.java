import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Submit {
	public static void main(String[] pojebaneArgumenty) throws IOException {
		try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
				FastReader reader = new FastReader()) {
			int t = reader.nextInt();
			int g;
			String s;
			while (t-- > 0) {
				g = reader.nextInt();
				s = reader.nextLine();
				int counter = 0, max = 0;
				if (s.indexOf('A') >= 0) {
					for (int i = s.indexOf('A') + 1; i < g; i++) {
						if (s.charAt(i) == 'P') {
							counter++;
							if (max < counter) {
								max = counter;
							}
						} else {
							counter = 0;
						}
					}
				}
				writer.append(max + System.lineSeparator());
				writer.flush();
			}
		}
	}
}

class FastReader implements AutoCloseable {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public FastReader() {
		this.reader = new BufferedReader(new InputStreamReader(System.in));
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreElements()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		while (tokenizer == null || !tokenizer.hasMoreElements()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return Integer.parseInt(tokenizer.nextToken());
	}

	public String nextLine() {
		String line = "";
		try {
			line = reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return line;
	}

	public char nextChar() {
		char character = ' ';
		try {
			character = (char) reader.read();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
		return character;
	}

	@Override
	public void close() {
		try {
			this.reader.close();
		} catch (IOException closingEx) {
			// ignore
		}
	}
}
