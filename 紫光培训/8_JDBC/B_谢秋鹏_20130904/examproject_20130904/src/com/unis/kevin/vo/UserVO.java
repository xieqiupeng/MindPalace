/**
 * 
 */
package com.unis.kevin.vo;

/**
 * @author founder
 *
 */
public class UserVO {

	/**
	 * 
	 */
	public UserVO() {
		// TODO Auto-generated constructor stub
	}
	
	private int userId;
	private String userName;
	private String userPassword;
	private int userDisplay;
	public int getUserId() {
		return userId;
	}
	public void setUserId(int userId) {
		this.userId = userId;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getUserPassword() {
		return userPassword;
	}
	public void setUserPassword(String userPassword) {
		this.userPassword = userPassword;
	}
	public int getUserDisplay() {
		return userDisplay;
	}
	public void setUserDisplay(int userDisplay) {
		this.userDisplay = userDisplay;
	}

}
