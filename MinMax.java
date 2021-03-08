
public class MinMax {
	public static int[] minMax (int [] ia) {
		if (ia.length<2) return null;
		int min = ia[0], max = ia[0];
		for (int i = 0; i < ia.length; i++) {
			if (ia[i] < min) min = ia[i];
			if (ia[i] > max) max = ia[i];
		}
		int[] array = {min,max};
		return array;
	}
	
	public static void main (String[] args) {
		int[] array = new int[1];
		for (int i = 0;i<1;i++) {
			array[i] = Terminal.getInt("Write an int");
		}
		int[] kurac = minMax(array);
		
		Terminal.put(kurac[0]+","+kurac[1]);
	}
}
