package Multiply;
public class MultiplicationTable {
	public static void main(String[] args) {
		System.out.println("                  Multiplication Table\n");
		System.out.print("     ");
		for (int j = 1; j < 13; j++)
			System.out.printf("%4d", j);
		System.out.println("\n    --------------------------------------------------");
		for (int i = 1; i < 13; i++) {
			System.out.printf("%3d |", i);
			for (int j = 1; j < 13; j++) {
				System.out.printf("%4d", i * j);
			}
			System.out.println();
		}
	}
}
