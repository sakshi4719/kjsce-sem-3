class thread1 extends Thread
{
	public void run()
	{
	for(int i = 1; i<=9; i++)
	{
	System.out.print("$");
	try{Thread.sleep(500);}
	catch(Exception e)
	{System.out.println(e);}
	}
	}
}

class thread2 extends Thread 
{
	public void run()
	{
	for(int i = 1; i<=9; i++)
	{
	System.out.print(i);
	try{Thread.sleep(500);}
	catch(Exception e)
	{System.out.println(e);}
	}
	}
}

class thr2
{
	public static void main(String args[])
	{
	thread1 t1 = new thread1();
	thread2 t2 = new thread2();

	t1.start();
	t2.start();
	}
}

	
	
