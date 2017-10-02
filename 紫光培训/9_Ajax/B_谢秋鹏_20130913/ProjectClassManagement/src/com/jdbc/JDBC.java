package com.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBC {
	
	//与数据库建立连接
	public Connection initDB()
	{
		String driver ="com.mysql.jdbc.Driver";
		String url ="jdbc:mysql://localhost:3306/userdb?characterEncoding=UTF-8";
		String root ="root";
		String password ="admin";
		Connection conn = null;
		
		try {
			Class.forName(driver);
			conn =DriverManager.getConnection(url,root,password);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return conn;
	}
	
	//关闭executeUpdate类型的查询
	public void closeDB(Statement st,Connection conn)
	{
		try {
			st.close();
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	//关闭executeQuery类型的查询
	public void closeDB(ResultSet rs,Statement st,Connection conn)
	{
		try {
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
