// Create a Package Engineering which has two classes as Student and Marks. Accept (n) student details like roll_no, Subject_name, Student_name,calculate total marks  in the class Student Write display () method to display details and sort () method to sort the students records as per increasing order of the total marks. The function sort must be statically defined to invoke it without referring to any object. Both the functions are written in the Marks class.

// Create a main class which will use a package display all the records of the student in the increasing order of the their total marks.



import engineering.*;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter number of records: ");
		int num = sc.nextInt();
		
		
		
		Student[] stud_list = new Student[num];
		
		for (int i = 0; i < num; i++){
			System.out.println("Enter Roll Number of the Student: ");
			int roll_no = sc.nextInt();
			
			System.out.println("Enter Branch of the Student: ");
			String branch = sc.next();
			
			System.out.println("Enter Name of the Student: ");
			String name = sc.next();
			
			stud_list[i] = new Student(roll_no, branch, name);
		}
		Marks.display(stud_list);
		stud_list = Marks.sort(stud_list);
		System.out.println("\n\nSorted list of students according to their total marks: ");
		
		Marks.display(stud_list);
		
		
	}
}





























