//package com.modernsky.istv;
//
//import java.io.IOException;
//import java.io.InputStream;
//import java.util.ArrayList;
//import java.util.List;
//
//import android.content.Intent;
//import android.content.res.AssetManager;
//import android.graphics.Bitmap;
//import android.graphics.BitmapFactory;
//import android.graphics.drawable.Drawable;
//import android.support.v4.view.ViewPager;
//import android.support.v4.view.ViewPager.OnPageChangeListener;
//import android.view.View;
//import android.view.View.OnClickListener;
//import android.view.ViewGroup.LayoutParams;
//import android.widget.Button;
//import android.widget.ImageView;
//import android.widget.ImageView.ScaleType;
//import android.widget.LinearLayout;
//
//import com.modernsky.istv.adapter.ViewPagerAdapter;
//import com.modernsky.istv.utils.PreferencesUtils;
//import com.modernsky.istv.utils.Utils;
//
///**
// * 
// * @author rendy
// * 
// *         首页界面
// * 
// */
//public class FirstStartActivity extends BaseActivity implements
//		OnClickListener, OnPageChangeListener {
//
//	private ViewPager vp;
//	private ViewPagerAdapter vpAdapter;
//	private List<View> views;
//	// 引导图片资源
//	private static final String[] pics = { "first_1.jpg", "first_2.jpg",
//			"first_3.jpg" };
//	// 底部小点图片
//	private ImageView[] dots;
//
//	// 记录当前选中位置
//	private int currentIndex;
//	private Button startButton;
//	private LinearLayout ll;
//
//	/** Called when the activity is first created. */
//
//	@Override
//	public void setContentView() {
//		if (PreferencesUtils.getFirstStartInfo(this)) {
//			startActivity(new Intent(this, LogoActivity.class));
//			overridePendingTransition(R.anim.enter, R.anim.exit);
//			finish();
//		}
//		setContentView(R.layout.activity_first);
//	}
//
//	@Override
//	public void findViewById() {
//		startButton = (Button) findViewById(R.id.button1);
//		startButton.setOnClickListener(this);
//		initViewPagers();
//	}
//
//	/**
//	 * 初始化巡展
//	 */
//	private void initViewPagers() {
//		views = new ArrayList<View>();
//		LinearLayout.LayoutParams mParams = new LinearLayout.LayoutParams(
//				LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
//
//		// 初始化引导图片列表
//		for (int i = 0; i < pics.length; i++) {
//			ImageView iv = new ImageView(this);
//			iv.setLayoutParams(mParams);
//			iv.setScaleType(ScaleType.CENTER_CROP);
//			iv.setImageBitmap(Utils.getImageFromAssetsFile(this, pics[i]));
//			views.add(iv);
//		}
//		vp = (ViewPager) findViewById(R.id.viewpager);
//		// 初始化Adapter
//		vpAdapter = new ViewPagerAdapter(views);
//		vp.setAdapter(vpAdapter);
//		// 绑定回调
//		vp.setOnPageChangeListener(this);
//
//		// 初始化底部小点
//		initDots();
//	}
//
//	private void initDots() {
//		ll = (LinearLayout) findViewById(R.id.ll);
//
//		dots = new ImageView[pics.length];
//
//		// 循环取得小点图片
//		for (int i = 0; i < pics.length; i++) {
//			dots[i] = (ImageView) ll.getChildAt(i);
//			dots[i].setEnabled(true);// 都设为灰色
//			dots[i].setOnClickListener(this);
//			dots[i].setTag(i);// 设置位置tag，方便取出与当前位置对应
//		}
//
//		currentIndex = 0;
//		dots[currentIndex].setEnabled(false);// 设置为白色，即选中状态
//	}
//
//	/**
//	 * 设置当前的引导页
//	 */
//	private void setCurView(int position) {
//		if (position < 0 || position >= pics.length) {
//			return;
//		}
//		setStartButtonVisible(position);
//
//		vp.setCurrentItem(position);
//	}
//
//	private void setStartButtonVisible(int position) {
//		if (position == pics.length - 1) {
//			ll.setVisibility(View.INVISIBLE);
//			startButton.setVisibility(View.VISIBLE);
//		} else {
//			startButton.setVisibility(View.GONE);
//			ll.setVisibility(View.VISIBLE);
//		}
//	}
//
//	/**
//	 * 这只当前引导小点的选中
//	 */
//	private void setCurDot(int positon) {
//		if (positon < 0 || positon > pics.length - 1 || currentIndex == positon) {
//			return;
//		}
//		setStartButtonVisible(positon);
//		dots[positon].setEnabled(false);
//		dots[currentIndex].setEnabled(true);
//		currentIndex = positon;
//	}
//
//	// 当滑动状态改变时调用
//	@Override
//	public void onPageScrollStateChanged(int arg0) {
//		// TODO Auto-generated method stub
//
//	}
//
//	// 当当前页面被滑动时调用
//	@Override
//	public void onPageScrolled(int arg0, float arg1, int arg2) {
//		// TODO Auto-generated method stub
//
//	}
//
//	// 当新的页面被选中时调用
//	@Override
//	public void onPageSelected(int arg0) {
//		setCurDot(arg0);
//	}
//
//	@Override
//	public void onClick(View v) {
//		if (v.getId() == R.id.button1) {
//			PreferencesUtils.setFirstStartInfo(this, true);
//			startActivity(new Intent(this, MainActivity.class));
//			overridePendingTransition(R.anim.enter, R.anim.exit);
//			finish();
//		} else {
//			int position = (Integer) v.getTag();
//			setCurView(position);
//			setCurDot(position);
//		}
//	}
//
//	// private Bitmap getImageFromAssetsFile(String fileName) {
//	// Bitmap image = null;
//	// AssetManager am = getResources().getAssets();
//	//
//	// try {
//	// InputStream is = am.open(fileName);
//	// image = BitmapFactory.decodeStream(is);
//	// is.close();
//	// } catch (IOException e) {
//	// e.printStackTrace();
//	// }
//	// return image;
//	// }
//
//	@Override
//	protected void onDestroy() {
//		// TODO Auto-generated method stub
//		super.onDestroy();
//		for (View view : views) {
//			releaseImageView((ImageView) view);
//		}
//	}
//
//	private void releaseImageView(ImageView imageView) {
//		Drawable d = imageView.getDrawable();
//		if (d != null)
//			d.setCallback(null);
//		imageView.setImageDrawable(null);
//		imageView.setBackgroundDrawable(null);
//	}
//
//}