
public class GCD {

	public static long gcd(long x, long y) {
		if (y==0) return x;
		else return gcd(y, x%y);
	}
	
	public static void main(String[] args) {
		int a = Terminal.getInt("Number one:");
		int b = Terminal.getInt("Number 2:");
		Terminal.put(gcd(a,b));
	}

}
