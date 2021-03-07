
public class UniqueCharacters {

	public static int distinctCharacters (String s) {
		int counter = s.length();
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < i ; j++ ) {
				if(s.charAt(i) == s.charAt(j))
				counter --;
				}
			
			}
		return counter;
	}
	public static void main(String[] args)
	{
		String x = "";
		x = Terminal.getString("Type smth");
		Terminal.put(distinctCharacters(x));

	}

}
