package engineering;

public class Marks{
	public static void display(Student[] students){
		for (Student student : students){
			System.out.println("##########################################");
			System.out.println("Roll Number: " + student.roll_no);
			System.out.println("Student name: " + student.student_name);
			System.out.println("Branch: " + student.subject_name);
			System.out.println("Marks in Subject 1: " + student.marks[0]);
			System.out.println("Marks in Subject 2: " + student.marks[1]);
			System.out.println("Marks in Subject 3: " + student.marks[2]);
			System.out.println("Total Marks: " + student.total_marks);
		}
	}
	
	public static Student[] sort(Student[] students){
		int length = students.length;
		System.out.println(length);
		for(int i = 0; i < (length - 1); i++){
			int min = i;
			System.out.println("???");
			for(int j = (i + 1); j < length; j++){
				System.out.println(i +"\t"+ j);
				//System.out.println("%%%");
				if(students[min].total_marks > students[j].total_marks)
					//System.out.println("^^^");
					j = min;
			}
			System.out.println("!!!");
			if(min != i){
				Student temp = students[i];
				students[i] = students[min];
				students[min] = temp; 
			}
		}
		
		return students;
	}
}
