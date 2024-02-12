// https://www.metacareers.com/profile/coding_practice_question/?problem_id=313591923957227&psid=600891527799620&practice_plan=0&p=DATA_ENG&b=0121222

import java.io.*; 
import java.util.*;
// Add any extra import statements you may need here


class Main {

  // Add any helper functions you may need here
  

  static String returnSmallestKey(HashMap<String, Integer> inputDict, int n)  {
    // Write your code here
    if (n > inputDict.size() || n == 0) {
      return null;
    }
    
    // Create a PriorityQueue
    PriorityQueue<Map.Entry<String, Integer>> priorityQueue = new PriorityQueue<>(
      (a, b) -> {
          if (a.getValue() == b.getValue()) {
            return (a.getKey()).compareTo(b.getKey());
          }
          return a.getValue() - b.getValue();
        }
    );

    // Insert elements from the HashMap into the PriorityQueue
    for (Map.Entry<String, Integer> entry : inputDict.entrySet()) {
        priorityQueue.offer(entry);
    }

    // Retrieve and print elements from the PriorityQueue
    int i = 0;
    Map.Entry<String, Integer> entry = null;
    while (i < n) {
        entry = priorityQueue.poll();
        i++;
    }
    
    return entry.getKey();
  }







  // These are the tests we use to determine if the solution is correct.
  // You can add your own at the bottom.
  int test_case_number = 1;
  void check(String expected, String output) {
    boolean result = (expected == output);
    char rightTick = '\u2713';
    char wrongTick = '\u2717';
    if (result) {
      System.out.println(rightTick + " Test #" + test_case_number);
    }
    else {
      System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
      printString(expected); 
      System.out.print(" Your output: ");
      printString(output);
      System.out.println();
    }
    test_case_number++;
  }
  void printString(String n) {
    System.out.print("[" + n + "]");
  }
  public void run() throws IOException {
  
    // Testcase 1 
    HashMap<String, Integer> inputDict1 = new HashMap<String, Integer>() {{ 
      put("laptop", 999); 
      put("smartphone", 999); 
      put("smart tv", 500);
      put("smart watch", 300);
      put("smart home", 9999999);
      }};
    int n1 = 2;
    String expected_1 = "smart tv";
    String output_1 = returnSmallestKey(inputDict1, n1);
    check(expected_1, output_1);

    // Testcase 2
    HashMap<String, Integer> inputDict2 = new HashMap<String, Integer>() {{
      put("a", 10);
      put("b", 20);
    }};
    int n2 = 0;
    String expected_2 = null;
    String output_2 = returnSmallestKey(inputDict2, n2);
    check(expected_2, output_2);


    // Testcase 3
    HashMap<String, Integer> inputDict3 =  new HashMap<String, Integer>() {{
      put("a", 1);
      put("b", 2);
      put("c", 3);
      put("d", 4);
      put("e", 5);
    }};
    int n3 = 6;
    String expected_3 = null;
    String output_3 = returnSmallestKey(inputDict3, n3);
    check(expected_3, output_3);
 
 
    // Testcase 4
    HashMap<String, Integer> inputDict4 = new HashMap<String, Integer>() {{
      put("a", 10);
      put("b", 20);
      put("c", 3);
      put("d", 2); 
      put("e", 9);
    }};
    int n4 = 1;
    String expected_4 = "d";
    String output_4 = returnSmallestKey(inputDict4, n4);
    check(expected_4, output_4);

        
   // Add your own test cases here
   
    
  }
  public static void main(String[] args) throws IOException {
    new Main().run();
  }
}