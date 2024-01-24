// https://www.metacareers.com/profile/coding_practice_question/?problem_id=840934449713537&psid=275492097255885&practice_plan=0&p=GENERAL_SWE&b=0111122

import java.io.*; 
import java.util.*;
// Add any extra import statements you may need here


class Main {

  // Add any helper functions you may need here
  

  int numberOfWays(int[] arr, int k) {
    // Write your code here
    
    Map<Integer, Integer> freq = new HashMap<>();
    
    for (int a : arr) {
      if (freq.containsKey(a)) {
        freq.put(a, freq.get(a) + 1);
      } else {
        freq.put(a, 1);
      }
    }
    
    int count = 0;
    int dup_count = 0;
    
    if (k % 2 == 0) {
      if (freq.containsKey(k / 2)) {
        int v = freq.get(k / 2);
        dup_count += v * (v - 1)/ 2;
        freq.remove(k / 2);
      }
    }
    
    for (int a : arr) {
      if (freq.containsKey(k - a)) {
        count++;
      }
    }
    
    count = count / 2 + dup_count;
    return count;
    
  }











  // These are the tests we use to determine if the solution is correct.
  // You can add your own at the bottom.
  int test_case_number = 1;
  
  void check(int expected, int output) {
    boolean result = (expected == output);
    char rightTick = '\u2713';
    char wrongTick = '\u2717';
    if (result) {
      System.out.println(rightTick + " Test #" + test_case_number);
    }
    else {
      System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
      printInteger(expected); 
      System.out.print(" Your output: ");
      printInteger(output);
      System.out.println();
    }
    test_case_number++;
  }
  
  void printInteger(int n) {
    System.out.print("[" + n + "]");
  }
  
  public void run() {
    int k_1 = 6;
    int[] arr_1 = {1, 2, 3, 4, 3};
    int expected_1 = 2;
    int output_1 = numberOfWays(arr_1, k_1);
    check(expected_1, output_1);

    int k_2 = 6;
    int[] arr_2 = {1, 5, 3, 3, 3};
    int expected_2 = 4;
    int output_2 = numberOfWays(arr_2, k_2);
    check(expected_2, output_2);

    // Add your own test cases here
    
  }
  public static void main(String[] args) {
    new Main().run();
  }
}