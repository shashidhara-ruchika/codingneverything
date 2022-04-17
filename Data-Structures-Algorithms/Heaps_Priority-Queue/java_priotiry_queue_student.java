/*
https://www.hackerrank.com/challenges/java-priority-queue/problem?isFullScreen=true
*/

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.*;
/*
 * Create the Student and Priorities classes here.
 */
 
class Student implements Comparable<Student> {
        int id;
        String name;
        double cgpa;
        
    Student(int id, String name, double cgpa) {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }
    
    public int getID() {
        return this.id;
    }
    
    public String getName() {
        return this.name;
    }
    
    public double getCGPA() {
        return this.getCGPA();
    }
    
    @Override
    public int compareTo(Student student) {
        double diffCGPA = student.cgpa - this.cgpa;
        if (diffCGPA == 0D) {
            if (student.name.equals(this.name)) {
                return student.id - this.id;
            } 
            else {
                return this.name.compareTo(student.name);
            }
        } 
        else {
            return diffCGPA < 0 ? -1 : 1;
        }
    }
    
};

class Priorities {
    public List<Student> getStudents(List<String> events) {
        
        PriorityQueue<Student> pq = new PriorityQueue<Student>();
        String[] eventDescription;
        List<Student> remainingStudents = new ArrayList<Student>();
        
        for(String event : events) {
            eventDescription = event.split(" ");
            if (eventDescription[0].equals("ENTER")) {
                pq.add(
                    new Student(
                        Integer.parseInt(eventDescription[3]), 
                        eventDescription[1], 
                        Double.parseDouble(eventDescription[2])
                    )
                );   
            }
            else {
                pq.poll();
            }
        }
        
        while(!pq.isEmpty()) {
            remainingStudents.add(pq.poll());
        }
        
        return remainingStudents;
        
    }
};


public class Solution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}

/*
Sample Input 0

12
ENTER John 3.75 50
ENTER Mark 3.8 24
ENTER Shafaet 3.7 35
SERVED
SERVED
ENTER Samiha 3.85 36
SERVED
ENTER Ashley 3.9 42
ENTER Maria 3.6 46
ENTER Anik 3.95 49
ENTER Dan 3.95 50
SERVED
Sample Output 0

Dan
Ashley
Shafaet
Maria
*/
