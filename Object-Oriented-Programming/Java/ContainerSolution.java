import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class ContainerSolution {

    String[] solution(String[][] queries) {

        Soln solve = new Soln();

        String[] result = new String[queries.length];
        int i = 0;

        for (String[] query : queries) {
            if ("ADD".equals(query[0])) {
                solve.add(Integer.parseInt(query[1]));
                result[i] = "";
            } else if ("EXISTS".equals(query[0])) {
                result[i] = solve.exists(Integer.parseInt(query[1])).toString();
            } else if ("REMOVE".equals(query[0])) {
                result[i] = solve.remove(Integer.parseInt(query[1])).toString();
                // result[i] = "";
            } else if ("GET_NEXT".equals(query[0])) {
                Integer res = solve.getNext(Integer.parseInt(query[1]));
                if (res == null) {
                    result[i] = "";
                } else {
                    result[i] = res.toString();
                }

            } else {

            }
            i++;
        }

        return result;

    }

    class Soln {
        LinkedList<Integer> ll;

        Soln() {
            ll = new LinkedList<>();
        }

        public void add(int n) {
            int i = 0;

            while (i < ll.size() && ll.get(i) < n) {
                i++;
            }

            ll.add(i, n);
        }

        public Boolean exists(int n) {
            return ll.contains(n);
        }

        public Boolean remove(int n) {
            boolean val = ll.remove((Integer) n);
            return val;
        }

        public Integer getNext(int n) {
            int i = 0;

            while (i < ll.size() && ll.get(i) <= n) {
                i++;
            }

            if (i >= ll.size()) {
                return null;
            }
            return ll.get(i);
        }
    }

    class Soln2 {
        Set<Integer> set;
        Map<Integer, Integer> freq;

        LinkedList<Integer> ll;

        Soln2() {
            set = new HashSet<>();
            freq = new HashMap<>();

        }

        public void add(int n) {
            if (set.contains(n)) {
                freq.put(n, freq.get(n) + 1);
            } else {
                set.add(n);
                freq.put(n, 1);
            }
        }

        public Boolean exists(int n) {
            return set.contains(n);
        }

        public Boolean remove(int n) {

            if (set.contains(n)) {
                // System.out.println(freq.get(n));
                if (freq.get(n) == 1) {
                    freq.remove(n);
                    set.remove(n);
                } else {
                    freq.put(n, freq.get(n) - 1);
                }
                return true;
            } else {
                return false;
            }
        }

        public Integer getNext(int n) {
            List<Integer> list = new ArrayList<>();

            for (int s : set) {
                for (int i = 0; i < freq.get(s); i++) {
                    list.add(s);
                }
            }

            list = list.stream().sorted().collect(Collectors.toList());

            int i = list.lastIndexOf(n);

            if (i == list.size() - 1) {
                return null;
            } else {
                return list.get(i + 1);
            }
        }
    }

}
