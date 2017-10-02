package com.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.jdbc.JDBC;
import com.vo.CourseVO;

public class CourseDAO {
	
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private JDBC db = null;
	
	public void insertCourse(CourseVO courseVo)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="INSERT INTO coursetable(course_name,teacher_id,course_describe)" +
				" VALUES("+
				"'"+courseVo.getCourseName()+"'," +
				"'"+courseVo.getTeacherId()+"'," +
				"'"+courseVo.getCourseDescribe()+"')";
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
	
	public ArrayList<CourseVO> selectCourseList()
	{
		CourseVO courseVo = null;
		ArrayList<CourseVO> courseList = null;
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT course_id,course_name,teacher_id,course_describe FROM coursetable WHERE course_display=1";
			System.out.println(sql);
			rs = st.executeQuery(sql);
			courseList = new ArrayList<CourseVO>();
			while(rs.next())
			{
				courseVo = new CourseVO();
				courseVo.setCourseId(rs.getString("course_id"));
				courseVo.setCourseName(rs.getString("course_name"));
				courseVo.setTeacherId(rs.getString("teacher_id"));
				courseVo.setCourseDescribe(rs.getString("course_describe"));
				courseList.add(courseVo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return courseList;
	}
	
	public void disableCourse(String courseId)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="UPDATE coursetable SET course_display=0 WHERE course_id ="+courseId;
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
	
	public CourseVO selectOneCourse(String courseId)
	{
		db = new JDBC();
		con =db.initDB();
		CourseVO courseVo =new CourseVO();
		try {
			st = con.createStatement();
			String sql="SELECT course_name,teacher_id,course_describe FROM coursetable " +
					"WHERE course_id ="+courseId;
			System.out.println(sql);
			rs =st.executeQuery(sql);
			rs.next();
			courseVo.setCourseId(courseId);
			courseVo.setCourseName(rs.getString("course_name"));
			courseVo.setTeacherId(rs.getString("teacher_id"));
			courseVo.setCourseDescribe(rs.getString("course_describe"));
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return courseVo;
	}
	
	public void updateCourse(CourseVO courseVo)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();			
			String sql="Update coursetable " +
					"SET course_name="+"'"+courseVo.getCourseName()+"', "+ 
					"teacher_id="+"'"+courseVo.getTeacherId()+"', " +
					"course_describe="+"'"+courseVo.getCourseDescribe()+"' "+
					"WHERE course_id="+courseVo.getCourseId();
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
	public ArrayList<String> selectCourseByStudent(String studentId)
	{
		db = new JDBC();
		con =db.initDB();
		ArrayList<String> courseIdArray=new ArrayList<String>();
		try {
			st = con.createStatement();
			String sql="SELECT course_id FROM sctable " +
					"WHERE student_id ="+studentId;
			System.out.println(sql);
			rs =st.executeQuery(sql);
			while(rs.next())
			{
				String courseId =rs.getString("course_id");
				courseIdArray.add(courseId);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return courseIdArray;
	}
	public ArrayList<String> selectCourseById(ArrayList<String> courseIdArray)
	{
		db = new JDBC();
		con =db.initDB();
		ArrayList<String> courseNameArray =new ArrayList<String>();
		try {
			st = con.createStatement();
			for(int i=0;i<courseIdArray.size();i++)
			{
				String sql="SELECT course_name FROM coursetable " +
						"WHERE course_id ="+courseIdArray.get(i);
				System.out.println(sql);
				rs =st.executeQuery(sql);
				while(rs.next())
				{
					String courseName=rs.getString("course_name");
					courseNameArray.add(courseName);
				}
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return courseNameArray;
	}
}
