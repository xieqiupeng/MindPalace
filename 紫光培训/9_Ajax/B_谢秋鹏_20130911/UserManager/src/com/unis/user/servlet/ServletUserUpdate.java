package com.unis.user.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.user.dao.UserDao;
import com.unis.user.vo.UserVO;

public class ServletUserUpdate extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public ServletUserUpdate() {
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
		
		String userId =request.getParameter("userId");
		String userName =request.getParameter("userName");
		String userPassword =request.getParameter("userPassword");
		String province =request.getParameter("province");
		String city =request.getParameter("city");
		String userSex =request.getParameter("userSex");
		String[] hobbyArray =request.getParameterValues("hobby");
		String hobby="";
		for(int i=0;i<hobbyArray.length;i++)
		{
			if(i==hobbyArray.length-1)
			{
				hobby += hobbyArray[i];
			}
			else{
				hobby += hobbyArray[i]+"£¬";
			}
		}
		String describe =request.getParameter("describe");
		
		UserVO userVo=new UserVO();
		userVo.setUserId(userId);
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		userVo.setProvince(province);
		userVo.setCity(city);
		userVo.setUserSex(userSex);
		userVo.setHobby(hobby);
		userVo.setDescribe(describe);

		UserDao userDao =new UserDao();
		userDao.updateOneUser(userVo);

		request.getRequestDispatcher("/servlet/ServletUserList").forward(request, response);
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
