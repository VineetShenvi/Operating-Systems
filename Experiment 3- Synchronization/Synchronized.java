import java.util.*;

class Server 
{
    private int availableSeats;
    
    Server(int availableSeats){
        this.availableSeats = availableSeats;
    }
    
	synchronized public void bookTicket(String pname) {
        System.out.println("Vineet Shenvi   6000220012   C182");
	    System.out.println("Hi "+ pname + "!\nWelcome to Neeta Travels!");
	    System.out.println("Number of seats available : "+availableSeats);
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of tickets needed: ");
        int n = sc.nextInt();
		if ((availableSeats >= n) && (n > 0)) 
        {
			System.out.println("You have booked "+n+" seats.");
			availableSeats = availableSeats- n;
		} 
		else 
        System.out.println("Sorry, we do not have "+n+" tickets available!");
		System.out.println();
	}
}

class Passenger extends Thread 
{
	private Server s;
	private String name;

	public Passenger(Server s,String name) 
    {
		this.s = s;
		this.name = name;
	}
	
	public void run() 
    {
		s.bookTicket(name);
	}
}

public class Synchronized 
{
    public static void main(String[] args) 
    {
        Server s = new Server(100);
        Passenger t1 = new Passenger(s,"Taran");
        Passenger t2 = new Passenger(s,"Vedant");
        Passenger t3 = new Passenger(s, "Rushaan");

        t1.start();
        t2.start();
        t3.start();
    }
}

