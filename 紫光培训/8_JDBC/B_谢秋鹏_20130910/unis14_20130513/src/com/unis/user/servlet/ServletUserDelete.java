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

public class ServletUserDelete extends HttpServlet {

	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		this.doPost(request, response);
		
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//����id��ɾ��һ���û�
		String userIdString = request.getParameter("userId");
		int userId = Integer.parseInt(userIdString);
		UserDao userDao = new UserDao(); 
		userDao.deleteOneUser(userId);
		
		//ɾ��֮���ѯ��δɾ���û��б��͵�listҳ��
		ArrayList<UserVo> userList = null;
		userDao = new UserDao();
		userList = userDao.selectUserNotDeleteList();
		request.setAttribute("userList", userList);
		request.getRequestDispatcher("/userlist.jsp").forward(request, response);
	}

}
