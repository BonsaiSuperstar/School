/*
 * Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Eleventh Assignment – Two Options 
 * December 3, 2017
 */
import java.util.Scanner;

public class Driver {

	public static void main(String[] args) {
		
		Integer[] num = new Integer[10];
		String[] str = {"Cooper", "Dougie", "Mr C.", "Gordon", "Albert",
					   "Tammy", "Diane", "Truman", "Andy", "Lucy"};
		BST<String> s = new BST<String>(str);
		Scanner in = new Scanner(System.in);
		System.out.println
			   ("╭━━┳━━━━┳━━━╮╱╭╮╱╱╱╱╱╱╭╮\n" + 
				"┃╭╮┃╭╮╭╮┃╭━╮┃╭╯╰╮╱╱╱╱╭╯╰╮\n" + 
				"┃╰╯╰┫┃┃╰┫╰━━╮╰╮╭╋━━┳━┻╮╭╯\n" + 
				"┃╭━╮┃┃┃╱╰━━╮┃╱┃┃┃┃━┫━━┫┃\n" + 
				"┃╰━╯┃┃┃╱┃╰━╯┃╱┃╰┫┃━╋━━┃╰╮\n" + 
				"╰━━━╯╰╯╱╰━━━╯╱╰━┻━━┻━━┻━╯\n" + 
				"");
		System.out.println("Enter 10 integers: ");
		for(int i=0; i<10; i++) {
			num[i]=in.nextInt();
		}
		BST<Integer> n = new BST<Integer>(num);
		
		System.out.println("\nDATA TYPE INTEGER...");
		System.out.println("Inorder using stack:");
		n.inorderUsingtack();
		System.out.println("\n\nHeight of Tree: " + n.height());
		System.out.println("\nBreadth first traversal:");
		n.breadthFirstTraversal();
		System.out.println("\n\nInorder:");
		n.inorder();
		System.out.println("\n\nPreorder:");
		n.preorder();
		System.out.println("\n\nPostorder:");
		n.postorder();
		in.close();
		
		System.out.println("\n\nDATA TYPE STRING...");
		System.out.println("Inorder using stack: ");
		s.inorderUsingtack();
		System.out.println("\n\nHeight of Tree: " + s.height());
		System.out.println("\nBreadth first traversal:");
		s.breadthFirstTraversal();
		System.out.println("\n\nInorder:");
		s.inorder();
		System.out.println("\n\nPreorder:");
		s.preorder();
		System.out.println("\n\nPostorder:");
		s.postorder();
		
	}//end of main

}//end of driver
