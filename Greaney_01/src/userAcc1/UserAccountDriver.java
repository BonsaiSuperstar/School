/*Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * First Assignment - The UserAccount Class
 * September 2, 2017
 */

package userAcc1;

import java.util.Scanner;

public class UserAccountDriver {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		UserAccount user1 = new UserAccount("Brian", "goose1");
		UserAccount user2 = new UserAccount("Liam", "cnl5022");

		String tempName, tempPass;
		
		System.out.print("Enter user name: ");
		tempName = sc.nextLine();
		
	 	while(!user1.getUsername().equals(tempName) && !user2.getUsername().equals(tempName)){
			System.out.print("Please enter a valid user name: ");
			tempName = sc.nextLine();
		}
		
		System.out.print("Enter password: ");
		tempPass = sc.nextLine();
		
		if(user1.getUsername().equals(tempName)){
			if(user1.getPassword().equals(tempPass)){
				System.out.println("Logging in...");
			}
			else{
				System.out.println("Incorrect password, account will be deactivated!");
				user1.deactivateAccount();
			}
		}
		else if(user2.getUsername().equals(tempName)){
			if(user2.getPassword().equals(tempPass)){
				System.out.println("Logging in...");
			}
			else{
				System.out.println("Incorrect password, account will be deactivated!");
				user2.deactivateAccount();
			}
		}
		
		System.out.println("\n User Accounts List:");
		System.out.println("---------------------");
		System.out.println(user1);
		System.out.println(user2);

		sc.close();
	}

}
