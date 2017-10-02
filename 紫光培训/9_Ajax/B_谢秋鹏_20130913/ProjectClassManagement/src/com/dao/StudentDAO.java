package com.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.jdbc.JDBC;
import com.vo.StudentVO;

public class StudentDAO {
	
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private JDBC db = null;
	
	public String insertStudent(StudentVO studentVo)
	{
		db = new JDBC();
		con =db.initDB();
		String str ="";
		try {
			st = con.createStatement();
			String sql="INSERT INTO studenttable(student_name,student_sex,student_age,student_major,class_id)" +
				" VALUES("+
				"'"+studentVo.getStudentName()+"'," +
				"'"+studentVo.getStudentSex()+"'," +
				"'"+studentVo.getStudentAge()+"'," +
				"'"+studentVo.getStudentMajor()+"'," +
				"'"+studentVo.getClassId()+"')";
			System.out.println(sql);
			st.executeUpdate(sql);
			String returnSQL ="select @@Identity";
			rs= st.executeQuery(returnSQL);
			rs.next();
			str =rs.getString(1);
			System.out.println("studentId="+str);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(st, con);
		}
		return str;
	}
	
	public ArrayList<StudentVO> selectStudentList()
	{
		StudentVO studentVo = null;
		ArrayList<StudentVO> list = null;
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT student_id,student_name,student_sex,student_age,student_major,classtable.class_id,class_name" +
					" FROM studenttable,classtable " +
					"WHERE classtable.class_id=studenttable.class_id and " +
					"student_display=1";
			System.out.println(sql);
			rs = st.executeQuery(sql);
			list = new ArrayList<StudentVO>();
			while(rs.next())
			{
				studentVo = new StudentVO();
				studentVo.setStudentId(rs.getString("student_id"));
				studentVo.setStudentName(rs.getString("student_name"));
				studentVo.setStudentSex(rs.getString("student_sex"));
				studentVo.setStudentAge(rs.getString("student_age"));
				studentVo.setStudentMajor(rs.getString("student_major"));
				studentVo.setClassId(rs.getString("class_id"));
				studentVo.setClassName(rs.getString("class_name"));
				list.add(studentVo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return list;
	}
	
	public ArrayList<StudentVO> selectStudentByClass(String classId)
	{
		StudentVO studentVo = null;
		ArrayList<StudentVO> list = null;
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT student_id,student_name,student_sex,student_age,student_major,classtable.class_id,class_name" +
					" FROM studenttable,classtable " +
					"WHERE classtable.class_id=studenttable.class_id and " +
					"classtable.class_id=" +classId+" and "+
					"student_display=1";
			System.out.println(sql);
			rs = st.executeQuery(sql);
			list = new ArrayList<StudentVO>();
			while(rs.next())
			{
				studentVo = new StudentVO();
				studentVo.setStudentId(rs.getString("student_id"));
				studentVo.setStudentName(rs.getString("student_name"));
				studentVo.setStudentSex(rs.getString("student_sex"));
				studentVo.setStudentAge(rs.getString("student_age"));
				studentVo.setStudentMajor(rs.getString("student_major"));
				studentVo.setClassId(rs.getString("class_id"));
				studentVo.setClassName(rs.getString("class_name"));
				list.add(studentVo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return list;
	}
	public StudentVO selectStudentById(String studentId)
	{
		StudentVO studentVo = null;
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT student_name,student_sex,student_age,student_major,class_id" +
					" FROM studenttable " +
					"WHERE student_id=" +studentId;
			System.out.println(sql);
			rs = st.executeQuery(sql);
			rs.next();
			studentVo = new StudentVO();
			studentVo.setStudentId(studentId);
			studentVo.setStudentName(rs.getString("student_name"));
			studentVo.setStudentSex(rs.getString("student_sex"));
			studentVo.setStudentAge(rs.getString("student_age"));
			studentVo.setStudentMajor(rs.getString("student_major"));
			studentVo.setClassId(rs.getString("class_id"));
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		finally
		{
			db.closeDB(rs, st, con);
		}
		return studentVo;
	}
	
	public void disableStudent(String studentId)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="UPDATE studenttable SET student_display=0 WHERE student_id ="+studentId;
			System.out.println(sql);
			st.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(st, con);
		}
	}
	
	public void updateStudent(StudentVO studentVo)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();			
			String sql="Update studenttable " +
					"SET student_name="+"'"+studentVo.getClassName()+"', "+ 
					"student_sex="+"'"+studentVo.getStudentName()+"', " +
					"student_age="+"'"+studentVo.getStudentAge()+"', " +
					"student_major="+"'"+studentVo.getStudentMajor()+"', " +
					"class_id="+"'"+studentVo.getClassId()+"', " +
					"WHERE student_id="+studentVo.getStudentId();
			System.out.println(sql);
			st.executeUpdate(sql);
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
