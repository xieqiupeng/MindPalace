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
		//获取前台数据
		String userName = request.getParameter("userName");
		String userPassword = request.getParameter("userPassword");
		String userProvince = request.getParameter("userProvince");
		String userCity = request.getParameter("userCity");
		String userSex = request.getParameter("userSex");
		String userHobby[] = request.getParameterValues("userHobby");
		String userDescribe = request.getParameter("userDescribe");
		//把爱好的数组数据存放到一个字符串中
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
		//打印输出前台获取的数据
		System.out.println("用户名："+userName);
		System.out.println("密码："+userPassword);
		System.out.println("省份："+userProvince);
		System.out.println("城市："+userCity);
		System.out.println("性别："+userSex);
		System.out.println("爱好："+userHobbyString);
		System.out.println("描述："+userDescribe);
		//把数据保存到用户Vo中
		UserVo userVo = new UserVo();
		userVo.setUserName(userName);
		userVo.setUserPassword(userPassword);
		userVo.setUserProvince(userProvince);
		userVo.setUserCity(userCity);
		userVo.setUserSex(userSex);
		userVo.setUserHobby(userHobbyString);
		userVo.setUserDescribe(userDescribe);
		UserDao userDao = new UserDao();
		//通过用户的Vo来把数据插入到数据库中
		userDao.insertUser(userVo);
		//插入成功之后跳转到用户登录页面
		request.getRequestDispatcher("/userlogin.jsp").forward(request, response);
	}

}
