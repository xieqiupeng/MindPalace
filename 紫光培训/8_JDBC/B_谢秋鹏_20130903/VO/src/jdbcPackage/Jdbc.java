package jdbcPackage;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

import voPackage.UserVo;

public class Jdbc {
	public void insertUser(UserVo userVo)
	{
		Statement str=null;
		Connection con=null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			con=DriverManager.getConnection
			("jdbc:mysql://localhost:3306/jdbc_database_user?characterEncoding=utf-8", "root","admin");
			str =con.createStatement();
			String sql ="INSERT INTO table_user(user_name,user_password)VALUES ('"+
			userVo.getUserName()+"','"+
			userVo.getUserPassword()+"')";
			System.out.println(sql);
			str.executeUpdate(sql);
		} 
		catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();	
		}
		finally
		{
			try {
				str.close();
				con.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	public static void main(UserVo userVo)
	{
		Jdbc testDB= new Jdbc();
		testDB.insertUser(userVo);
		//System.out.println("123kjhjuhgi45");
	}
}