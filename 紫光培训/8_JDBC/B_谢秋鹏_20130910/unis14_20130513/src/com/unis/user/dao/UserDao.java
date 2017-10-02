package com.unis.user.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.unis.dbmanage.DBmanage;
import com.unis.user.vo.UserVo;

public class UserDao {
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private DBmanage db = null;
	//�û�ע�᷽��
	public void insertUser(UserVo userVo)
	{
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="INSERT INTO userTable(" +
					"user_name,user_password,user_province,user_city,user_sex,user_hobby,user_describe)" +
					" VALUES('"+userVo.getUserName()+"'," +
					"'"+userVo.getUserPassword()+"'," +
					"'"+userVo.getUserProvince()+"'," +
					"'"+userVo.getUserCity()+"'," +
					"'"+userVo.getUserSex()+"'," +
					"'"+userVo.getUserHobby()+"'," +
					"'"+userVo.getUserDescribe()+"')";
			st.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st);
		}
	}
	//�ж��û����������Ƿ����
	public UserVo judgeUserPassword(String userName)
	{
		UserVo userVo = null;
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT user_name,user_password FROM userTable WHERE user_name='"+userName+"' AND user_display=1";
			rs = st.executeQuery(sql);
			while(rs.next())
			{
				userVo = new UserVo();
				userVo.setUserName(rs.getString("user_name"));
				userVo.setUserPassword(rs.getString("user_password"));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st, rs);
		}
		return userVo;
	}
	//��ѯ������û��ɾ�����û��б�
	public ArrayList<UserVo> selectUserNotDeleteList()
	{
		UserVo userVo = null;
		ArrayList<UserVo> userList = null;
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT user_id,user_name,user_password,user_province,user_city FROM userTable WHERE user_display=1";
			rs = st.executeQuery(sql);
			userList = new ArrayList<UserVo>();
			while(rs.next())
			{
				userVo = new UserVo();
				userVo.setUserId(rs.getInt("user_id"));
				userVo.setUserName(rs.getString("user_name"));
				userVo.setUserPassword(rs.getString("user_password"));
				userVo.setUserProvince(rs.getString("user_province"));
				userVo.setUserCity(rs.getString("user_city"));
				userList.add(userVo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st, rs);
		}
		return userList;
	}
	//ɾ�������û�
	public void deleteOneUser(int userId)
	{
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="UPDATE userTable SET user_display=0 WHERE user_id="+userId;
			st.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st);
		}
	}
	//����id��ѯ��һ���û���Ϣ
	public UserVo selectOneUserInfo(int userId)
	{
		UserVo userVo = null;
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT user_id,user_name,user_password,user_province,user_city,user_sex,user_hobby,user_describe FROM userTable WHERE user_id="+userId;
			rs = st.executeQuery(sql);
			while(rs.next())
			{
				userVo = new UserVo();
				userVo.setUserId(rs.getInt("user_id"));
				userVo.setUserName(rs.getString("user_name"));
				userVo.setUserPassword(rs.getString("user_password"));
				userVo.setUserProvince(rs.getString("user_province"));
				userVo.setUserCity(rs.getString("user_city"));
				userVo.setUserSex(rs.getString("user_sex"));
				userVo.setUserHobby(rs.getString("user_hobby"));
				userVo.setUserDescribe(rs.getString("user_describe"));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st, rs);
		}
		return userVo;
	}
	//�����û�id���޸�һ���û���Ϣ
	public void updateUser(UserVo userVo)
	{
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="UPDATE userTable SET user_name='"+userVo.getUserName()+"',user_password='"+userVo.getUserPassword()+"',user_province='"+userVo.getUserProvince()+"',user_city='"+userVo.getUserCity()+"',user_sex='"+userVo.getUserSex()+"',user_hobby='"+userVo.getUserHobby()+"',user_describe='"+userVo.getUserDescribe()+"' WHERE user_id="+userVo.getUserId();
			st.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st);
		}
	}
	//ɾ������û�
	public void deleteUserList(String[] userIdString)
	{
		db = new DBmanage();
		con =db.initDB();
		try {
			st = con.createStatement();
			for (int i = 0; i < userIdString.length; i++) {
				String sql="UPDATE userTable SET user_display=0 WHERE user_id="+userIdString[i];
				st.executeUpdate(sql);
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(con, st);
		}
	}
	
	public boolean ajaxJudgeUserName(String userName)
	{
		db = new DBmanage();
		con =db.initDB();
		boolean temp=false;
		try {
			st = con.createStatement();
			String sql="SELECT * FROM userTable WHERE user_name='"+userName+"'";
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
			db.closeDB(con, st);
		}
		return temp;
	}
}
