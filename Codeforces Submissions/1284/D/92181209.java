//package com.cf.hello2020;//package com.cf.r664;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.SortedMap;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class D {

	private FastScanner in;
	private PrintWriter out;

	public static void main(String[] args) {
		new D().run();
	}

	private void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		int n = in.nextInt();

		List<Speaker> speakers = IntStream.range(0, n).mapToObj(i -> Speaker.read(in)).collect(Collectors.toList());

		if (existsSensitiveness(speakers)) {
			out.println("NO");
		} else {
			out.println("YES");
		}

		out.close();
	}

	private boolean existsSensitiveness(List<Speaker> speakers) {
		for (int i = 0; i < 2; i++) {
			if (existsSensitiveness(speakers, i)) {
				return true;
			}
		}
		return false;
	}

	private boolean existsSensitiveness(List<Speaker> speakers, int intersectingIdx) {
		List<Event> events =
				IntStream.range(0, speakers.size())
					.boxed()
					.flatMap(idx -> Stream.of(new Event(idx, true, speakers.get(idx).s[intersectingIdx]),
							new Event(idx, false, speakers.get(idx).e[intersectingIdx])))
					.sorted()
					.collect(Collectors.toList());

		Multiset<Integer> beginningsOnTheOtherVenue = new Multiset<>(Integer::compareTo);
		Multiset<Integer> endingsOnTheOtherVenue = new Multiset<>(Integer::compareTo);

		for (Event e : events) {
			if (e.opening) {
				beginningsOnTheOtherVenue.addOne(speakers.get(e.idx).s[1 - intersectingIdx]);
				endingsOnTheOtherVenue.addOne(speakers.get(e.idx).e[1 - intersectingIdx]);

				if (endingsOnTheOtherVenue.size() > 1 &&
						endingsOnTheOtherVenue.smallest() < beginningsOnTheOtherVenue.biggest()) {
					return true;
				}
			} else {
				beginningsOnTheOtherVenue.removeOne(speakers.get(e.idx).s[1 - intersectingIdx]);
				endingsOnTheOtherVenue.removeOne(speakers.get(e.idx).e[1 - intersectingIdx]);
			}
		}

		return false;
	}

	private static class Event implements Comparable<Event> {
		int idx;
		boolean opening;
		int time;

		public Event(int idx, boolean opening, int time) {
			this.idx = idx;
			this.opening = opening;
			this.time = time;
		}

		@Override
		public int compareTo(Event o) {
			return 2 * Integer.compare(time, o.time) - Boolean.compare(opening, o.opening);
		}

		@Override
		public String toString() {
			return "Event{" +
					"idx=" + idx +
					", opening=" + opening +
					", time=" + time +
					'}';
		}
	}

	private static class Speaker {
		int[] s;
		int[] e;

		public Speaker(int[] s, int[] e) {
			this.s = s;
			this.e = e;
		}

		public static Speaker read(FastScanner scanner) {
			int sa = scanner.nextInt();
			int ea = scanner.nextInt();
			int sb = scanner.nextInt();
			int eb = scanner.nextInt();
			return new Speaker(new int[] {sa, sb}, new int[] {ea, eb});
		}

		@Override
		public String toString() {
			return "Speaker{" +
					"s=" + Arrays.toString(s) +
					", e=" + Arrays.toString(e) +
					'}';
		}
	}

	private static class Multiset<T> {

		SortedMap<T, Integer> realMap;
		int in = 0;

		public Multiset(Comparator<T> comparator) {
			this.realMap = new TreeMap<>(comparator);
		}

		void addOne(T elem) {
			in++;
			realMap.put(elem, realMap.getOrDefault(elem, 0) + 1);
		}

		void removeOne(T elem) {
			in--;
			if (realMap.get(elem) == 1) realMap.remove(elem);
			else realMap.put(elem, realMap.get(elem) - 1);
		}

		T smallest() {
			return realMap.firstKey();
		}

		T biggest() {
			return realMap.lastKey();
		}

		public int size() {
			return in;
		}
	}

	static class FastScanner {

		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}
