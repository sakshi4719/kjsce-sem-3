class thread1 extends Thread
{
	public void run()
	{
	for(char ch = 97; ; ch++)
	{
	if (ch == 122)			
	{
	ch = 97;
	}
	System.out.print(ch);
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
	for(int i = 1; ; i++)
	{
	System.out.print(i);
	try{Thread.sleep(500);}
	catch(Exception e)
	{System.out.println(e);}
	}
	}
}

class asciii
{
	public static void main(String args[])
	{
	thread1 t1 = new thread1();
	thread2 t2 = new thread2();

	t2.start();
	t1.start();
	}
}

	
	
