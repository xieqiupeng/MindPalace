import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.net.InetSocketAddress;
import java.io.IOException;
public class Ch11_08_SocketChannelReader 
{
	private Charset charset = Charset.forName("GB2312");
	private SocketChannel channel;
	public void getHTMLContent()
	{
		try
		{
			connect();
			sendRequest();
			readRequest();
		}
		catch(IOException e)
		{
			System.out.println(e.toString());
		}
		finally
		{
			if(channel != null)
			{
				try
				{
					channel.close();
				}
				catch(IOException e)
				{
					
				}
			}
		}
	}
	
	private void connect() throws IOException
	{
		InetSocketAddress socketAddress = new InetSocketAddress("www.sohu.com",80);
		channel = SocketChannel.open(socketAddress);
	}
	
	private void sendRequest() throws IOException
	{
		channel.write(charset.encode("GET " + "/document" + "\r\n\r\n"));
	}
	private void readRequest() throws IOException
	{
		ByteBuffer buffer = ByteBuffer.allocate(1024);
		while(channel.read(buffer)!=-1)
		{
			buffer.flip();
			System.out.println(charset.decode(buffer));
			buffer.clear();
		}
	}
	public static void main(String[] args) 
	{
		new Ch11_08_SocketChannelReader().getHTMLContent();
	}

}
