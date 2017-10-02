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
		//获取前台要修改的数据
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
		//把获取的数据保存到UserVo中
		UserVo userVo = new UserVo();
		userVo.setUserId(userId);
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		userVo.setUserProvince(userProvince);
		userVo.setUserCity(userCity);
		userVo.setUserSex(userSex);
		userVo.setUserHobby(userHobbyString);
		userVo.setUserDescribe(userDescribe);
		//调用修改方法，通过vo来修改用户信息
		UserDao userDao = new UserDao();
		userDao.updateUser(userVo);
		
		//删除之后查询出未删除用户列表发送到list页面
		ArrayList<UserVo> userList = null;
		userDao = new UserDao();
		userList = userDao.selectUserNotDeleteList();
		request.setAttribute("userList", userList);
		request.getRequestDispatcher("/userlist.jsp").forward(request, response);
	}

}
