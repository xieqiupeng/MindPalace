import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * @author ��ͼ��
 * 
 */
public class Practice {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		//������д��ĳһ����
		DataOutputStream dos = new DataOutputStream(new FileOutputStream("record.txt"));
		//�ɼ�
		double[] o_score = {80.5,66,89,76,77.5};
		//����
		int[] o_index ={5,10,4,29,18};
		//��Ŀ����
		String[] o_name = {"����","��ѧ","����","��ʷ","����"};
		//��¼����ĳ���
		dos.writeByte(o_name.length);
	
		//д������
		for (int i=0;i<o_score.length;i++){
			dos.writeDouble(o_score[i]);
			dos.writeInt(o_index[i]);
			dos.writeUTF(o_name[i]);
		}
		//�ر�
		dos.close();
		
		//�����ݶ���
		DataInputStream dis = new DataInputStream(new FileInputStream("record.txt"));
		double[] i_score;
		int[] i_index;
		String[] i_name;
		byte length;
		
		//��ȡ����
		length = dis.readByte();
		System.out.println(length);
		//��ʼ��
		i_score = new double[length];
		i_index= new int[length];
		i_name= new String[length];
		
		//��¼����
		for(int i = 0;i<length;i++){
			i_score[i]  = dis.readDouble();
			i_index[i] = dis.readInt();
			i_name[i] = dis.readUTF();
		}
		
		//��ʾ���
		System.out.println("���� �ɼ� ����");
		for(int i = 0;i<i_name.length;i++)
		{
			System.out.println(i_name[i]+" "+i_score[i]+" "+i_index[i]);
		}
		//�ر�
		dis.close();
	}
}