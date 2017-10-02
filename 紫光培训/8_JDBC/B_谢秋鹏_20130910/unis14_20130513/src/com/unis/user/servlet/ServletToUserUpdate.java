package com.unis.user.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.user.dao.UserDao;
import com.unis.user.vo.UserVo;

public class ServletToUserUpdate extends HttpServlet {

	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		this.doPost(request, response);
	}

	
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//����id����ѯ����ǰ�û���������Ϣ,���͵��޸�ҳ��
		String userIdString = request.getParameter("userId");
		int userId = Integer.parseInt(userIdString);
		UserDao userDao = new UserDao();
		UserVo userVo = new UserVo(); 
		userVo = userDao.selectOneUserInfo(userId);
		request.setAttribute("userVo", userVo);
		request.getRequestDispatcher("/userupdate.jsp").forward(request, response);
	}

}
