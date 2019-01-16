package fbAcc3;

import java.io.Serializable;

@SuppressWarnings("serial")
public abstract class UserAccount implements Serializable{

	private String username;
	private String password;
	private boolean active;
	
	public UserAccount(){
		
	}
	
	public UserAccount(String name, String pass){
		this.username = name;
		this.password = pass;
		this.active = true;
	}
		
	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public boolean isActive() {
		return active;
	}

	public void setActive(boolean active) {
		this.active = active;
	}

	public int hashCode() {
		return this.username.hashCode();
	}

	public boolean equals(UserAccount other) {
		return this.hashCode() == other.hashCode();
	}
	
	public boolean checkPassword(String password){
		if(password.equals(this.password)){
			return true;
		}
		else {
			return false;
		}
	}
	
	public void deactivateAccount(){
		this.active = false;
	}
	
	public String toString(){
		return this.username;
	}
	
	public abstract void getPasswordHelp();
}
