import java.util.Scanner;

public class PairTest {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Integer f;
		String s;
		
		System.out.println("First Field\tSecond Field");

		f = scan.nextInt();
		s = scan.next();
		Pair<Integer, String> p1 = new Pair<Integer, String>(f, s);
		System.out.print("Original ");
		p1.toString();
		
		f = scan.nextInt();
		s = scan.next();
		p1 = new Pair<Integer, String>(f, s);
		System.out.print("Modified ");
		p1.toString();
		
		f = scan.nextInt();
		s = scan.next();
		p1 = new Pair<Integer, String>(f, s);
		System.out.print("Again Modified ");
		p1.toString();
		
		scan.close();
	}
}

class Pair<F, S> {
	private F f;
	private S s;
	
	public Pair(F f, S s) {
		this.f = f;
		this.s = s;
	}

	public F getF() {
		return f;
	}

	public S getS() {
		return s;
	}

	public void setF(F f) {
		this.f = f;
	}

	public void setS(S s) {
		this.s = s;
	}
	
	@Override
	public String toString() {
		System.out.println("pair: (" + getF() + ", " + getS() + ")" );
		return null;
	}
}