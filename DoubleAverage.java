
public class DoubleAverage {

	public static double average (double[] data) {
		double g = 0,f = 0;
		try {
			for (int i = 0; i < data.length; i++)
				g=g+data[i];
			f= g/data.length;
		}
		catch (Exception e) {
			Terminal.put("An error has occured!");
		}
		return f;
	}
	
	public static void main(String[] args) {
		double[] potato= {1,2,3,4,5};
		Terminal.put(average(potato));
	}

}
