package com.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.jdbc.JDBC;
import com.vo.StudentVO;

public class SCDAO {
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private JDBC db = null;
	
	public void insertSC(String studentId,String[] courseId)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			for(int i=0;i<courseId.length;i++){
				String sql="INSERT INTO sctable(student_id,course_id,sc_grade)" +
				" VALUES("+
				"'"+studentId+"'," +
				"'"+courseId[i]+"',"+
				"'"+"1"+"')";
				System.out.println(sql);
				st.executeUpdate(sql);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(st, con);
		}
	}
}
