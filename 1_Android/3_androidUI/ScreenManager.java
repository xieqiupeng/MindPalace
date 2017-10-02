package com.lvdora.aqi.util;

import java.util.Stack;
import android.app.Activity;

/**
 * 单例视图管理器 管理activity栈的获取和回收
 * 
 * @author Administrator
 * 
 */
public class ScreenManager {
	// 视图栈
	private static Stack<Activity> activityStack;
	// 唯一实例
	private static ScreenManager instance;

	/**
	 * 懒汉模式
	 */
	private ScreenManager() {
	}

	/**
	 * 获取 Singleton实例的方法
	 * 
	 * @return
	 */
	public static ScreenManager getScreenManager() {
		if (instance == null) {
			instance = new ScreenManager();
		}
		return instance;
	}

	/**
	 * 获取堆栈的栈顶activity
	 * 
	 * @return 栈顶activity
	 */
	private Activity currentActivity() {
		Activity activity = null;
		try {
			if (!activityStack.isEmpty()) {
				activity = activityStack.pop();
			}
			return activity;
		} catch (Exception ex) {
			System.out.println("ScreenManager:currentActivity---->" + ex.getMessage());
			return activity;
		} finally {
			activity = null;
		}
	}

	/**
	 * 将activity压入堆栈
	 * 
	 * @param activity
	 *            需要压入堆栈的activity
	 */
	public void pushActivity(Activity activity) {
		if (activityStack == null) {
			activityStack = new Stack<Activity>();
		}
		activityStack.push(activity);
	}

	/**
	 * 回收堆栈中所有Activity
	 */
	public void popAllActivity() {
		Activity activity = null;
		try {
			while (!activityStack.isEmpty()) {
				activity = currentActivity();
				popActivity(activity);
			}
		} finally {
			activity = null;
		}
	}

	/**
	 * 回收堆栈中指定的activity
	 * 
	 * @param activity
	 */
	public void popActivity(Activity activity) {
		if (activity != null) {
			activity.finish();
			activityStack.remove(activity);
			activity = null;
		}
	}
}