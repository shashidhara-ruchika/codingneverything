/*
https://www.hackerrank.com/challenges/java-reflection-attributes/problem?isFullScreen=true
*/

public class Solution {

        public static void main(String[] args){
//             Class student = ~~~Complete this line~~~;
//             Method[] methods = ~~~Complete this line~~~;

//             ArrayList<String> methodList = new ArrayList<>();
//             for(~~~Complete this line~~~){
//                 methodList.add(~~~Complete this line~~~);
//             }
//             Collections.sort(methodList);
//             for(String name: methodList){
//                 System.out.println(name);
//             }
            
            Class student = Student.class;
            Method[] methods = student.getDeclaredMethods();

            ArrayList<String> methodList = new ArrayList<>();
            for(Method m : methods){
                methodList.add(m.getName());
            }
            Collections.sort(methodList);
            for(String name: methodList){
                System.out.println(name);
            }
        }

    }
