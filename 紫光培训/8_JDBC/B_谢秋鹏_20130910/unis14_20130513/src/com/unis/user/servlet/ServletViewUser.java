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
		//��ȡǰ̨���������û�id
		String userIdString = request.getParameter("userId");
		int userId = Integer.parseInt(userIdString);
		UserDao userDao = new UserDao();
		UserVo userVo = new UserVo(); 
		//�����û�id����ѯ�û���Ϣ�����û���Ϣ���浽�û�vo��
		userVo = userDao.selectOneUserInfo(userId);
		//��vo���͵��鿴ҳ��
		request.setAttribute("userVo", userVo);
		request.getRequestDispatcher("/userview.jsp").forward(request, response);
	}

}
