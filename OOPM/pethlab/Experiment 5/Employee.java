/*
Create a class Employee which stores E-Name, E-Id and E-Salary of an Employee. Use class Vector to maintain an array of Employee with respect to the E-Salary. 

Provide the following functions
1) Create (): this function will accept the n Employee records in any order and will arrange them in the sorted order.
2) Insert (): to insert the given Employee record at appropriate index in the vector depending upon the E-Salary.
3) delete ByE-name( ): to accept the name of the Employee  and delete the record having given name
4) deleteByE-Id ( ): to accept the Id of the Employee and delete the record having given E-Id.


Provide the following functions
--> boolean add(E e) : This method appends the specified element to the end of this Vector.
--> void addElement(E obj) This method adds the specified component to the end of this vector, increasing its size by one.
--> int lastIndexOf(Object o, int index) This method returns the index of the last occurrence of the specified element in this vector, searching backwards from index, or returns -1 if the element is not found.
--> void removeElementAt(int index)This method deletes the component at the specified index.

*/

import java.util.*;

public class Employee{
	String e_name;
	int e_id;
	int e_salary;
	
	
	Employee(String name, int id, int salary){
		e_name = name;
		e_id = id;
		e_salary = salary;
	}
	
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Input the number of employee records to be added upto creation: ");
		int num = Integer.parseInt(sc.nextLine());
		Vector<Employee> e_vec = Employee.create(num);
		
		Employee.sort_vector(e_vec);
		
		for (int i = 0; i < e_vec.size(); i++)
            System.out.print(e_vec.get(i).e_name + " ");
        
        
		System.out.println("\n###\nInput the details of a new employee:");
        System.out.println("Enter their name: ");
		String name = sc.nextLine();			
			
		System.out.println("Enter their ID number: ");
		int id = Integer.parseInt(sc.nextLine());
		
		System.out.println("Enter their Salary: ");
		int salary = Integer.parseInt(sc.nextLine());
		
		Employee e = new Employee(name, id, salary);
		
		Employee.insert(e_vec, e);
		
		for (int i = 0; i < e_vec.size(); i++)
            System.out.print(e_vec.get(i).e_name + " ");
		
		System.out.println("Input name of employee to delete their record: ");
        String name_to_del = sc.nextLine();
        System.out.println(Employee.delete_by_name(e_vec, name_to_del));
        for (int i = 0; i < e_vec.size(); i++)
            System.out.print(e_vec.get(i).e_name + " ");
        
        System.out.println("Input ID of employee to delete their record: ");
        int id_to_del = Integer.parseInt(sc.nextLine());
        System.out.println(Employee.delete_by_id(e_vec, id_to_del));
        for (int i = 0; i < e_vec.size(); i++)
            System.out.print(e_vec.get(i).e_name + " ");
        
	}
	
	
	static Vector create(int num){
		Scanner sc = new Scanner(System.in);
		Vector<Employee> employees = new Vector<Employee>(num);
 
        for (int i = 1; i <= num; i++){
        	System.out.println("\n###");
        	
        	
        	System.out.println("Employee " + i + "'s records: ");
        	       	
        	System.out.println("Enter their name: ");
			String name = sc.nextLine();			
			
			System.out.println("Enter their ID number: ");
			int id = Integer.parseInt(sc.nextLine());
			
			System.out.println("Enter their Salary: ");
			int salary = Integer.parseInt(sc.nextLine());
			
			Employee e = new Employee(name, id, salary);
			
			employees.add(e);
            
            System.out.println("###");
            
            
            
        }
        
        return employees;
	}
	
	
	static Vector insert(Vector<Employee> v, Employee e){
		for (int i = 0; i < v.size(); i++){
			if(v.get(i).e_salary > e.e_salary){
				v.insertElementAt(e, i);
				return v;
			}
		}
		v.add(e);
		return v;
	}
	
	
	static String delete_by_name(Vector<Employee> v, String name){
		for (int i = 0; i < v.size(); i++){
			if(v.get(i).e_name.equals(name)){
				v.removeElementAt(i);
				return ("Deleted " + name);
			}
		}
		return "Name does not exist in records.";
	}
	
	
	static String delete_by_id(Vector<Employee> v, int id){
		for (int i = 0; i < v.size(); i++){
			if(v.get(i).e_id == id){
				v.removeElementAt(i);
				return ("Deleted " + id);
			}
		}
		return "ID does not exist in records.";
	}

	
	static void sort_vector(Vector<Employee> v){
		int size = v.size();
		for (int i = 0; i < (size - 1); i++){
			int min = i;
			int min_salary = v.get(i).e_salary;
			for(int j = i + 1; j < size; j++){
				int j_salary = v.get(j).e_salary;
				if(min_salary > j_salary){
					min = j;
					min_salary = j_salary;
				}
			}
			if (min != i){
				Employee temp = v.get(i);
				v.set(i, v.get(min));
				v.set(min, temp);
			}
		}
	}
	
		
	static boolean add(Vector<Employee> v, Employee e){
		return v.add(e);
	}
	
	
	static void addElement(Vector<Employee> v, Employee e){
		v.addElement(e);
	}
	
	
	static int lastIndexOf(Vector<Employee> v, Employee e){
		return v.lastIndexOf(e);
	}
	
	
	static void removeElementAt(Vector<Employee> v,int index){
		v.removeElementAt(index);
	}
}





















