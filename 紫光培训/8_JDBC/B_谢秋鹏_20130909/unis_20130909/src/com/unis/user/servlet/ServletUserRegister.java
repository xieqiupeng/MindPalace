package com.unis.user.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.user.dao.UserDao;
import com.unis.user.vo.UserVo;

public class ServletUserRegister extends HttpServlet {

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out
				.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		out.print("    This is ");
		out.print(this.getClass());
		out.println(", using the GET method");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		String userProvince = request.getParameter("userProvince");
		String userCity = request.getParameter("userCity");
		String userSex = request.getParameter("userSex");
		String[] userHobby = request.getParameterValues("userHobby");
		String userDescribe = request.getParameter("userDescribe");
		
		String userHobbyString="";
		for(int i=0;i<userHobby.length;i++)
		{
			if(i==0)
			{
				userHobbyString=userHobbyString+userHobby[i];
			}
			else
			{
				userHobbyString=userHobbyString+","+userHobby[i]; 
			}
		}
		UserVo userVo = new UserVo();
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		userVo.setUserProvince(userProvince);
		userVo.setUserCity(userCity);
		userVo.setUserSex(userSex);
		userVo.setUserHobbyString(userHobbyString);
		userVo.setUserDescribe(userDescribe);
		
		
		
		UserDao userDao = new UserDao();
		userDao.insertUser(userVo);
		
		System.out.println(userName+","+userPassword+","+userProvince+","+userCity+","+userSex+","+userHobbyString+","+userDescribe);
	}

}
