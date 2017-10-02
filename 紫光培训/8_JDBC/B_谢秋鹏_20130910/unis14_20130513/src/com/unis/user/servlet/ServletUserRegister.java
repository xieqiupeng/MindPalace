package com.unis.user.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.unis.user.dao.UserDao;
import com.unis.user.vo.UserVo;

public class ServletUserRegister extends HttpServlet {

	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		
	}

	
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//��ȡǰ̨����
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		String userProvince = request.getParameter("userProvince");
		String userCity = request.getParameter("userCity");
		String userSex = request.getParameter("userSex");
		String userHobby[] = request.getParameterValues("userHobby");
		String userDescribe = request.getParameter("userDescribe");
		//�Ѱ��õ��������ݴ�ŵ�һ���ַ�����
		String userHobbyString="";
		for(int i=0;i<userHobby.length;i++)
		{
			if(i==0)
			{
				userHobbyString+=userHobby[i];
			}
			else
			{
				userHobbyString+=","+userHobby[i];
			}
		}
		//��ӡ���ǰ̨��ȡ������
		System.out.println("�û�����"+userName);
		System.out.println("���룺"+userPassword);
		System.out.println("ʡ�ݣ�"+userProvince);
		System.out.println("���У�"+userCity);
		System.out.println("�Ա�"+userSex);
		System.out.println("���ã�"+userHobbyString);
		System.out.println("������"+userDescribe);
		//�����ݱ��浽�û�Vo��
		UserVo userVo = new UserVo();
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		userVo.setUserProvince(userProvince);
		userVo.setUserCity(userCity);
		userVo.setUserSex(userSex);
		userVo.setUserHobby(userHobbyString);
		userVo.setUserDescribe(userDescribe);
		UserDao userDao = new UserDao();
		//ͨ���û���Vo�������ݲ��뵽���ݿ���
		userDao.insertUser(userVo);
		//����ɹ�֮����ת���û���¼ҳ��
		request.getRequestDispatcher("/userlogin.jsp").forward(request, response);
	}

}
