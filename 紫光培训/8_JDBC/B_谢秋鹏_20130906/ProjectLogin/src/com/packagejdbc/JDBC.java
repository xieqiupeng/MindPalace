/**
 * 
 */
package com.packagejdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import com.packagevo.VO;

/**
 * @author XQP
 *
 */
public class JDBC {

	public static Connection creatConnection() throws ClassNotFoundException, SQLException
	{
		String driver="com.mysql.jdbc.Driver";
		String url="jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8";
		String root="root";
		String password="admin";
		
		Class.forName(driver);
		Connection conn =DriverManager.getConnection(url,root,password);
		return conn;
	}
	/**
	 * 
	 */
	public JDBC() {
		// TODO Auto-generated constructor stub
	}

}
