/**
 * 
 */
package com.unis.kevin.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.unis.kevin.vo.KindVO;

/**
 * @author founder
 *
 */
public class KindManager {

	/**
	 * 
	 */
	public KindManager() {
		// TODO Auto-generated constructor stub
	}

	public void insertKind(KindVO KindVo) {
		Connection conn = null;
		Statement st = null;
		int insertFlag = 0;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String KindInsertSQL = "INSERT INTO Kindtable(Kind_name,Kind_describe) VALUES('"+KindVo.getKindName()+"','"+KindVo.getKindDescribe()+"')";
			insertFlag = st.executeUpdate(KindInsertSQL);
			//System.out.println(insertFlag);
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
	public void updateKind(KindVO KindVo) {
		Connection conn = null;
		Statement st = null;
		int updateFlag = 0;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String KindUpdateSQL = 
			"UPDATE kindtable SET kind_name ='"+KindVo.getKindName()+
			"',kind_describe ='"+KindVo.getKindDescribe()+
			"' WHERE kind_id ="+KindVo.getKindId();
			updateFlag = st.executeUpdate(KindUpdateSQL);
			System.out.println(KindUpdateSQL);
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
	public ArrayList searchKindList() {
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		ArrayList KindList = new ArrayList();
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String KindListSQL = "SELECT kind_id,kind_name,kind_describe FROM kindtable WHERE kind_display = 1";
			rs = st.executeQuery(KindListSQL);
			while (rs.next()) {
				KindVO KindVo = new KindVO();
				KindVo.setKindId(rs.getInt("Kind_id"));
				KindVo.setKindName(rs.getString("Kind_name"));
				KindVo.setKindDescribe(rs.getString("Kind_describe"));
				KindList.add(KindVo);
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
		return KindList;
	}
	
	public KindVO searchKindById(String kindId) {
		KindVO KindVo = new KindVO();
		Connection conn = null;
		Statement st = null;
		ResultSet rs = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String KindInfoSQL = "SELECT kind_id,kind_name,kind_describe FROM kindtable WHERE kind_id = "+kindId;
			System.out.println(KindInfoSQL);
			rs = st.executeQuery(KindInfoSQL);
			while(rs.next()){
				KindVo.setKindId(rs.getInt("kind_id"));
				KindVo.setKindName(rs.getString("kind_name"));
				KindVo.setKindDescribe(rs.getString("kind_describe"));
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
		
		return KindVo;
		
	}
	public KindVO disableKindById(String kindId)
	{
		KindVO KindVo = new KindVO();
		Connection conn = null;
		Statement st = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=UTF-8", "root", "admin");
			st = conn.createStatement();
			String KinddisableSQL = 
			"UPDATE kindtable SET kind_display=0 WHERE kind_id = "+kindId;
			System.out.println(KinddisableSQL);
			st.executeUpdate(KinddisableSQL);
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
		return KindVo;
		
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

//		KindManager um = new KindManager();
//		KindVO uv = new KindVO();
//		uv.setKindName("kevin");
//		uv.setKindDescribe("123456");
//		um.insertKind(uv);
	}

}
