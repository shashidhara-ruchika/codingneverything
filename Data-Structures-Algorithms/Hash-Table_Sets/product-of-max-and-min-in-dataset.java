// https://github.com/josergc/min-max-product

import java.util.*;

public class Solution {
    public List<Long> solution(List<String> operations, List<Integer> x) {
        List<Long> productArray = new ArrayList<>();
        TreeSet<Long> dataset = new TreeSet<>();

        Long minVal = (long)x.get(0);
        Long maxVal = (long)x.get(0);

        for (int i = 1; i < x.size(); i++) {
            String operation = operations.get(i);
            Long xVal = (long)x.get(i);

            if ("push".equals(operation)) {
                dataset.add(xVal);
                minVal = Math.min(minVal, xVal);
                maxVal = Math.max(maxVal, xVal);

                

            } else if ("pop".equals(operation)) {
                dataset.remove(xVal);
                minVal = dataset.first();
                maxVal = dataset.last();
            }

            productArray.add(((maxVal * minVal)));
        }

        return productArray;

    } 
}

