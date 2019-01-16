/* Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Fifth Assignment - Utility Methods
 * October 1, 2017
 */
package pkg1;

import java.util.*;

public class driver {

	public static void main(String[] args) {
		//ArrayLists for tests
		ArrayList<Integer> intList = new ArrayList<>();
		ArrayList<String> stringList = new ArrayList<>();
		ArrayList<FacebookUser> fbList = new ArrayList<>();
		ArrayList<Integer> list1 = new ArrayList<>();
		ArrayList<String> list2 = new ArrayList<>();
		ArrayList<FacebookUser> list3 = new ArrayList<>();
		
		System.out.println("\t|````````````````````````|");
		System.out.println("\t|    Utility Methods     |");
		System.out.println("\t|    TESTING DRIVER:     |");
		System.out.println("\t|________________________|");
		
		//integer tests
		intList.add(1);
		intList.add(1);
		intList.add(2);
		intList.add(2);
		intList.add(3);
		intList.add(3);
		System.out.println("\n List of Integers with duplicates:\n\t"+intList);
		list1 = Utilities.removeDublicates(intList);
		System.out.println(" List of Integers without duplicates:\n\t"+list1);
		int intSearch = 2;
		Integer[] intArr = (Integer[])list1.toArray(new Integer[list1.size()]);
		System.out.println("\n  Searching for: \""+intSearch+"\"");
		System.out.println("  Element's location in array: "
							+Utilities.linearSearch(intArr, intSearch)+"\n");
		
		//string tests
		stringList.add("Hey");
		stringList.add("Hey");
		stringList.add("Howdy");
		stringList.add("Howdy");
		stringList.add("Doody");
		stringList.add("Doody");
		System.out.println("\n List of Strings wiht duplicates:\n\t"+stringList);
		list2 = Utilities.removeDublicates(stringList);
		System.out.println(" List of Strings without duplicates: \n\t"+list2);
		String strSearch = "Hey";
		String[] strArr= (String[])list2.toArray(new String[list2.size()]);
		System.out.println("\n  Searching for: \""+strSearch+"\"");
		System.out.println("  Element's location in array: "
							+Utilities.linearSearch(strArr, strSearch)+"\n");
		
		//FacebookUser tests
		FacebookUser fb1 = new FacebookUser("fb1", "pass","word");
		FacebookUser fb2 = new FacebookUser("fb2", "pass","word");
		FacebookUser fb3 = new FacebookUser("fb3", "pass","word");
		fbList.add(fb1);
		fbList.add(fb1);
		fbList.add(fb2);
		fbList.add(fb2);
		fbList.add(fb3);
		fbList.add(fb3);
		System.out.println("\n List of FacebookUsers with duplicates:\n\t"+fbList);
		list3 = Utilities.removeDublicates(fbList);
		System.out.println(" List of FacebookUsers without duplicates:\n\t"+list3);
		String fbSearch = "fb3";
		String[] fbArr = new String[list3.size()];
		for(int i=0;i<list3.size();i++) {
			fbArr[i] = list3.get(i).getUsername();
		}
		System.out.println("\n  Searching for: \""+fbSearch +"\"");
		System.out.println("  Element's location in array: "
							+Utilities.linearSearch(fbArr, fbSearch)+"\n");
		
		//Miscellaneous tests
		System.out.println("\t***********************");
		System.out.println("\t* MISCELLANEOUS TESTS *");
		System.out.println("\t***********************\n");
		//list of duplicates test
		ArrayList<String> testStr = new ArrayList<>();
		testStr.add("yo");
		testStr.add("yo");
		testStr.add("yo");
		System.out.println(" What if your removeDuplicates method is passed an ArrayList "
							+ "\n  in which every item is identical?");
		System.out.print("\tBefore: "+testStr);
		System.out.println("\n\t After: "+Utilities.removeDublicates(testStr)
							+"\n\tYo, no matter how many go in,\n\tonly one comes out...");
		//empty lists test
		System.out.println("\n What if the ArrayList or array is empty?");
		list1.clear();
		System.out.println("\tRemove duplicates?\n\t"+Utilities.removeDublicates(list1)
							+"\n\tnadda...");
		String[] array = {};
		System.out.println("\tA linear search?");
		if(Utilities.linearSearch(array, "search")==-1) {
			System.out.println("\tERROR! Doesn't exist within the array.");
		}
		System.out.println("\tthat's a nope too...");
		//one item only test
		System.out.println("\n What if it contains only one item?");
		list1.add(1);
		System.out.println("\tBefore: "+list1);
		System.out.println("\t After: "+Utilities.removeDublicates(list1)
							+"\n\tno duplicates to remove...");
		String[] test = {"test"};
		System.out.println("\tSearching for: \"test\" within: String[] test");
		System.out.println("\tfound at: "+Utilities.linearSearch(test, "test")
							+"\n\tnothing unexpected there...");
	}// end of main

}//end of class
