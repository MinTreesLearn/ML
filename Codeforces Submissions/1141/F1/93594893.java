//package codeforces_464_div2;

import java.util.*;
import java.util.stream.Collectors;

public class F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        int[][] sub = new int[n][n];
        for (int i = 0; i < n; i++) {
            sub[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                sub[i][j] = sub[i][j - 1] + arr[j];
            }
        }

        HashMap<Integer, List<P>> hm = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (hm.containsKey(sub[i][j])) {
                    hm.get(sub[i][j]).add(new P(i, j));
                } else {
                    List<P> temp = new ArrayList<>();
                    temp.add(new P(i, j));
                    hm.put(sub[i][j], temp);
                }
            }
        }

        int ans = Integer.MIN_VALUE;
        /*for(Map.Entry it : hm.entrySet()) {
            int or = overlap(it.getValue());
            ans = Math.max(ans, or);
        }*/

        List<P> ansList = null;
        for (List<P> it : hm.values()) {
            int or = overlap(it);
            if(or>ans) {
                ans = or;
                ansList = it;
            }
        }

        List<P> processedList = extractOverlapping(ansList);

        System.out.println(ans);
        for(int i=0; i<processedList.size(); i++) {
            int A = processedList.get(i).a + 1;
            int B = processedList.get(i).b + 1;
            System.out.println(A + " " + B);
        }
    }

    public static int overlap(List<P> listOfPair) {
        List<P> sortedList = listOfPair.stream()
                .sorted((pair1, pair2) -> pair1.getB().compareTo(pair2.getB()))
                .collect(Collectors.toList());

        int cnt = 0;
        int end = sortedList.get(0).b;
        for (int i = 1; i < sortedList.size(); i++) {
            if (sortedList.get(i).a <= end) {
                cnt++;
            } else {
                end = sortedList.get(i).b;
            }
        }

        return sortedList.size() - cnt;
    }

    public static List<P> extractOverlapping(List<P> ansList) {
        List<P> sortedList = ansList.stream()
                .sorted((pair1, pair2) -> pair1.getB().compareTo(pair2.getB()))
                .collect(Collectors.toList());

        List<P> finalList = new ArrayList<>();
        finalList.add(sortedList.get(0));
        int end = sortedList.get(0).b;
        for (int i = 1; i < sortedList.size(); i++) {
            if (sortedList.get(i).a <= end) {
                continue;
            } else {
                finalList.add(sortedList.get(i));
                end = sortedList.get(i).b;
            }
        }

        return finalList;
    }
}

class P implements Comparable<P> {
    Integer a;
    Integer b;

    public P(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public Integer getA() {
        return a;
    }

    public Integer getB() {
        return b;
    }

    @Override
    public int compareTo(P that) {
        return this.b.compareTo(that.b);
    }
}
