package com.unis.user.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.user.dao.UserDao;
import com.unis.user.vo.UserVo;

public class ServletDeleteUserList extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		
	}

	
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//根据id来删除一个用户
		String[] userIdString = request.getParameterValues("userId");
		UserDao userDao = new UserDao(); 
		userDao.deleteUserList(userIdString);
		
		//删除之后查询出未删除用户列表发送到list页面
		ArrayList<UserVo> userList = null;
		userDao = new UserDao();
		userList = userDao.selectUserNotDeleteList();
		request.setAttribute("userList", userList);
		request.getRequestDispatcher("/userlist.jsp").forward(request, response);
	}

}
