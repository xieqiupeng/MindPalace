package com.unis.kevin.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.kevin.db.UserManager;
import com.unis.kevin.vo.UserVO;

public class ServletInsertUser extends HttpServlet {

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

		//设置请求的字符集格式
		request.setCharacterEncoding("UTF-8");
		
		//设置响应的字符集格式
		response.setCharacterEncoding("UTF-8");
		
		//获取前台表单项的值
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		
		//实例化UserVO
		UserVO userVo = new UserVO();
		
		//将获取的表单项的值存放在userVo中
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		
		//实例化UserManager
		UserManager um = new UserManager();
		
		//调用insertUser方法，传入句柄userVo
		um.insertUser(userVo);
		
		//跳转
		request.getRequestDispatcher("/servlet/ServletUserList").forward(request, response);
		
	}

}
