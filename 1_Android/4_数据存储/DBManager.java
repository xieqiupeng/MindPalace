package com.lvdora.aqi.db;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.os.Environment;
import android.util.Log;

public class DBManager {
	// IO缓存
	private final int BUFFER_SIZE = 10000;
	// 保存的数据库文件名
	public static final String DB_NAME = "city.db";
	public static final String PACKAGE_NAME = "com.lvdora.aqi";
	// 在手机里存放数据库的位置
	public static final String DB_PATH = "/data" + Environment.getDataDirectory().getAbsolutePath() + "/"
			+ PACKAGE_NAME;
	// 数据库文件路径
	public static final String DB_FILE = DB_PATH + "/" + DB_NAME;

	private SQLiteDatabase database;
	private Context context;

	public DBManager(Context context) {
		this.context = context;
	}

	public void openDatabase() {
		this.database = this.openDatabase(DB_FILE);
	}

	/**
	 * 导入数据库
	 * @param dbfile
	 * @return
	 */
	private SQLiteDatabase openDatabase(String dbfile) {
		try {
			//数据库文件不在路径中则从Assets里复制过去
			if (!(new File(dbfile).exists())) {
				InputStream is = this.context.getAssets().open("city.db");
				FileOutputStream fos = new FileOutputStream(dbfile);
				byte[] buffer = new byte[BUFFER_SIZE];
				int count = 0;
				while ((count = is.read(buffer)) > 0) {
					fos.write(buffer, 0, count);
				}
				fos.close();
				is.close();
			}
			SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(dbfile, null);
			return db;
		} catch (FileNotFoundException e) {
			Log.e("Database", "File not found");
			e.printStackTrace();
		} catch (IOException e) {
			Log.e("Database", "IO exception");
			e.printStackTrace();
		}
		return null;
	}

	/**
	 * 关闭数据库
	 */
	public void closeDatabase() {
		this.database.close();
	}
}
