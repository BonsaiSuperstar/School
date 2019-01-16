package fbAcc3;

public class Undoer {
	private int action;
	private FacebookUser value;
	private FacebookUser user;
	
	Undoer(int a, FacebookUser v, FacebookUser u){
		this.action = a;
		this.value = v;
		this.user = u;
	}

	public int getAction() {
		return action;
	}

	public void setAction(int action) {
		this.action = action;
	}

	public FacebookUser getValue() {
		return value;
	}

	public void setValue(FacebookUser value) {
		this.value = value;
	}

	public FacebookUser getUser() {
		return user;
	}

	public void setUser(FacebookUser user) {
		this.user = user;
	}
	
}
