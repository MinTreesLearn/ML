/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

                        Just have Patience + 1...

*/








import javax.management.InstanceNotFoundException;
import javax.swing.*;
import java.util.*;
import java.lang.*;
import java.io.*;


public class Solution {

    static class Boot {
        int left;
        int right;

        Boot(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    static Map<Integer, List<Integer>> leftBootIndexMap;
    static Map<Integer, List<Integer>> rightBootIndexMap;
    static List<Boot> boots = new ArrayList<>();

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        char[] leftBootsColor = sc.next().toCharArray();
        char[] rightBootsColor = sc.next().toCharArray();

        int[] freqLeftBoots = getFreqOfBoots(leftBootsColor, n);
        int[] freqRightBoots = getFreqOfBoots(rightBootsColor, n);

        leftBootIndexMap = getIndexMappingOfBoots(leftBootsColor, n);
        rightBootIndexMap = getIndexMappingOfBoots(rightBootsColor, n);

        int totalPairsOfBoots = findMaxPairOfBoots(freqLeftBoots, freqRightBoots);

        out.println(totalPairsOfBoots);
        for (Boot boot : boots) {
            out.println(boot.left + " " + boot.right);
        }
    }

    private static Map<Integer, List<Integer>> getIndexMappingOfBoots(char[] bootsColor, int n) {
        Map<Integer, List<Integer>> indexMappingOfBoots = new HashMap<>();
        for (int i = 0; i < 27; i++) {
            indexMappingOfBoots.put(i, new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int colorIndex = bootsColor[i] == '?' ? 26 : bootsColor[i] - 'a';
            indexMappingOfBoots.get(colorIndex).add(i + 1);
        }
        return indexMappingOfBoots;
    }

    private static int findMaxPairOfBoots(int[] freqLeftBoots, int[] freqRightBoots) {
        int totalPairsOfBoots = 0, remainingLeftBoots = 0, remainingRightBoots = 0;
        for (int i = 0; i < 26; i++) {
            int matchingPairs = Math.min(freqLeftBoots[i], freqRightBoots[i]);
            totalPairsOfBoots += matchingPairs;

            freqLeftBoots[i] -= matchingPairs;
            freqRightBoots[i] -= matchingPairs;

            addPairsOfBoots(i, i, matchingPairs);

            remainingLeftBoots += freqLeftBoots[i];
            remainingRightBoots += freqRightBoots[i];
        }

        int indefiniteLeftMatches = Math.min(remainingLeftBoots, freqRightBoots[26]);
        int indefiniteRightMatches = Math.min(remainingRightBoots, freqLeftBoots[26]);

        freqLeftBoots[26] -= indefiniteRightMatches;
        freqRightBoots[26] -= indefiniteLeftMatches;

        List<Integer> leftBootsRemaining = getRemainingBoots(leftBootIndexMap);
        for (int i = 0; i < indefiniteLeftMatches; i++) {
            int size = leftBootsRemaining.size();
            int leftBootIndex = leftBootsRemaining.get(size - 1);
            leftBootsRemaining.remove(size - 1);

            size = rightBootIndexMap.get(26).size();
            int rightBootIndex = rightBootIndexMap.get(26).get(size - 1);
            rightBootIndexMap.get(26).remove(size - 1);
            boots.add(new Boot(leftBootIndex, rightBootIndex));
        }

        List<Integer> rightBootsRemaining = getRemainingBoots(rightBootIndexMap);
        for (int i = 0; i < indefiniteRightMatches; i++) {
            int size = leftBootIndexMap.get(26).size();
            int leftBootIndex = leftBootIndexMap.get(26).get(size - 1);
            leftBootIndexMap.get(26).remove(size - 1);

            size = rightBootsRemaining.size();
            int rightBootIndex = rightBootsRemaining.get(size - 1);
            rightBootsRemaining.remove(size - 1);

            boots.add(new Boot(leftBootIndex, rightBootIndex));
        }

        totalPairsOfBoots += indefiniteLeftMatches + indefiniteRightMatches;

        int bothIndefinite = Math.min(freqLeftBoots[26], freqRightBoots[26]);
        addPairsOfBoots(26, 26, bothIndefinite);
        totalPairsOfBoots += bothIndefinite;

        return totalPairsOfBoots;
    }

    private static List<Integer> getRemainingBoots(Map<Integer, List<Integer>> bootIndexMap) {
        List<Integer> remaining = new ArrayList<>();
        for (int color : bootIndexMap.keySet()) {
            if (color == 26) {
                continue;
            }
            remaining.addAll(bootIndexMap.get(color));
        }
        return remaining;
    }

    private static void addPairsOfBoots(int leftColor, int rightColor, int matchingPairs) {
        for (int i = 0; i < matchingPairs; i++) {
            int size = leftBootIndexMap.get(leftColor).size();
            int leftBootIndex = leftBootIndexMap.get(leftColor).get(size - 1);
            leftBootIndexMap.get(leftColor).remove(size - 1);

            size = rightBootIndexMap.get(rightColor).size();
            int rightBootIndex = rightBootIndexMap.get(rightColor).get(size - 1);
            rightBootIndexMap.get(rightColor).remove(size - 1);

            boots.add(new Boot(leftBootIndex, rightBootIndex));
        }
    }

    private static int[] getFreqOfBoots(char[] bootsColor, int n) {
        int[] freq = new int[27];
        for (int i = 0; i < n; i++) {
            if (bootsColor[i] == '?') {
                freq[26]++;
            }else {
                freq[bootsColor[i] - 'a']++;
            }
        }
        return freq;
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer str;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (str == null || !str.hasMoreElements())
            {
                try
                {
                    str = new StringTokenizer(br.readLine());
                }
                catch (IOException  lastMonthOfVacation)
                {
                    lastMonthOfVacation.printStackTrace();
                }
            }
            return str.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException lastMonthOfVacation)
            {
                lastMonthOfVacation.printStackTrace();
            }
            return str;
        }
    }

}