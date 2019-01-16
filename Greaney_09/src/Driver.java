/* Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Ninth Assignment – Sorting
 * November 4, 2017 
 */
public class Driver {

	public static <E extends Comparable<E>> void print(E[] list) {
		if (list.length == 0)
			return;
		int i;
		System.out.print("[");
		for (i=0; i<list.length-1; i++) {
			System.out.print(list[i] + ", ");
		}
		System.out.println(list[i]+"]");
	}

	public static <E extends Comparable<E>> void shuffler(E[] list) {
		for (int i = 0; i < list.length; i++) {
			int j = (int) (Math.random() * list.length);
			E temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
	
	public static void main(String[] args) {
		
		System.out.println("\t|````````````````````````|");
		System.out.println("\t|    Utility Methods     |");
		System.out.println("\t|    TESTING DRIVER:     |");
		System.out.println("\t|        Part II         |");
		System.out.println("\t|________________________|");
		System.out.println("\n\t    **INSERTION SORT**");
		
		System.out.println("Integer test...");
		Integer intList[] = {2,47,18,-1,0,3};
		System.out.print("BEFORE: ");
		print(intList);
		Utilities.insertionSort(intList);
		System.out.print("AFTER:  ");
		print(intList);
		
		System.out.println("\nString test...");
		String stringList[] = {"zebra", "cat", "mouse", "aardvark", "dog"};
		System.out.print("BEFORE: ");
		print(stringList);
		Utilities.insertionSort(stringList);
		System.out.print("AFTER:  ");
		print(stringList);

		System.out.println("\nFacebookUser test...");
		FacebookUser fbList[] = {new FacebookUser("Rob","pass","pass"), 
				new FacebookUser("Joe","123","123"),
				new FacebookUser("Annie","pword","pword"),
				new FacebookUser("Zelda","456","456"),
				new FacebookUser("Mikey","life","life")};
		System.out.print("BEFORE: ");
		print(fbList);
		Utilities.insertionSort(fbList);
		System.out.print("AFTER:  ");
		print(fbList);
		
		System.out.println("\n\t  **SHUFFLING ARRAYS**");
		shuffler(intList);
		shuffler(stringList);
		shuffler(fbList);
		System.out.println("Arrays now shuffled...");
		
		System.out.println("\n\t     **QUICK SORT**");
		System.out.println("Integer test...");
		System.out.print("BEFORE: ");
		print(intList);
		Utilities.quickSort(intList);
		System.out.print("AFTER:  ");
		print(intList);
		
		System.out.println("\nString test...");
		System.out.print("BEFORE: ");
		print(stringList);
		Utilities.quickSort(stringList);
		System.out.print("AFTER:  ");
		print(stringList);
		
		System.out.println("\nFacebookUser test...");
		System.out.print("BEFORE: ");
		print(fbList);
		Utilities.quickSort(fbList);
		System.out.print("AFTER:  ");
		print(fbList);
		
	}

}
