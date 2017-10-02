package com.unis.user.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.unis.dbmanage.DBmanage;
import com.unis.user.vo.UserVO;

public class UserDao {
	public void insertUser(UserVO userVo)
	{
		Connection conn =null;
		Statement stm =null;
		try {
			conn = DBmanage.initDB();
			stm =conn.createStatement();
			String sql ="insert into usertable(user_name,user_password,user_province,user_city,user_sex,user_hobby,user_describe)" +
					" values('" +
					userVo.getUserName()+"','"+
					userVo.getUserPassword()+"','"+
					userVo.getProvince()+"','"+
					userVo.getCity()+"','"+
					userVo.getUserSex()+"','"+
					userVo.getHobby()+"','"+
					userVo.getDescribe()+"')";
			System.out.println(sql);
			int insertFlag= 0;
			insertFlag =stm.executeUpdate(sql);
			System.out.println(insertFlag);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(stm,conn);
		}
	}
	public boolean judgeUserPassword(UserVO userVo)
	{
		Connection conn=null;
		Statement stm=null;
		ResultSet rs =null;
		boolean checkNull=true;
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			String sql="select user_name from usertable where " +
					"user_name='"+userVo.getUserName()+"' AND "+
					"user_password='"+userVo.getUserPassword()+"'";
			System.out.println(sql);
			rs =stm.executeQuery(sql);
			if(rs.next()==true)
			{
				checkNull=false;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(rs, stm, conn);
		}
		return checkNull;
	}
	public boolean judgeUserName(String userName)
	{
		Connection conn=null;
		Statement stm=null;
		ResultSet rs =null;
		boolean checkNull=false;
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			String sql="select user_name from usertable where " +
					"user_name='"+userName+"'";
			System.out.println(sql);
			rs =stm.executeQuery(sql);
			if(rs.next()==false)
			{
				checkNull=true;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally{
			DBmanage.closeDB(rs, stm, conn);
		}
		return checkNull;
	}
	public ArrayList selectUserNotDeleteList()
	{
		Connection conn=null;
		Statement stm=null;
		ResultSet rs =null;
		ArrayList<UserVO> list =new ArrayList<UserVO>();
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			String sql="Select user_id,user_name,user_password,user_province,user_city from usertable where user_display=1";
			System.out.println(sql);
			rs =stm.executeQuery(sql);
			System.out.println(rs);
			while(rs.next())
			{	
				UserVO userVo =new UserVO();
				userVo.setUserId(rs.getString("user_id"));
				userVo.setUserName(rs.getString("user_name"));
				userVo.setUserPassword(rs.getString("user_password"));
				userVo.setProvince(rs.getString("user_province"));
				userVo.setCity(rs.getString("user_city"));
				list.add(userVo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(rs,stm,conn); 
		}
		return list;
	}
	public void deleteOneUser(String userId)
	{
		Connection conn=null;
		Statement stm=null;
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			String sql="Update usertable SET user_display=0 where user_id='" +userId+"'";
			System.out.println(sql);
			stm.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(stm,conn);
		}
	}
	public void deleteUserList(String[] userIdString)
	{
		Connection conn=null;
		Statement stm=null;
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			for (int i=0;i<userIdString.length;i++)
			{
				String sql="Update usertable SET user_display=0 where user_id='" +userIdString[i]+"'";
				System.out.println(sql);
				stm.executeUpdate(sql);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(stm,conn);
		}
	}
	public UserVO selectOneUserInfo(String userId)
	{
		Connection conn=null;
		Statement stm=null;
		ResultSet rs =null;
		UserVO userVo =new UserVO();
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			String sql="Select user_name,user_password,user_province,user_city,user_sex,user_hobby,user_describe from usertable " +
					"where user_id=" +userId+"";
			System.out.println(sql);
			rs =stm.executeQuery(sql);
			rs.next();
			userVo.setUserId(userId);
			userVo.setUserName(rs.getString("user_name"));
			userVo.setUserPassword(rs.getString("user_password"));
			userVo.setProvince(rs.getString("user_province"));
			userVo.setCity(rs.getString("user_city"));
			userVo.setUserSex(rs.getString("user_sex"));
			userVo.setHobby(rs.getString("user_hobby"));
			userVo.setDescribe(rs.getString("user_describe"));
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(rs,stm,conn);
		}
		return userVo;
	}
	public void updateOneUser(UserVO userVo)
	{
		Connection conn=null;
		Statement stm=null;
		try {
			conn =DBmanage.initDB();
			stm =conn.createStatement();
			String sql="Update usertable SET " +
			"user_name='" +userVo.getUserName()+
			"',user_password='" +userVo.getUserPassword()+
			"',user_province='" +userVo.getProvince()+
			"',user_city='" +userVo.getCity()+
			"',user_sex='" +userVo.getUserSex()+
			"',user_hobby='" +userVo.getHobby()+
			"',user_describe='" +userVo.getDescribe()+
			"' where user_id='"+userVo.getUserId()+"'";
			System.out.println(sql);
			stm.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			DBmanage.closeDB(stm,conn);
		}
	}
}