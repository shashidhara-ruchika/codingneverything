// https://www.metacareers.com/profile/coding_practice_question/?problem_id=720422605157879&psid=275492097255885&practice_plan=0&p=GENERAL_SWE&b=0011122

import java.io.*; 
import java.util.*;
// Add any extra import statements you may need here


class Main {

  class Sides{
    int a;
    int b;
    int c;
    Sides(int a,int b,int c){
      this.a = a;
      this.b = b;
      this.c = c; 
    }
    
    
    public int getA() {
      return a;
    }
    
    
    public int getB() {
      return b;
    }
    
    
    public int getC() {
      return c;
    }
    
     @Override
      public int hashCode() {
        int[] tArr = {a, b, c};
        Arrays.sort(tArr);
          return Objects.hash(tArr[0], tArr[1], tArr[2]);
      }
    
    @Override
    public boolean equals(Object obj) {
      
      if (obj == this) {
        return true;
    }
    if (!(obj instanceof Sides)) {
        return false;
    }
    Sides otherSides = (Sides) obj;

    int[] tArr = {a, b, c};
    int[] oArr = {otherSides.getA(), otherSides.getB(), otherSides.getC()};

    Arrays.sort(tArr);
    Arrays.sort(oArr);
      

    return Arrays.equals(tArr, oArr);
    }
  }
  
 
  
  // Add any helper functions you may need here
  
  
  int countDistinctTriangles(ArrayList<Sides> arr) {
    // Write your code here
    Set<Sides> set = new HashSet<Sides>();
    
    for (Sides s : arr) {
      
      set.add(s);
    }
    
    return set.size();
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
    ArrayList<Sides> arr_1 = new ArrayList<>();
    arr_1.add(new Sides(7, 6, 5));
    arr_1.add(new Sides(5, 7, 6));
    arr_1.add(new Sides(8, 2, 9));
    arr_1.add(new Sides(2, 3, 4));
    arr_1.add(new Sides(2, 4, 3));
    int expected_1 = 3;
    int output_1 = countDistinctTriangles(arr_1);
    check(expected_1, output_1);

    ArrayList<Sides> arr_2 = new ArrayList<>();
    arr_2.add(new Sides(3, 4, 5));
    arr_2.add(new Sides(8, 8, 9));
    arr_2.add(new Sides(7, 7, 7));
    int expected_2 = 3;
    int output_2 = countDistinctTriangles(arr_2);
    check(expected_2, output_2);
    
    // Add your own test cases here
    
  }
  
  public static void main(String[] args) {
    new Main().run();
  }
}