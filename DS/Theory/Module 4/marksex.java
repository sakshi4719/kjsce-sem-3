import java.util.*;

class Student{
	int marks;
	Student(){
	Scanner sc = new Scanner(System.in);
	marks = sc.nextInt();
	}
}

class MarksOutOfRangeException extends Exception{
	public MarksOutOfRangeException(String str){
	super(str);
	}
}

class TestException{
	static void rangeCheck(int marks) throws MarksOutOfRangeException{
		System.out.println(marks);

		if (marks < 0 || marks > 100){
			throw new MarksOutOfRangeException("marks out of range");}
		else{
			System.out.println("marks entered successfully");}
	}


	public static void main(String args[]){	
		Student s1 = new Student();
		try{rangeCheck(s1.marks);}

		catch(MarksOutOfRangeException e)
			{System.out.println(e);}
	}
}
