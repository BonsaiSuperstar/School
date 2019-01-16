package userAcc1;

public class driver {

	@SuppressWarnings("unused")
	public static void main(String[] args) {
		UserAccount user1 = new UserAccount("one", "p1");
		UserAccount user2 = new UserAccount("two", "p2");
		
		boolean expectFalse = user1.checkPassword("P1");
		boolean expectTrue = user1.checkPassword("p1");
		boolean expectFalseWithNull = user1.checkPassword(null);
		user1.deactivateAccount();
		boolean expectFalseUserAccount = user1.equals(user2);
	}

}
