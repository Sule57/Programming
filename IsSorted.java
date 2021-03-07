//**READ THIS PART**//
//Its not set to boolean because its unprintable

public class IsSorted {
	
	public static String isSorted (int[] iarr) {
		if (iarr == null || iarr.length == 0) return "true";
		for (int i = 0; i<iarr.length;i++) {
			for (int j=0;j<i;j++) {
				if (iarr [j] > iarr [i]) return "false";
			}
		}
		return "true";
	}

	public static void main(String[] args) {
		
		int a[] = {};
		Terminal.put(isSorted(a));
		
	}

}
