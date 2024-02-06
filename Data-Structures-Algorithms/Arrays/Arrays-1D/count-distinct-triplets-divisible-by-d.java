import java.util.*;

class Solution {

// O (n ^ 3)
public static int CountTriplets4(int d, List<Integer> b)
{
    int n = b.size();
    var a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = b.get(i) % d;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        var ai = a[i];
        for (int j = i + 1; j < n; j++)
        {
            var aij = ai + a[j];
            if (aij >= d)
                aij -= d;
            var neededForK = aij > 0
                ? d - aij
                : 0;
            for (int k = j + 1; k < n; k++)
                if (a[k] == neededForK)
                    count++;
        }
    }
    return count;
}

// O (n)
public static int countTriplets(int d, List<Integer> a) {
    int count = 0;
    int n = a.size();
    HashMap<Integer, Integer> remainderCount = new HashMap<>();

    // Count remainders and store in a map
    for (int i = 0; i < n; i++) {
        int remainder = a.get(i) % d;

        remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
    }

    // Count triplets with the required remainder
    for (int i = 0; i < n; i++) {
        int remainder = a.get(i) % d;
        int neededRemainder = (d - remainder) % d;

        if (remainderCount.containsKey(neededRemainder)) {
            count += remainderCount.get(neededRemainder);
        }
        if (neededRemainder == remainder) {
            count--;
        }
    }

    return count / 3;
}

// O (n ^ 2)
public static int countThreeSum(List<Integer> values, int d, int e) {
    int count = 0;
    int[] valuesCount = new int[e];

    for (int i = 0; i < values.size(); i++) {
        for (int j = i + 1; j < values.size(); j++) {
            count += valuesCount[(d - values.get(i) - values.get(j)) % e];
        }
        valuesCount[values.get(i) % e]++;
    }

    return count;
}

}