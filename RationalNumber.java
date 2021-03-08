//I HAVE NO FUCKING CLUE IF THIS WORKS AND I DONT GIVE A SHIT
public class RationalNumber {
	private long p;
	private long q;
	public RationalNumber(long p, long q) {
		String sign = "";
		if (q == 0) throw new IllegalArgumentException("ILLEGAL VALUE");
		else if (q < 0 && p > 0) { q=q*(-1); p=p*(-1);}
		else if (q < 0 && p < 0) { p=p*(-1); q=q*(-1);}
		else if (p < 0 && q > 0) {
			sign = "-";
			p=p*(-1);
		}
		
		long divisor = GCD.gcd(p, q);
		if (sign == "-") this.p = p/divisor*(-1);
		else this.p = p/divisor;
		this.q = q/divisor;
	}
	
}
