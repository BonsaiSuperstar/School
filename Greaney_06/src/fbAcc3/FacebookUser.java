package fbAcc3;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class FacebookUser extends UserAccount implements Comparable<FacebookUser>, Serializable {

	private static final long serialVersionUID = -89946894708968320L;
	
	String passwordHint;
	ArrayList<FacebookUser> friends;
	
	public FacebookUser() {
		
	}
	
	public FacebookUser(String name, String password, String pHint) {
		super(name, password);
		this.passwordHint = pHint;
		friends = new ArrayList<>();
	}

	public String getPasswordHint() {
		return passwordHint;
	}

	public void setPasswordHint(String passwordHint) {
		this.passwordHint = passwordHint;
	}

	public ArrayList<FacebookUser> getFriends() {
		ArrayList<FacebookUser> friendsCopy = new ArrayList<>();
		
		for(int i = 0; i < friends.size(); i++) {
			friendsCopy.add(friends.get(i));
		}
		
		Collections.sort(friendsCopy, new Comparator<FacebookUser>() {
			public int compare(FacebookUser FB1, FacebookUser FB2) {
				return FB1.toString().compareToIgnoreCase(FB2.toString());
			}
		});
		
		return friendsCopy;
	}

	public void setFriends(ArrayList<FacebookUser> friends) {
		this.friends = friends;
	}
	
	void friend(FacebookUser newFriend) {
		if (friends.contains(newFriend)) {
			System.out.println("ERROR! Friend already exists.");
		}
		else {
			friends.add(newFriend);
		}
	}
	
	void defriend(FacebookUser formerFriend) {
		if (friends.contains(formerFriend)) {
			friends.remove(formerFriend);
		}
		else {
			System.out.println("ERROR! No friend with this name.");
		}
	}
	
	public static Comparator<FacebookUser> COMPARE_BY_NAME = new Comparator<FacebookUser>() {
		public int compare(FacebookUser one, FacebookUser other) {
			return one.getUsername().compareToIgnoreCase(other.getUsername());
		}
	};
	
	public static Comparator<FacebookUser> COMPARE_BY_FRIENDS = new Comparator<FacebookUser>() {
		public int compare(FacebookUser o1, FacebookUser o2) {
			int a, b;
			a = 0;
			b = 0;
			if (o1.getFriends() != null) {
				a = o1.getFriends().size();
			}
			if (o2.getFriends() != null) {
				b = o2.getFriends().size();
			}
			return b - a;
		}
	};
	
	@Override
	public void getPasswordHelp() {
		System.out.println("Password hint: ** " + passwordHint + " **");
	}
	
	@Override
    public int compareTo(FacebookUser o) {
        return 0;
    }
	
	@Override
	public String toString() {
		return super.toString();
    }
	
}

