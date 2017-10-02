package com.PackageServlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.PackageJDBC.JDBC;
import com.PackageVO.TeacherVO;

public class ServletInsertTeacher extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public ServletInsertTeacher() {
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
		
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");

		String teacherNum =request.getParameter("teacherNum");
		String teacherName =request.getParameter("teacherName");
		String teacherSex =request.getParameter("teacherSex");
		String[] teacherBirthArray =request.getParameterValues("teacherBirth");
		String teacherBirth ="";
		for (int i=0;i<3;i++)
		{
			if(i==2)
			{
				teacherBirth = teacherBirth+teacherBirthArray[i];
			}
			else{
				teacherBirth = teacherBirth+teacherBirthArray[i]+"-";
			}
		}
		String[] teacherWorktimeArray =request.getParameterValues("teacherWorktime");
		String teacherWorktime ="";
		for (int i=0;i<3;i++)
		{
			if(i==2)
			{
				teacherWorktime = teacherWorktime+teacherWorktimeArray[i];
			}
			else
			{
				teacherWorktime = teacherWorktime+teacherWorktimeArray[i]+"-";
			}
		}
		String[] teacherAddressArray =request.getParameterValues("teacherAddress");
		String teacherAddress ="";
		for (int i=0;i<2;i++)
		{
			if(i==1){
				teacherAddress =  teacherAddress+ teacherAddressArray[i]+"ÊÐ";
			}
			else{
				teacherAddress =  teacherAddress+ teacherAddressArray[i]+"Ê¡";
			}
		}
		
		TeacherVO teachervo =new TeacherVO();
		teachervo.setTeacherNum(teacherNum);
		teachervo.setTeacherName(teacherName);
		teachervo.setTeacherSex(teacherSex);
		teachervo.setTeacherBirth(teacherBirth);
		teachervo.setTeacherWorktime(teacherWorktime);
		teachervo.setTeacherAddress(teacherAddress);
		
		JDBC jdbc = new JDBC();
		try {
			jdbc.insertTeacher(teachervo);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
//		request.setAttribute("teachervo", teachervo);
		request.getRequestDispatcher("/servlet/ServletTeacherList").forward(request,response);
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
