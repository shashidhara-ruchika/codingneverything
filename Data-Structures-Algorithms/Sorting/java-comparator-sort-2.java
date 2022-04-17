/*
https://www.hackerrank.com/challenges/java-sort/problem?isFullScreen=true
*/

import java.util.*;

class StudentComparator implements Comparator<Student> {
    
    @Override
    public int compare(Student s1, Student s2) {
        double diffCGPA = s2.getCgpa() - s1.getCgpa();
        if (diffCGPA == 0D) {
            if (s1.getFname().equals(s2.getFname())) {
                return s1.getId() - s2.getId();
            }
            else {
                return s1.getFname().compareTo(s2.getFname());
            }
        } 
        else {
            return diffCGPA > 0 ? 1 : -1;
        }
    }
    
}

class Student{
	private int id;
	private String fname;
	private double cgpa;
	public Student(int id, String fname, double cgpa) {
		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getId() {
		return id;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
}

//Complete the code
public class Solution
{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCases = Integer.parseInt(scan.nextLine());
		
		List<Student> studentList = new ArrayList<Student>();
		while(testCases>0){
			int id = scan.nextInt();
			String fname = scan.next();
			double cgpa = scan.nextDouble();
			
			Student st = new Student(id, fname, cgpa);
			studentList.add(st);
			
			testCases--;
		}
        
        Collections.sort(studentList, new StudentComparator());
      
      	for(Student st: studentList){
			System.out.println(st.getFname());
		}
        
        scan.close();
	}
}



/*
Sample Input

5
33 Rumpa 3.68
85 Ashis 3.85
56 Samiha 3.75
19 Samara 3.75
22 Fahim 3.76

Sample Output

Ashis
Fahim
Samara
Samiha
Rumpa
*/
