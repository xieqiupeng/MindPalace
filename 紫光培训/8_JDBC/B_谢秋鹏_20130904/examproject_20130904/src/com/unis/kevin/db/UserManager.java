/**
 * 
 */
package com.unis.kevin.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.unis.kevin.vo.UserVO;

/**
 * @author founder
 *
 */
public class UserManager {

	/**
	 * 
	 */
	public UserManager() {
		// TODO Auto-generated constructor stub
	}

	public void insertUser(UserVO userVo) {
		Connection conn = null;
		Statement st = null;
		int insertFlag = 0;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/userinfodb?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String userInsertSQL = "INSERT INTO usertable(user_name,user_password) VALUES('"+userVo.getUserName()+"','"+userVo.getUserPassword()+"')";
			insertFlag = st.executeUpdate(userInsertSQL);
			System.out.println(insertFlag);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally{
			try {
				st.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	public ArrayList searchUserList() {
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		ArrayList userList = new ArrayList();
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/userinfodb?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String userListSQL = "SELECT user_id,user_name,user_password FROM usertable WHERE user_display = 1";
			rs = st.executeQuery(userListSQL);
			while (rs.next()) {
				UserVO userVo = new UserVO();
				userVo.setUserId(rs.getInt("user_id"));
				userVo.setUserName(rs.getString("user_name"));
				userVo.setUserPassword(rs.getString("user_password"));
				userList.add(userVo);
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally{
			try {
				rs.close();
				st.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return userList;
	}
	
	public UserVO searchUserById(String userId) {
		UserVO userVo = new UserVO();
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/userinfodb?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String userInfoSQL = "SELECT user_id,user_name,user_password FROM usertable WHERE user_id = "+userId;
			System.out.println(userInfoSQL);
			rs = st.executeQuery(userInfoSQL);
			while(rs.next()){
				userVo.setUserId(rs.getInt("user_id"));
				userVo.setUserName(rs.getString("user_name"));
				userVo.setUserPassword(rs.getString("user_password"));
			}
				
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally{
			try {
				rs.close();
				st.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		
		return userVo;
		
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

//		UserManager um = new UserManager();
//		UserVO uv = new UserVO();
//		uv.setUserName("kevin");
//		uv.setUserPassword("123456");
//		um.insertUser(uv);
	}

}
