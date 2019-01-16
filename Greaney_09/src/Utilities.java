
import java.util.ArrayList;
import java.util.List;

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
	
	public static <E extends Comparable<E>> void insertionSort(E[] list) {
		for (int i = 1; i < list.length; i++) {
			E key = list[i];
			int point = i;
			while (point > 0 && key.compareTo(list[point - 1]) < 0) {
				list[point] = list[point - 1];
				point--;
			}
			list[point] = key;
		}

	}

	public static <E extends Comparable<E>> void quickSort(E[] list) {
		if (list == null || list.length == 0)
			return;
		quickSort(list, 0, list.length - 1);
	}

	private static <E extends Comparable<E>> void quickSort(E[] list, int low,
			int high) {
		if (low >= high)
			return;
		E pivot;
		if (high - low == 0 || high - low == 1)
			pivot = list[low];
		else
			pivot = list[low + 1];
		print(pivot, list, low, high);
		int i = low, j = high;
		while (i <= j) {
			while (list[i].compareTo(pivot) < 0) {
				i++;
			}

			while (list[j].compareTo(pivot) > 0) {
				j--;
			}

			if (i <= j) {
				E temp = list[i];
				list[i] = list[j];
				list[j] = temp;
				i++;
				j--;
			}
		}
		if (low < j)
			quickSort(list, low, j);

		if (high > i)
			quickSort(list, i, high);
	}

	private static <E extends Comparable<E>> void print(E pivot, E[] list, int low, int high) {
		if (list.length == 0)
			return;
		System.out.print("\tSub-array: [");
		int i;
		for (i = low; i < high; ++i)
			System.out.print(list[i] + ", ");
		System.out.println(list[i]+"]");
		System.out.println("\tPivot: " + pivot);

	}
	
}