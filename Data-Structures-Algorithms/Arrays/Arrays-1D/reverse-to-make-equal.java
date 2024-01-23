// https://www.metacareers.com/profile/coding_practice_question/?problem_id=2869293499822992&psid=275492097255885&practice_plan=0&p=GENERAL_SWE&b=0111122

import java.io.*; 
import java.util.*;
// Add any extra import statements you may need here


class Main {

  // Add any helper functions you may need here
  

  boolean areTheyEqual(int[] array_a, int[] array_b) {
    // Write your code here
    Map<Integer, Integer> freq = new HashMap<Integer, Integer>();
    for (int i = 0; i < array_a.length; i++) {
      if (!freq.containsKey(array_a[i])) {
       freq.put(array_a[i], 1); 
      } else {
        freq.put(array_a[i], freq.get(array_a[i]) + 1); 
      }
      if (!freq.containsKey(array_b[i])) {
       freq.put(array_b[i], -1); 
      } else {
        freq.put(array_b[i], freq.get(array_b[i])-1); 
      }
    }
    
    for (int v : freq.values()) {
      if (v != 0) {
        return false;
      }
    }
    return true;
    
  }











  // These are the tests we use to determine if the solution is correct.
  // You can add your own at the bottom.
  int test_case_number = 1;
  void check(boolean expected, boolean output) {
    boolean result = (expected == output);
    char rightTick = '\u2713';
    char wrongTick = '\u2717';
    if (result) {
      System.out.println(rightTick + " Test #" + test_case_number);
    }
    else {
      System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
      System.out.print(expected); 
      System.out.print(" Your output: ");
      System.out.print(output);
      System.out.println();
    }
    test_case_number++;
  }
  
  public void run() {
    int[] array_a_1 = {1, 2, 3, 4};
    int[] array_b_1 = {1, 4, 3, 2};
    boolean expected_1 = true;
    boolean output_1 = areTheyEqual(array_a_1, array_b_1); 
    check(expected_1, output_1); 

    int[] array_a_2 = {1, 2, 3, 4};
    int[] array_b_2 = {1, 4, 3, 3};
    boolean expected_2 = false;
    boolean output_2 = areTheyEqual(array_a_2, array_b_2); 
    check(expected_2, output_2); 
    // Add your own test cases here
    
  }
  
  public static void main(String[] args) {
    new Main().run();
  }
}