package servletPackage;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import jdbcPackage.Jdbc;

import voPackage.UserVo;


public class voServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public voServlet() {
		super();
	}

	/**
	 * Destruction of the servlet. <br>
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
		
		String userName =request.getParameter("userName");
		String userPassword =request.getParameter("userPassword");
		//System.out.println(userName);
		
		UserVo userVo =new UserVo();
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		
		Jdbc jdbc=new Jdbc();
		jdbc.insertUser(userVo);
		
		request.setAttribute("userVo", userVo);
		request.getRequestDispatcher("/MyJsp.jsp").forward(request, response);
		//response.forward(/Myjsp.jsp);
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