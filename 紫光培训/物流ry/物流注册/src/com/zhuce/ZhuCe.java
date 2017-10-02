package com.zhuce;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ZhuCe extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public ZhuCe() {
		super();
	}

	/**
	 * Destruction of the servlet. <br>
	 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

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

		response.setContentType("text/html");
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");

		//用户名
		String userName = request.getParameter("userName");
		request.setAttribute("userName",userName );
		
		//密码
		String userPassword = request.getParameter("userPassword");
		request.setAttribute("userPassword",userPassword );

		//性别
		String userSex = request.getParameter("userSex");
		request.setAttribute("userSex",userSex );

		//手机号
		String userPhone = request.getParameter("userPhone");
		request.setAttribute("userPhone",userPhone);
		
		//学校和宿舍
		String userSchool = request.getParameter("userSchool");
		request.setAttribute("userSchool",userSchool );
		String userDormitory = request.getParameter("userDormitory");
		request.setAttribute("userDormitory",userDormitory );
		
		//有效证件号码
		String idNumer = request.getParameter("idNumer");
		request.setAttribute("idNumer",idNumer );
		
		//跳转
		request.getRequestDispatcher("/success.jsp").forward(request, response);
	}

	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}

}
