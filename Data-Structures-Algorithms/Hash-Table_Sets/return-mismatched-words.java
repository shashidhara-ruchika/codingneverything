// https://www.metacareers.com/profile/coding_practice_question/?problem_id=297209572413814&psid=600891527799620&practice_plan=0&p=DATA_ENG&b=0121222

import java.io.*; 
import java.util.*;
// Add any extra import statements you may need here


class Main {

  // Add any helper functions you may need here
  

  String[] returnMismatchedWords(String str1, String str2) {
    // Write your code here
    List<String> mismatched = new ArrayList<>();
    
    
    
    Set<String> set = new HashSet<>();
    
    String[] str1list = str1.split(" ");
    String[] str2list = str2.split(" ");
    
    for (String s : str1list) {
      set.add(s);
    }
    
    for (String s : str2list) {
      if (set.contains(s)) {
        set.remove(s);
      } else {
        set.add(s);
      }
    }
     
    List<String> soln = new ArrayList<>();
         
         
    for (String s : str1list) {
      if (set.contains(s)) {
        soln.add(s);
      }
    }
         
    for (String s : str2list) {
      if (set.contains(s)) {
        soln.add(s);
      }
    }
         
    return soln.toArray(new String[0]);
     
  }







 
  // These are the tests we use to determine if the solution is correct.
  // You can add your own at the bottom.
  int test_case_number = 1;
  void check(String[] expected, String[] output) {
    int expected_size = expected.length; 
    int output_size = output.length; 
    boolean result = true; 
    if (expected_size != output_size) {
      result = false;
    }
    for (int i = 0; i < Math.min(expected_size, output_size); i++) {
      result &= (output[i].equals(expected[i]));
    }
    char rightTick = '\u2713';
    char wrongTick = '\u2717';
    if (result) {
      System.out.println(rightTick + " Test #" + test_case_number);  
    }
    else {
      System.out.print(wrongTick + " Test #" + test_case_number + ": Expected ");
      System.out.println(Arrays.toString(expected)); 
      System.out.print(" Your output: ");
      System.out.println(Arrays.toString(output)); 
      System.out.println();
    }
    test_case_number++;
  }
  public void run() throws IOException {
    Scanner sc = new Scanner(System.in);
    
    // Test Case 1
    String str1 = "Firstly this is the first string";
    String str2 = "Next is the second string";
    String[] expected_1 = {"Firstly", "this", "first", "Next", "second"};
    String[] output_1 = returnMismatchedWords(str1, str2);
    check(expected_1, output_1);
    

    // Test Case 2
    String str3 = "This is the first string extra";
    String str4 = "This is the second string";
    String[] expected_2 = {"first", "extra", "second"};
    String[] output_2 = returnMismatchedWords(str3, str4);
    check(expected_2, output_2);

  
    // Test Case 3
    String str5 = "This is the first text";
    String str6 = "This is the second string";
    String[] expected_3 = {"first", "text", "second", "string"};
    String[] output_3 = returnMismatchedWords(str5, str6);
    check(expected_3, output_3);
    
    // Add your own test cases here
    
  }
  public static void main(String[] args) throws IOException {
    new Main().run();
  }
}