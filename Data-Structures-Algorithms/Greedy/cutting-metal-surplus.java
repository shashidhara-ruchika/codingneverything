// https://gist.github.com/marcogalluzzi/38148f1b9e6cb4fde70d486fc3597708

import java.util.*;

// not an optimal solution

public class Solution {

    public int cuttingMetalSurplus(int costPerCut, int salePrice, List<Integer> lengths) {

        int maxProfit = 0;
        int maxLength = Collections.max(lengths);

        for (int saleLength = 1; saleLength < maxLength; saleLength++) {

            int salePricePerRod = salePrice * saleLength;
            int currentProfit = 0;

            for (int rodLength : lengths) {
                int uniformRods = rodLength / saleLength;

                if (uniformRods > 0) {
                    int extraCut = (rodLength % saleLength > 0) ? 1 : 0;
                    int totalCuts = uniformRods - 1 + extraCut;

                    int currentCost = totalCuts * costPerCut;
                    int revenue = uniformRods * salePricePerRod;

                    if (revenue > currentCost) {
                        currentProfit += revenue - currentCost;
                    }
                }
            }

            maxProfit = Math.max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
}