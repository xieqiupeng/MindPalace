package com.packagejdbc;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.packagevo.VO;

public class SQLOperation {

	public String check(VO vo) throws SQLException, ClassNotFoundException
	{
		Connection conn =JDBC.creatConnection();
		Statement stm = conn.createStatement();
		String sql="Select user_name From usertable" +
		" Where user_name='" +vo.getUserName()+
		"' AND "+
		"user_password='"+vo.getUserPassword()+
		"'";
		System.out.println(sql);
		ResultSet rs =stm.executeQuery(sql);
		boolean flag =  rs.next();
		String str="确有此人";
		System.out.println(rs);
		if(flag == false){
			str="用户名密码错误！";
		}
		return str;
	}
}