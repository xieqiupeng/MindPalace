package com.unis.user.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.unis.dbmanage.DBmanage;
import com.unis.user.vo.UserVo;

public class UserDao {
	public void insertUser(UserVo userVo)
	{
		DBmanage dbManage = new DBmanage();
		Connection conn = dbManage.initDB();
		Statement st = null;
		try {
			st = conn.createStatement();
			String sql = "INSERT INTO userTable (user_name,user_password,user_province,user_city,user_sex,user_hobby,user_describe) values('"+userVo.getUserName()+"','"+userVo.getUserPassword()+"','"+userVo.getUserProvince()+"','"+userVo.getUserCity()+"','"+userVo.getUserSex()+"','"+userVo.getUserHobbyString()+"','"+userVo.getUserDescribe()+"')";
			System.out.println(sql);
			st.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			dbManage.closeDB(st, conn);
		}
	}
	
	public boolean judgePassword(String userName,String userPassword)
	{
		DBmanage dbManage = new DBmanage();
		ResultSet rs = null;
		Connection conn = dbManage.initDB();
		Statement st = null;
		boolean temp = false;
		try {
			st = conn.createStatement();
			String sql = "SELECT * FROM userTable WHERE user_name='"+userName+"' AND user_password='"+userPassword+"'";
			System.out.println(sql);
			rs = st.executeQuery(sql);
			if(rs.next())
			{
				temp=true;
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			dbManage.closeDB(rs ,st, conn);
		}
		return temp;
	}
}
