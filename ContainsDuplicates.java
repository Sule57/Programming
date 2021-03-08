
public class ContainsDuplicates {

	public static boolean containsDuplicates (String[] sarr) {
		if (sarr.length == 0 || sarr == null) return false;
		for (int i = 0; i < sarr.length; i++) {
			for (int j = 0; j < i; j++) {
				if (sarr[i] == sarr[j]) return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		
	}

}
