// Translation of the cpp solution by Alexander Cai
// Solved

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner br = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int nPeople;
        int maxWithdrawal;
        int nCases = br.nextInt();

        for (int t = 1; t <= nCases; ++t) {
            nPeople = br.nextInt();
            maxWithdrawal = br.nextInt();
            Pair[] people = new Pair[nPeople];

            for (int i = 0; i < nPeople; ++i) {
                int money = br.nextInt();
                people[i] = new Pair((money - 1) / maxWithdrawal, i);
            }
            Arrays.sort(people);

            System.out.printf("Case #%d:", t);
            for (int i = 0; i < nPeople; ++i)
                System.out.printf(" %d", people[i].second + 1);
            System.out.println();
        }
    }

    public static class Pair implements Comparable<Pair> {
        private int first;
        private int second;

        public Pair(int a, int b) {
            first = a;
            second = b;
        }

        @Override
        public int compareTo(Pair other) {
            if (other.first != this.first)
                return this.first - other.first;
            if (other.second != this.second)
                return this.second - other.second;
            return 0;
        }
    }
}
