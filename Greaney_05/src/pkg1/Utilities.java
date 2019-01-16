package pkg1;

import java.util.*;
public class Utilities {

	public static <E> ArrayList<E> removeDublicates(List<E> list) {
		ArrayList<E> dupList = new ArrayList<>();
		ArrayList<E> newList = new ArrayList<>();
		for(int i=0;i<list.size();i++) {
			E object = list.get(i);
			if(!dupList.contains(object)) {
				dupList.add(object);
				newList.add(object);
			}
		}
		return newList;
	}
	
	public static <E extends Comparable<E>>int linearSearch(E[] list, E key) {
		for(int i=0;i<list.length;i++) {
			if(key.compareTo(list[i])==0) {
				return i;
			}
		}
		return -1;
	}
	
}
