/*
 * Brian Greaney
 * CIS 2217 Fall, 2017, N04
 * Tenth Assignment - Multi-Level Undo
 * November 12, 2017
 */
package fbAcc3;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Driver {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws ClassNotFoundException, IOException {
		
		ArrayList<FacebookUser> fbUser = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		int choice = 0;
		
		System.out.println("De-serializing 'FBUsers.ser' file...");
		try
        {
            FileInputStream fis = new FileInputStream("FBUsers.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);
            fbUser = (ArrayList<FacebookUser>) ois.readObject();
            ois.close();
            fis.close();
         }catch(IOException ioe){
             ioe.printStackTrace();
             sc.close();
             return;
          }catch(ClassNotFoundException c){
             System.out.println("Class not found");
             c.printStackTrace();
             sc.close();
             return;
          }
		
		do {
			
			FBUtilities.menu();
			System.out.print("Enter choice 1-13: ");
			choice = sc.nextInt();
			while (choice < 1 || choice > 13) {
				System.out.print("Enter a valid choice: ");
				choice = sc.nextInt();
			}
			
			switch(choice) {
			case 1:
				FBUtilities.listUsersAlphabetically(fbUser);
				break;
			case 2: 
				FBUtilities.listUsersByFriendCount(fbUser);
				break;
			case 3:
				FBUtilities.addUser(fbUser);
				break;
			case 4:
				FBUtilities.deleteUser(fbUser);
				break;
			case 5:
				FBUtilities.passHint(fbUser);
				break;
			case 6:
				FBUtilities.addFriend(fbUser);
				break;
			case 7:
				FBUtilities.removeFriend(fbUser);
				break;
			case 8:
				FBUtilities.listFriends(fbUser);
				break;
			case 9:
				FBUtilities.recommendFriends(fbUser);
				break;
			case 10:
				FBUtilities.like(fbUser);
				break;
			case 11:
				FBUtilities.listLikes(fbUser);
				break;
			case 12:
				FBUtilities.Undo(fbUser);
				break;
			case 13:
				System.out.println("Goodbye...");
				break;
				
			}
			
		}while(choice!=13);
		
		sc.close();
		
		System.out.println("Serializing 'FBUsers.ser' file...");
		try {
			FileOutputStream fos = new FileOutputStream("FBUsers.ser");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(fbUser);
			oos.close();
			fos.close();
		}catch(IOException ioe) {
			ioe.printStackTrace();
		}
		//Tester...
		for(FacebookUser fbu: fbUser) {
			System.out.println("\nUsername: " + fbu.getUsername() + "\nPassword: " + fbu.getPassword()
								+ "\nFriends: " + fbu.getFriends() + "\nLikes: " + fbu.getLikes());
		}
		
	}//end of main
	
}// end of class
