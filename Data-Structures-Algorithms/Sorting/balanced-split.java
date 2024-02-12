// https://www.metacareers.com/profile/coding_practice_question/?problem_id=226994905008716&psid=275492097255885&practice_plan=0&p=GENERAL_SWE&b=0011122

import java.io.*; 
import java.util.*;
// Add any extra import statements you may need here


class Main {

  // Add any helper functions you may need here
  

  boolean balancedSplitExists(int[] arr) {
    // Write your code here
    
    Arrays.sort(arr);
    
    int n = arr.length;
    
    int[] lSum = new int[n];
    lSum[0] = arr[0];
    
    int[] rSum = new int[n];
    rSum[n - 1] = arr[n - 1];
    
    for (int i = 1; i < n; i++) {
      lSum[i] = lSum[i - 1] + arr[i];
      rSum[n - i - 1] = rSum[n - i] + arr[n - i - 1];
    }
    
    for (int i = 1; i < n; i++) {
      if (lSum[i - 1] == rSum[i] && arr[i - 1] < arr[i]) {
        return true;
      }
    }
    
    return false;
    
    
    
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
  void printString(String str) {
    System.out.print("[" + str + "]");
  }
  
  public void run() {
    int arr_1[] = {2, 1, 2, 5};
    boolean expected_1 = true;
    boolean output_1 = balancedSplitExists(arr_1); 
    check(expected_1, output_1); 

    int arr_2[] = {3, 6, 3, 4, 4};
    boolean expected_2 = false;
    boolean output_2 = balancedSplitExists(arr_2); 
    check(expected_2, output_2); 
    
    // Add your own test cases here
    
  }
  
  public static void main(String[] args) {
    new Main().run();
  }
}
