/*Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Third Assignment - The FacebookUser Class
 * September 17, 2017
 */
package fbAcc2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.*;

public class fbDemo {

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
		
		do {
			menu();
			System.out.print("Enter 1-5: ");
			choice = in.nextInt();
			while (choice < 1 || choice > 5) {
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
				boolean found = false;
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
				boolean found = false;
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
				System.out.println("Goodbye...");
				System.out.println();
			}
			
		}while(choice!=5);
		
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
	
	public static void menu() {
		System.out.println();
		System.out.println("\tFacebook User Menu");
		System.out.println("----------------------------------");
		System.out.println("1. List Users");
		System.out.println("2. Add a User");
		System.out.println("3. Delete a User");
		System.out.println("4. Get Password Hint");
		System.out.println("5. Quit");
	}// end of menu method
	
}// end of class
