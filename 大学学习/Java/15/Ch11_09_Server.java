import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;
public class Ch11_09_Server 
{
	private static int port = 9999;
	public static void main(String[] args) throws Exception
	{
		Selector selector = Selector.open();
		ServerSocketChannel channel = ServerSocketChannel.open();
		channel.configureBlocking(false);
		InetSocketAddress isa = new InetSocketAddress(port);
		channel.socket().bind(isa);
		channel.register(selector,SelectionKey.OP_ACCEPT);
		while(selector.select()>0)
		{
			Set readyKeys = selector.selectedKeys();
			Iterator readyItor = readyKeys.iterator();
			while(readyItor.hasNext())
			{
				SelectionKey key = (SelectionKey)readyItor.next();
				readyItor.remove();
				if(key.isAcceptable())
				{
					ServerSocketChannel keyChannel = (ServerSocketChannel)key.channel();
					ServerSocket serverSocket = keyChannel.socket();
					Socket socket = serverSocket.accept();
					PrintWriter out = new PrintWriter(socket.getOutputStream(),true);
					out.println("Hello, NIO");
					out.close();
				}
				else
				{
					System.err.println("Oops");
				}
			}
		}

	}

}
