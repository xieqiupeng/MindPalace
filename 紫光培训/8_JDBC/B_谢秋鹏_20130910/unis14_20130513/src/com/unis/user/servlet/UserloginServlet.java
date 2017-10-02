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

public class UserloginServlet extends HttpServlet {

	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

	}

	
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//获取用户名和密码信息
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		UserDao userDao = new UserDao();
		UserVo userVo = new UserVo(); 
		//通过从前台获取的用户名信息来查询数据库中的内容，把数据保存到vo中
		userVo = userDao.judgeUserPassword(userName);
		//判断登录条件——当vo为空或者获取的密码和查询出来的密码不相应
		if (userVo==null||!userVo.getUserPassword().equals(userPassword)) {
			//当用户名或密码不正确的时候发送一条错误信息到登录页面
			request.setAttribute("error", "用户名或密码错误！");
			request.getRequestDispatcher("/userlogin.jsp").forward(request, response);
		}
		else
		{
			//判断用户名和密码正确
			//再次实例化UserDao,查询数据数据中用户的列表信息，发送到list页面
			userDao = new UserDao();
			ArrayList<UserVo> userList = null;
			userList = userDao.selectUserNotDeleteList();
			request.setAttribute("userList", userList);
			request.getRequestDispatcher("/userlist.jsp").forward(request, response);
		}
		
	}

}
