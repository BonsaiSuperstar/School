/*Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Second Assignment - The FacebookUser Class
 * September 10, 2017
 */

package fbAcc1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Driver {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int choice = 0;
		int j = 0;
		
		ArrayList<FacebookUser> fbUser = new ArrayList<>();
		
		fbUser.add(new FacebookUser("Brian", "password1", "It's password 1 dummy!"));
		fbUser.add(new FacebookUser("Liam", "1drowssap", "password1 backwards"));
		fbUser.add(new FacebookUser("Angie", "rock"," and roll"));
		fbUser.add(new FacebookUser("Nathan","kidney","failure"));
		fbUser.add(new FacebookUser("Maureen", "cheese101", "yum"));
		fbUser.get(0).friend(fbUser.get(1));
		fbUser.get(0).friend(fbUser.get(2));
		fbUser.get(0).friend(fbUser.get(3));
		fbUser.get(0).friend(fbUser.get(4));
		fbUser.get(1).friend(fbUser.get(0));
		fbUser.get(2).friend(fbUser.get(3));
		fbUser.get(3).friend(fbUser.get(4));
		fbUser.get(4).friend(fbUser.get(2));
		fbUser.get(4).friend(fbUser.get(0));
		
		do {
			System.out.println();
			System.out.println("\tFacebook User Menu");
			System.out.println("----------------------------------");
			System.out.println("1. Create an account");
			System.out.println("2. Login with existing account");
			System.out.println("3. List of users and their friends");
			System.out.println("4. Add a friend");
			System.out.println("5. Remove a friend");
			System.out.println("6. EXIT\n");
			System.out.print("Enter choice: ");
			choice = sc.nextInt();
			
			while (choice < 1 || choice > 6) {
				System.out.print("Enter a valid choice: ");
				choice = sc.nextInt();
			}
			sc.nextLine();
			
			if (choice == 1) {
				System.out.print("Enter a username: ");
				String name = sc.nextLine();
				System.out.print("Enter a password: ");
				String pass = sc.nextLine();
				System.out.print("Enter a password hint: ");
				String pHint = sc.nextLine();
				fbUser.add(new FacebookUser(name,pass,pHint));
			}
			
			else if (choice == 2) {
				System.out.println("Sign in...");
				System.out.print("username: ");
				String tempName = sc.next();
				sc.nextLine();
				
				for(int i=0; i < fbUser.size(); i++) {
					if(fbUser.get(i).getUsername().equals(tempName)) {
						System.out.println("User found");
						System.out.print("password: ");
						String tempPass = sc.nextLine();
						if(fbUser.get(i).getPassword().equals(tempPass)) {
							System.out.println("Logged in!");
							j = i;
							break;
						}
						else {
							System.out.println("One more try, here's a hint...");
							fbUser.get(i).getPasswordHelp();
							System.out.print("password: ");
							tempPass = sc.nextLine();
							
							if(fbUser.get(i).getPassword().equals(tempPass)) {
								System.out.println("Logged in!");
								j = i;
								break;
							}
							else {
								System.out.println("Failed to log in, deactivating account.");
								fbUser.get(i).deactivateAccount();
								break;
							}
						}
					}		
				}
			}
			
			else if (choice == 3) {
				Collections.sort(fbUser, FacebookUser.COMPARE_BY_NAME);
				for(FacebookUser fbu: fbUser) {
					System.out.println(fbu);
					System.out.println("Friends: " + fbu.getFriends());
				}
			}
			
			else if (choice == 4) {
				System.out.println("Enter the username you would like to befriend:");
				String tempName = sc.nextLine();
				for(int i=0; i < fbUser.size(); i++) {
					if(fbUser.get(i).getUsername().equals(tempName)) {
						fbUser.get(j).friend(fbUser.get(i));
					}
				}
			}
			
			else if (choice == 5) {
				System.out.println("Enter the username you would like to defriend:");
				String tempName = sc.nextLine();
				for(int i=0; i < fbUser.size(); i++) {
					if(fbUser.get(i).getUsername().equals(tempName)) {
						fbUser.get(j).defriend(fbUser.get(i));
					}
				}
			}
			
			else if (choice == 6){
				System.out.println("Goodbye...");
			}
			
		} while (choice != 6);
		
        sc.close();
        
    }
	
}
