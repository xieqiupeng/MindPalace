/**
 * 
 */
package com.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.jdbc.JDBC;
import com.vo.ClassVO;
import com.vo.StudentVO;

/**
 * SQLOperation
 * @author XQP
 *
 */
public class ClassDAO {
	
	private Connection con;
	private Statement st;
	private ResultSet rs;
	private JDBC db = null;
	
	public void insertClass(ClassVO classVo)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="INSERT INTO classtable(class_name,class_master,class_describe)" +
				" VALUES("+
				"'"+classVo.getClassName()+"'," +
				"'"+classVo.getClassMaster()+"'," +
				"'"+classVo.getClassDescribe()+"')";
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
		
	public ArrayList<ClassVO> selectClassList()
	{
		ClassVO classVo = null;
		ArrayList<ClassVO> classList = null;
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql = "SELECT class_id,class_name,class_master,class_describe FROM classtable WHERE class_display=1";
			System.out.println(sql);
			rs = st.executeQuery(sql);
			classList = new ArrayList<ClassVO>();
			while(rs.next())
			{
				classVo = new ClassVO();
				classVo.setClassId(rs.getString("class_id"));
				classVo.setClassName(rs.getString("class_name"));
				classVo.setClassMaster(rs.getString("class_master"));
				classVo.setClassDescribe(rs.getString("class_describe"));
				classList.add(classVo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return classList;
	}
	public void disableClass(String classId)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();
			String sql="UPDATE classtable SET class_display=0 WHERE class_id ="+classId;
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
	
	public void updateClass(ClassVO classVo)
	{
		db = new JDBC();
		con =db.initDB();
		try {
			st = con.createStatement();			
			String sql="Update classtable " +
					"SET class_name="+"'"+classVo.getClassName()+"', "+ 
					"class_master="+"'"+classVo.getClassMaster()+"', " +
					"class_describe="+"'"+classVo.getClassDescribe()+"' "+
					"WHERE class_id="+classVo.getClassId();
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
	
	public ClassVO selectOneClass(String classId)
	{
		db = new JDBC();
		con =db.initDB();
		ClassVO classVo =new ClassVO();
		try {
			st = con.createStatement();
			String sql="SELECT class_name,class_master,class_describe FROM classtable " +
					"WHERE class_id ="+classId;
			rs =st.executeQuery(sql);
			rs.next();
			classVo.setClassId(classId);
			classVo.setClassName(rs.getString("class_name"));
			classVo.setClassMaster(rs.getString("class_master"));
			classVo.setClassDescribe(rs.getString("class_describe"));
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			db.closeDB(rs, st, con);
		}
		return classVo;
	}
}