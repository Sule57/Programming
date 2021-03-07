
public class IntToBase2 {

	public static String intToBase2 (int x) {
		String temp = "";
		String s = "";
		String sign = "";
		if (x<0)
			x = x* (-1);
			sign = "-";
		do {
			if (x % 2 == 1) {
				temp = "1";
				s = temp + s;
			}
			else {
				temp = "0";
				s = temp + s;
			}
			x = x/2;
		}
		while (x != 0);
		return sign + s;
	}
	
	public static void main(String[] args) {
		int p;
		p = Terminal.getInt("Write an integer number:");
		Terminal.put(intToBase2(p));
	}
}
