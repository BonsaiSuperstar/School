/*Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Forth Assignment - The FacebookUser Class
 * September 24, 2017
 */
package fbAcc3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.*;

public class Driver {

	public static void menu() {
		System.out.println();
		System.out.println("\tFacebook User Menu");
		System.out.println("----------------------------------");
		System.out.println("1. List Users");
		System.out.println("2. Add a User");
		System.out.println("3. Delete a User");
		System.out.println("4. Get Password Hint");
		System.out.println("5. Add a friend");
		System.out.println("6. Remove a friend");
		System.out.println("7. List friends");
		System.out.println("8. Recommend friends");
		System.out.println("9. Quit");
	}// end of menu method
	
	public static int login(ArrayList<FacebookUser> fb) {
	    @SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
	    boolean found = false;
		int j = 0;
		System.out.println("Log in first...");
		System.out.print("username: ");
		String tempName = sc.nextLine();
		for(int i=0;i<fb.size();i++) {
			if(fb.get(i).getUsername().equals(tempName)) {
				System.out.println("User found");
				found = true;
				System.out.print("password: ");
				String tempPass = sc.nextLine();
				if(fb.get(i).getPassword().equals(tempPass)) {
					System.out.println("Logged in!");
					j=i;
					break;
				}
				else {
					System.out.println("One more try, here's a hint...");
					fb.get(i).getPasswordHelp();
					System.out.print("password: ");
					tempPass = sc.nextLine();
					if(fb.get(i).getPassword().equals(tempPass)) {
						System.out.println("Logged in!");
						j = i;
						break;
					}
					else {
						System.out.println("Failed to log in, deactivating account.");
						fb.get(i).deactivateAccount();
						break;
					}
				}	
			}
		}
		if(!found) {
			System.out.println("ERROR! Username not found!");
		}
		return j;
	}//end of login method
	
	public static void getRecommendations(FacebookUser user) {		
		ArrayList<FacebookUser> recommendations = new ArrayList<FacebookUser>();
		for(FacebookUser f : user.getFriends()) {
			getRecommendations(f, recommendations);
		}
		//remove user who logged in from recommendations list
		recommendations.remove(user);
		//loop through and remove logged in user's existing friends from recommendation list
		for(int i=0;i<user.getFriends().size();i++) {
			recommendations.remove(user.getFriends().get(i));
		}
		//print the recommendations
		if(!recommendations.isEmpty()) {
			System.out.println("Recommended friends for you:");
			for (FacebookUser u : recommendations) {
				System.out.println("\t"+u);
			}
		}
		else {
			System.out.println("Sorry, no recommendations.");
		}
	}//end of getRecommendations method

	private static void getRecommendations(FacebookUser user, ArrayList<FacebookUser> recommendations) {
		if(user != null && user.getFriends() != null && !user.getFriends().isEmpty()) {
			for(FacebookUser friend : user.getFriends()) {
				if(!recommendations.contains(friend)) {
					recommendations.add(friend);
					getRecommendations(friend, recommendations);
				}
			}
		}
	}//end of getRecommendations Helper method 
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws ClassNotFoundException, IOException {
		ArrayList<FacebookUser> fbUser = new ArrayList<>();
		
		System.out.println("De-serializing 'FBUsers' file...");
		try
        {
            FileInputStream fis = new FileInputStream("FBUsers");
            ObjectInputStream ois = new ObjectInputStream(fis);
            fbUser = (ArrayList<FacebookUser>) ois.readObject();
            ois.close();
            fis.close();
         }catch(IOException ioe){
             ioe.printStackTrace();
             return;
          }catch(ClassNotFoundException c){
             System.out.println("Class not found");
             c.printStackTrace();
             return;
          }
        
		Scanner in = new Scanner(System.in);
		int choice = 0;
		boolean found;
		
		do {
			menu();
			System.out.print("Enter 1-9: ");
			choice = in.nextInt();
			while (choice < 1 || choice > 9) {
				System.out.print("Enter a valid choice: ");
				choice = in.nextInt();
			}
			System.out.println();
			in.nextLine();
			
			if(choice == 1) { 
				Collections.sort(fbUser, FacebookUser.COMPARE_BY_NAME);
				for(FacebookUser fbu: fbUser) {
					System.out.println("\t" + fbu);
				}
			}
					
			if(choice == 2) {
				System.out.print("Enter a username: ");
				String name = in.nextLine();
				for(int i=0; i<fbUser.size(); i++) {
					while(fbUser.get(i).getUsername().equals(name)) {
						System.out.println("ERROR! User already exists!");
						System.out.print("Enter a username: ");
						name = in.nextLine();
					}
				}
				System.out.print("Enter a password: ");
				String pass = in.nextLine();
				System.out.print("Enter a password hint: ");
				String pHint = in.nextLine();
				fbUser.add(new FacebookUser(name,pass,pHint));
			}
					
			if(choice == 3) {
				System.out.print("Enter a User to delete: ");
				String deleted = in.nextLine();
				found = false;
				for(int i=0; i<fbUser.size(); i++) {
					if(fbUser.get(i).getUsername().equals(deleted)) {
					System.out.println("Deleting User...");
					found = true;
					fbUser.remove(i);
					}
				}
				if(!found) {
					System.out.println("ERROR! Username not found!");
				}
			}
			
			if(choice == 4) {
				System.out.print("Enter username: ");
				String pName = in.nextLine();
				found = false;
				for(int i=0;i<fbUser.size();i++) {
					if(fbUser.get(i).getUsername().equals(pName)) {
						fbUser.get(i).getPasswordHelp();
						found = true;
					}
				}
				if(!found) {
					System.out.println("ERROR! Username not found!");
				}
			}
					
			if(choice == 5) {
				int j = login(fbUser);
				found = false;
				System.out.print("Enter the username you would like to befriend: ");
				String tempName = in.nextLine();
				for(int i=0; i < fbUser.size(); i++) {
					if(fbUser.get(i).getUsername().equals(tempName)) {
						fbUser.get(j).friend(fbUser.get(i));
						found = true;
						System.out.println("Adding friend...");
					}
				}
				if(!found) {
					System.out.println("ERROR! Username not found!");
				}
			}
				
			if(choice == 6) {
				int j = login(fbUser);
				found = false;
				System.out.print("Enter the username you would like to defriend: ");
				String tempName = in.nextLine();
				for(int i=0; i < fbUser.size(); i++) {
					if(fbUser.get(i).getUsername().equals(tempName)) {
						fbUser.get(j).defriend(fbUser.get(i));
						found = true;
						System.out.println("Removing friend...");
					}
				}
				if(!found) {
					System.out.println("ERROR! Username not found!");
				}
			}
			
			if(choice == 7) {
				int j = login(fbUser);
				System.out.println(fbUser.get(j) + "'s friends:");
				System.out.println(fbUser.get(j).getFriends());
			}
			
			if(choice == 8) {
				int j =login(fbUser);
				getRecommendations(fbUser.get(j));	
			}
			
			if(choice == 9) {
				System.out.println("Goodbye...");
				System.out.println();
			}
			
		}while(choice!=9);
		
		in.close();
		
		System.out.println("Serializing 'FBUsers' file...");
		try {
			FileOutputStream fos = new FileOutputStream("FBUsers");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(fbUser);
			oos.close();
			fos.close();
		}catch(IOException ioe) {
			ioe.printStackTrace();
		}
		
	}//end of main
	
}// end of class
