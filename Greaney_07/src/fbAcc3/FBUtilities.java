package fbAcc3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeSet;

public class FBUtilities implements Cloneable {
	
	transient static Scanner in = new Scanner(System.in);

	public static void menu() {
		System.out.println();
		System.out.println("\t Facebook User Menu");
		System.out.println("-----------------------------------");
		System.out.println("1.  List users alphabetically");
		System.out.println("2.  List users by number of friends");
		System.out.println("3.  Add a user");
		System.out.println("4.  Delete a user");
		System.out.println("5.  Get password hint");
		System.out.println("6.  Add a friend");
		System.out.println("7.  Remove a friend");
		System.out.println("8.  List friends");
		System.out.println("9.  Recommend friends");
		System.out.println("10. Add a like");
		System.out.println("11. List likes");
		System.out.println("12. EXIT");
	}// end of menu method
	
	public static int login(ArrayList<FacebookUser> fb) {
	    boolean found = false;
		int j = 0;
		System.out.println("Log in first...");
		System.out.print("username: ");
		String tempName = in.nextLine();
		for(int i=0;i<fb.size();i++) {
			if(fb.get(i).getUsername().equals(tempName)) {
				System.out.println("User found");
				found = true;
				System.out.print("password: ");
				String tempPass = in.nextLine();
				if(fb.get(i).getPassword().equals(tempPass)) {
					System.out.println("Logged in!");
					j=i;
					break;
				}
				else {
					System.out.println("One more try, here's a hint...");
					fb.get(i).getPasswordHelp();
					System.out.print("password: ");
					tempPass = in.nextLine();
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
	
	public static void listUsersAlphabetically(ArrayList<FacebookUser> fbUser) {
		System.out.println("FacebookUsers alphabetically: ");
		Collections.sort(fbUser, FacebookUser.COMPARE_BY_NAME);
		for(FacebookUser fbu: fbUser) {
			System.out.println("\t" + fbu);
		}
	}//end of listUsersAlphabetically method
	
	public static void listUsersByFriendCount(ArrayList<FacebookUser> fbUser) {
		System.out.println("FacebookUsers by number of friends: ");
		Collections.sort(fbUser, FacebookUser.COMPARE_BY_FRIENDS);
		for(FacebookUser fbu: fbUser) {
			System.out.println("\t" + fbu + " has " + fbu.getFriends().size() + " friends.");
		}
	}//end of listUsersByFriendCount method
	
	public static void addUser(ArrayList<FacebookUser> fbUser) {
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
	}//end of addUser Method
	
	public static void deleteUser(ArrayList<FacebookUser> fbUser) {
		boolean found = false;
		System.out.print("Enter a User to delete: ");
		String deleted = in.nextLine();
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
	}//end of deleteUser method
	
	public static void passHint(ArrayList<FacebookUser> fbUser) {
		boolean found = false;
		System.out.print("Enter username: ");
		String pName = in.nextLine();
		for(int i=0;i<fbUser.size();i++) {
			if(fbUser.get(i).getUsername().equals(pName)) {
				fbUser.get(i).getPasswordHelp();
				found = true;
			}
		}
		if(!found) {
			System.out.println("ERROR! Username not found!");
		}
	}//end of passHint method
	
	public static void addFriend(ArrayList<FacebookUser> fbUser) {
		int j = login(fbUser);
		boolean found = false;
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
	}//end of addFriend method
	
	public static void removeFriend(ArrayList<FacebookUser> fbUser) {
		int j = login(fbUser);
		boolean found = false;
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
	}//end of removeFriend method
	
	public static void listFriends(ArrayList<FacebookUser> fbUser) {
		int j = login(fbUser);
		System.out.println(fbUser.get(j) + "'s friends:");
		System.out.println(fbUser.get(j).getFriends());
	}//end of listFriends method
	
	public static void recommendFriends(ArrayList<FacebookUser> fbUser) {
		int j =login(fbUser);
		getRecommendations(fbUser.get(j));
	}//end of recommendFriends method
	
	public static void like(ArrayList<FacebookUser> fbUser) {
		int j = login(fbUser);
		boolean found = false;
		System.out.print("What does " + fbUser.get(j) + " like? ");
		String like = in.nextLine();
		if(fbUser.get(j).friends.isEmpty()) {
			fbUser.get(j).like(like);
			found = true;
		}
		else {
			fbUser.get(j).like(like);
			found = true;
		}
		if(!found) {
			System.out.println("ERROR! Username not found!");
		}
	}//end of like method
	
	public static void listLikes(ArrayList<FacebookUser> fbUser) {
		int j = login(fbUser);
		boolean found = false;
		/*
		 * EXPLANATION:
		 * 	I have chosen a TreeSet for its speed, efficiency, sorting, and it won't allow duplicates.
		 * 	This will provide a duplicate-free set no matter how many times someone likes the same things.
		 */
		TreeSet<String> set = new TreeSet<>(fbUser.get(j).getLikes());
		
		if(set.isEmpty()) {
			System.out.println(fbUser.get(j).getUsername() + " doesn't like antything.");
			found = true;
		}
		else {
			System.out.println(fbUser.get(j).getUsername() + "'s likes: ");
			System.out.println("\t" + set);
			found = true;
		}
		if(!found) {
			System.out.println("ERROR! Username not found!");
		}
	}//end of listLikes method

}
