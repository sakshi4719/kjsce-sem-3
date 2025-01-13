import java.util.concurrent.ThreadLocalRandom;

class Controller extends Thread {
	int num;

	public void run() {
		while(true){
			num = ThreadLocalRandom.current().nextInt(1, 100);
			int square = 0;
			if (num % 2 == 0) {
				EvenSquare even = new EvenSquare(num);
				even.start();
				try {
					sleep(500);
				}
				catch (InterruptedException e) {
					System.out.println(e);
				}
				square = even.square;
			}
			else {
				OddCube odd = new OddCube(num);
				odd.start();
				
				try {
					sleep(500);
				}
				catch (InterruptedException e) {
					System.out.println(e);
				}
				square = odd.square;
			}		
			
			System.out.println("number generated: " + num + "\nsquare: " + square);
		}
		
	}
}

class EvenSquare extends Thread {
	int num;
	int square;
	
	EvenSquare(int num) {
		this.num = num;		
	}	
	
	public void run() {
		square = num * num; 
	}
}


class OddCube extends Thread {
	int num;
	int square;
	
	OddCube(int num) {
		this.num = num;		
	}

	public void run() {
		square = num * num * num;	
	}
}

class Threads {
	public static void main(String args[]) {
		Controller num_gen = new Controller();
		num_gen.start();
	}
}

















