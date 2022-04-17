/*
https://www.hackerrank.com/challenges/java-dequeue/problem?isFullScreen=true
*/ 

    import java.util.*;
    import java.math.*;
    
    public class test {
        
        public static int maxUniqueSubarrayWithSet(int n, int m, ArrayList<Integer> array) {
            
            Deque<Integer> deque = new ArrayDeque<>();
            Set<Integer> set = new HashSet<>();
            
            int maxUnique = 1;
             
            for (int i = 0; i < n; i++) {
                
                if (i >= m) {
                    int prev_ele = deque.peekFirst();
                    deque.removeFirst();
                    if (!deque.contains(prev_ele))
                        set.remove(prev_ele);
                }
                
                int new_ele = array.get(i);
                deque.addLast(new_ele);
                set.add(new_ele);
                
                maxUnique = Math.max(maxUnique, set.size());
            }
            
            return maxUnique;
        }
        
        public static int maxUniqueSubarrayWithMap(int n, int m, ArrayList<Integer> array) {
            
            Deque<Integer> deque = new ArrayDeque<>();
            Map<Integer, Integer> freq = new HashMap<>();
            
            int maxUnique = 1;
             
            for (int i = 0; i < n; i++) {
                
                if (i >= m) {
                    int prev_ele = deque.peekFirst();
                    deque.removeFirst();
                    freq.merge(prev_ele, -1, Integer::sum);
                    if (freq.get(prev_ele) == 0)
                        freq.remove(prev_ele);
                }
                
                int new_ele = array.get(i);
                deque.addLast(new_ele);
                if(freq.containsKey(new_ele))
                    freq.merge(new_ele, 1, Integer::sum);
                else
                    freq.put(new_ele, 1);
                
                maxUnique = Math.max(maxUnique, freq.size());
            }
            
            return maxUnique;
        }
        
        public static void main(String[] args) {
            
            Scanner scan = new Scanner(System.in);
            
            ArrayList<Integer> array = new ArrayList<>();
            
            int n = scan.nextInt();
            int m = scan.nextInt();

            for (int i = 0; i < n; i++) {
                array.add(scan.nextInt());
            }
            
            //System.out.println(maxUniqueSubarrayWithSet(n, m, array));
            System.out.println(maxUniqueSubarrayWithMap(n, m, array));
            
            scan.close();
        }
    }

/*
Sample Input

6 3
5 3 5 2 3 2
  
Sample Output

3
*/
