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

public class ServletUserReturn extends HttpServlet {

	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		
		
	}

	
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//点击返回按钮跳转到userlist页面
		UserDao userDao = new UserDao();
		ArrayList<UserVo> userList = null;
		userDao = new UserDao();
		userList = userDao.selectUserNotDeleteList();
		request.setAttribute("userList", userList);
		request.getRequestDispatcher("/userlist.jsp").forward(request, response);
	}

}
