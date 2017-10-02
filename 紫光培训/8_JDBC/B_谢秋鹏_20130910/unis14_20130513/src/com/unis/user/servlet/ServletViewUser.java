package com.unis.user.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.user.dao.UserDao;
import com.unis.user.vo.UserVo;

public class ServletViewUser extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		this.doPost(request, response);
	}


	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//获取前台传过来的用户id
		String userIdString = request.getParameter("userId");
		int userId = Integer.parseInt(userIdString);
		UserDao userDao = new UserDao();
		UserVo userVo = new UserVo(); 
		//根据用户id来查询用户信息，把用户信息保存到用户vo中
		userVo = userDao.selectOneUserInfo(userId);
		//把vo发送到查看页面
		request.setAttribute("userVo", userVo);
		request.getRequestDispatcher("/userview.jsp").forward(request, response);
	}

}
