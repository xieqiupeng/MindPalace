package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.dao.SCDAO;
import com.dao.StudentDAO;
import com.vo.StudentVO;

public class ServletUpdateStudent extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public ServletUpdateStudent() {
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

		String studentId =request.getParameter("studentId");
		String studentName =request.getParameter("studentName");
		String studentSex =request.getParameter("studentSex");
		String studentAge =request.getParameter("studentAge");
		String studentMajor =request.getParameter("studentMajor");
		String classId =request.getParameter("classId");
		
		String[] courseId=request.getParameterValues("courseId");
		System.out.println(courseId);
		
		StudentVO studentVo =new StudentVO();
		studentVo.setStudentId(studentId);
		studentVo.setStudentName(studentName);
		studentVo.setStudentSex(studentSex);
		studentVo.setStudentAge(studentAge);
		studentVo.setStudentMajor(studentMajor);
		studentVo.setClassId(classId);
		
		StudentDAO studentDao =new StudentDAO(); 
		studentDao.updateStudent(studentVo);
		
		SCDAO scDao =new SCDAO();
		scDao.insertSC(studentId,courseId);
		
		request.getRequestDispatcher("/servlet/ServletListStudent").forward(request, response);
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
