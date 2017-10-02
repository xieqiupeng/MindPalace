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

public class ServletUserUpdate extends HttpServlet {

	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		//��ȡǰ̨Ҫ�޸ĵ�����
		String userIdString = request.getParameter("userId");
		int userId = Integer.parseInt(userIdString);
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		String userProvince = request.getParameter("userProvince");
		String userCity = request.getParameter("userCity");
		String userSex = request.getParameter("userSex");
		String userHobby[] = request.getParameterValues("userHobby");
		String userDescribe = request.getParameter("userDescribe");
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
		//�ѻ�ȡ�����ݱ��浽UserVo��
		UserVo userVo = new UserVo();
		userVo.setUserId(userId);
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		userVo.setUserProvince(userProvince);
		userVo.setUserCity(userCity);
		userVo.setUserSex(userSex);
		userVo.setUserHobby(userHobbyString);
		userVo.setUserDescribe(userDescribe);
		//�����޸ķ�����ͨ��vo���޸��û���Ϣ
		UserDao userDao = new UserDao();
		userDao.updateUser(userVo);
		
		//ɾ��֮���ѯ��δɾ���û��б��͵�listҳ��
		ArrayList<UserVo> userList = null;
		userDao = new UserDao();
		userList = userDao.selectUserNotDeleteList();
		request.setAttribute("userList", userList);
		request.getRequestDispatcher("/userlist.jsp").forward(request, response);
	}

}
