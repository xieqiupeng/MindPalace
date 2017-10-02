package com.PackageJDBC;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.PackageVO.TeacherVO;
//import com.mysql.jdbc.Statement;

public class JDBC {
	
	public void insertTeacher(TeacherVO teachervo) throws SQLException
	{
		Statement stm =null;
		Connection conn=null;
		int insertFlag =0;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn=DriverManager.getConnection
			("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=utf-8", "root","admin");
			stm=conn.createStatement();
			String sql =
			"INSERT INTO teachertable(teacher_number,teacher_name,teacher_sex,teacher_birth,teacher_worktime,teacher_address)" +
			"VALUES ('"+
			teachervo.getTeacherNum()+"','"+
			teachervo.getTeacherName()+"','"+
			teachervo.getTeacherSex()+"','"+
			teachervo.getTeacherBirth()+"','"+
			teachervo.getTeacherWorktime()+"','"+
			teachervo.getTeacherAddress()+"')";
			System.out.println(sql);
			insertFlag =stm.executeUpdate(sql);		
		}
		catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void updateTeacher( TeacherVO teacherVo) {
		Connection conn = null;
		Statement st = null;
		int updateFlag = 0;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String sql = 
			"UPDATE teachertable SET teacher_number ='"+teacherVo.getTeacherNum()+
			"',teacher_name ='"+teacherVo.getTeacherName()+
			"',teacher_sex ='"+teacherVo.getTeacherSex()+
			"',teacher_birth ='"+teacherVo.getTeacherBirth()+
			"',teacher_worktime ='"+teacherVo.getTeacherWorktime()+
			"',teacher_address ='"+teacherVo.getTeacherAddress()+
			"' WHERE teacher_id ="+teacherVo.getTeacherId();
			System.out.println(sql);
			updateFlag = st.executeUpdate(sql);
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
	public ArrayList searchTeacherList() {
		Connection conn =null;
		Statement st =null;
		ResultSet rs =null;
		ArrayList teacherList =new ArrayList();
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn =DriverManager.getConnection
			("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=utf-8","root","admin");
			st =conn.createStatement();
			String sql ="Select teacher_id,teacher_number,teacher_name,teacher_sex,teacher_birth,teacher_worktime,teacher_address" +
			" FROM teachertable";
			System.out.println(sql);
			rs =st.executeQuery(sql);
			while(rs.next()==true)
			{
				TeacherVO teachervo =new TeacherVO();
				teachervo.setTeacherId(rs.getString("teacher_id"));
				teachervo.setTeacherNum(rs.getString("teacher_number"));
				teachervo.setTeacherName(rs.getString("teacher_name"));
				teachervo.setTeacherSex(rs.getString("teacher_sex"));
				teachervo.setTeacherBirth(rs.getString("teacher_birth"));
				teachervo.setTeacherWorktime(rs.getString("teacher_worktime"));
				teachervo.setTeacherAddress(rs.getString("teacher_address"));
				teacherList.add(teachervo);
			}
		}
		catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally{
			try {
				rs.close();
				st.close();
				conn.close();
			} 
			catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return teacherList;
	}

	public TeacherVO searchInfoById(String teacherId) {
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		TeacherVO teacherVo = new TeacherVO();
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String sql ="Select teacher_id,teacher_number,teacher_name,teacher_sex,teacher_birth,teacher_worktime,teacher_address" +
			" FROM teachertable"+
			" WHERE teacher_id = "+teacherId;
			System.out.println(sql);
			rs = st.executeQuery(sql);
			while(rs.next()){
				teacherVo.setTeacherId(rs.getString("teacher_id"));
				teacherVo.setTeacherNum(rs.getString("teacher_number"));
				teacherVo.setTeacherName(rs.getString("teacher_name"));
				teacherVo.setTeacherSex(rs.getString("teacher_sex"));
				teacherVo.setTeacherBirth(rs.getString("teacher_birth"));
				teacherVo.setTeacherWorktime(rs.getString("teacher_worktime"));
				teacherVo.setTeacherAddress(rs.getString("teacher_address"));
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
		return teacherVo;
	}
	
	public TeacherVO disableTeacher(String teacherId)
	{
		TeacherVO teacherVo = new TeacherVO();
		Connection conn = null;
		Statement st = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String sql = 
			"UPDATE teachertable SET teacher_display=0 WHERE teacher_id = "+teacherId;
			System.out.println(sql);
			st.executeUpdate(sql);
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
		return teacherVo;	
	}
	/**
	 * @param args
	 * @throws SQLException 
	 */
	public static void main(String[] args) throws SQLException {
		// TODO Auto-generated method stub
		//insertTeacher≤‚ ‘∑Ω∑®
//		JDBC jdbc= new JDBC();	
//		TeacherVO teachervo =new TeacherVO();
//		teachervo.setTeacherNum("1004030323");
//		teachervo.setTeacherName("–ª«Ô≈Ù");
//		teachervo.setTeacherSex("ƒ–");
//		teachervo.setTeacherBirth("1990-1-2");
//		teachervo.setTeacherWorktime("1995-2-2");
//		teachervo.setTeacherAddress("ÃÏ«≈");
//		jdbc.insertTeacher(teachervo);
		
		//searchTeacherList≤‚ ‘∑Ω∑®
//		JDBC jdbc =new JDBC();	
//		ArrayList teacherList =jdbc.searchTeacherList();
//		for (int i=0;i<teacherList.size();i++)
//		{
//			TeacherVO teachervo =(TeacherVO)teacherList.get(i);
//			System.out.println(teachervo.getTeacherId());
//			System.out.println(teachervo.getTeacherNum());
//			System.out.println(teachervo.getTeacherName());
//			System.out.println(teachervo.getTeacherSex());
//			System.out.println(teachervo.getTeacherBirth());
//			System.out.println(teachervo.getTeacherWorktime());
//			System.out.println(teachervo.getTeacherAddress());
		}
		//updateTeacher≤‚ ‘
//		JDBC jdbc= new JDBC();	
//		TeacherVO teacherVo =new TeacherVO();
//		teacherVo.getTeacherId("1");
//		teacherVo.setTeacherNum("1004030323");
//		teacherVo.setTeacherName("–ª«Ô≈Ù");
//		teacherVo.setTeacherSex("ƒ–");
//		teacherVo.setTeacherBirth("1990-1-2");
//		teacherVo.setTeacherWorktime("1995-2-2");
//		teacherVo.setTeacherAddress("ÃÏ«≈");
//		jdbc.updateTeacher(teacherVo);
	}