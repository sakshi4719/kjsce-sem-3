package engineering;

import java.util.Scanner;


public class Student{
	int roll_no;
	String subject_name;
	String student_name;
	int[] marks = new int[3];
	int total_marks;
	
	public Student(int roll_no, String branch, String name){
		this.roll_no = roll_no;
		subject_name = branch;
		student_name = name;
		this.get_marks();
		this.get_total_marks();
	}
	
	void get_marks(){
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter Marks in Subject 1: ");
		marks[0] = scan.nextInt();
		
		System.out.println("Enter Marks in Subject 2: ");
		marks[1] = scan.nextInt();
		
		System.out.println("Enter Marks in Subject 3: ");
		marks[2] = scan.nextInt();

	}
	
	void get_total_marks(){
		for(int i = 0; i < 3; i++){
			total_marks += marks[i];
		}
	}
}
