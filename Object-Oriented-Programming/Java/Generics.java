/*
https://www.hackerrank.com/challenges/java-generics/problem?isFullScreen=true
*/


import java.io.IOException;
import java.lang.reflect.Method;

// prints array of any generic type
class Printer
{
   //Write your code here
   
   public <T> void printArray(T[] TArray) {
       for(T element : TArray)
            System.out.println(element);
   }
 
}

public class Solution {


    public static void main( String args[] ) {
        Printer myPrinter = new Printer();
        Integer[] intArray = { 1, 2, 3 };
        String[] stringArray = {"Hello", "World"};
        myPrinter.printArray(intArray);
        myPrinter.printArray(stringArray);
        int count = 0;

        for (Method method : Printer.class.getDeclaredMethods()) {
            String name = method.getName();

            if(name.equals("printArray"))
                count++;
        }

        if(count > 1)System.out.println("Method overloading is not allowed!");
      
    }
}
