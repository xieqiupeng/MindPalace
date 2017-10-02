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
		//��ȡ�û�����������Ϣ
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		UserDao userDao = new UserDao();
		UserVo userVo = new UserVo(); 
		//ͨ����ǰ̨��ȡ���û�����Ϣ����ѯ���ݿ��е����ݣ������ݱ��浽vo��
		userVo = userDao.judgeUserPassword(userName);
		//�жϵ�¼����������voΪ�ջ��߻�ȡ������Ͳ�ѯ���������벻��Ӧ
		if (userVo==null||!userVo.getUserPassword().equals(userPassword)) {
			//���û��������벻��ȷ��ʱ����һ��������Ϣ����¼ҳ��
			request.setAttribute("error", "�û������������");
			request.getRequestDispatcher("/userlogin.jsp").forward(request, response);
		}
		else
		{
			//�ж��û�����������ȷ
			//�ٴ�ʵ����UserDao,��ѯ�����������û����б���Ϣ�����͵�listҳ��
			userDao = new UserDao();
			ArrayList<UserVo> userList = null;
			userList = userDao.selectUserNotDeleteList();
			request.setAttribute("userList", userList);
			request.getRequestDispatcher("/userlist.jsp").forward(request, response);
		}
		
	}

}
