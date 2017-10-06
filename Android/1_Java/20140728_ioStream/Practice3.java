import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * @author 构图者
 * 
 */
public class Practice {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		//将数据写入某一载体
		DataOutputStream dos = new DataOutputStream(new FileOutputStream("record.txt"));
		//成绩
		double[] o_score = {80.5,66,89,76,77.5};
		//名次
		int[] o_index ={5,10,4,29,18};
		//科目名称
		String[] o_name = {"语文","数学","政治","历史","生物"};
		//记录数组的长度
		dos.writeByte(o_name.length);
	
		//写入数据
		for (int i=0;i<o_score.length;i++){
			dos.writeDouble(o_score[i]);
			dos.writeInt(o_index[i]);
			dos.writeUTF(o_name[i]);
		}
		//关闭
		dos.close();
		
		//将数据读入
		DataInputStream dis = new DataInputStream(new FileInputStream("record.txt"));
		double[] i_score;
		int[] i_index;
		String[] i_name;
		byte length;
		
		//读取数据
		length = dis.readByte();
		System.out.println(length);
		//初始化
		i_score = new double[length];
		i_index= new int[length];
		i_name= new String[length];
		
		//记录数据
		for(int i = 0;i<length;i++){
			i_score[i]  = dis.readDouble();
			i_index[i] = dis.readInt();
			i_name[i] = dis.readUTF();
		}
		
		//显示输出
		System.out.println("名称 成绩 名次");
		for(int i = 0;i<i_name.length;i++)
		{
			System.out.println(i_name[i]+" "+i_score[i]+" "+i_index[i]);
		}
		//关闭
		dis.close();
	}
}