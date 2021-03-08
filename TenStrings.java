
public class TenStrings {

	public static void main(String[] args) {
		String[] array ;
		array = new String[10];
		for (int i = 0; i<10;i++) {
			array[i]=Terminal.getString("input the string"+(i+1)+"/10:  ");
		}
		if (ContainsDuplicates.containsDuplicates(array)==false) Terminal.put("does not contain duplicates");
		else Terminal.put("does contain duplicates");
	}

}
