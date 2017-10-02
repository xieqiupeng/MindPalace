package com.unis.dbmanage;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBmanage {	
	public static Connection initDB()
	{
		String driver="com.mysql.jdbc.Driver";
		String url="jdbc:mysql://localhost:3306/userdb?characterEncoding=UTF-8";
		String root="root";
		String password="admin";
		
		Connection conn =null;
		try {
			Class.forName(driver);
			conn=DriverManager.getConnection(url,root,password); 
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return conn;
	}
	public static void closeDB(Statement stm,Connection conn)
	{
			try {
				stm.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	public static void closeDB(ResultSet rs,Statement stm,Connection conn) 
	{
			try {
				rs.close();
				stm.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
}